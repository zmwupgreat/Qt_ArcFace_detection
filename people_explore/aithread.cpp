#include "aithread.h"
#include <QDebug>
#include <QMessageBox>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
AiThread::AiThread()
{
    infodb = InFoDatabase::Get_InFoDatabase();
}
AiThread::~AiThread()
{
    quit();
    wait();
}
void AiThread::AiThreadStop()
{
    this->exit(0);
}
/*
 * 启动线程
 */
void AiThread::AiThreadStart()
{
    if(!this->isRunning())
        start();
}
/*
 * 处理多线程槽
 */
void AiThread::handlerunaMsg()
{

}

/*
 * 图片处理
 */
bool AiThread::ConvertMatImage(cv::Mat &input, ASVLOFFSCREEN *output)
{
    std::vector<uchar> buffer;
    cv::imencode(".bmp", input, buffer);
    int len = buffer.size();
    char *imgBuffer = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
        imgBuffer[i] = buffer[i];

    bool isConvert = readBmpFromBuffer(imgBuffer,
        (uint8_t**)&(output->ppu8Plane[0]),
        &(output->i32Width),
        &(output->i32Height));

    free(imgBuffer);
    return isConvert;
}
/*
 * 读取图片
 */
bool AiThread::readBmpFromBuffer(char *sOutBmp, uint8_t **imageData, int *pWidth, int *pHeight)
{
    const char* pBuffer = sOutBmp;
    BITMAPINFOHEADER head;
    memcpy(&head, pBuffer + sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));
    *pWidth = head.biWidth;
    *pHeight = head.biHeight;
    int biBitCount = head.biBitCount;
    if (24 == biBitCount)
    {
        int lineByte = ((*pWidth) * biBitCount / 8 + 3) / 4 * 4;
        *imageData = (uint8_t *)malloc(lineByte * (*pHeight));
        for (int i = 0; i < *pHeight; i++)
        {
            memcpy(*imageData + i * (*pWidth) * 3, pBuffer + (*pHeight - 1 - i) * lineByte + 54, (*pWidth) * 3);
        }
    }
    else if (32 == biBitCount)
    {
        *imageData = (uint8_t *)malloc((*pWidth) * (*pHeight) * 3);
        for (int i = 0; i < *pHeight; i++)
        {
            for (int j = 0; j < *pWidth; j++)
            {
                memcpy((*imageData) + i * (*pWidth) * 3 + j * 3, pBuffer + (((*pHeight) - 1) - i) * (*pWidth) * 4 + j * 4 + 54, 3);
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

/*
 * 提取图像特征
 */
bool AiThread::GetFeature()
{
    MHandle FDEngine;
    MHandle FREngine;

    MInt32 nScale = 16;
    MInt32 nMaxFace = 1;
    MByte *fd_pWorkMem = nullptr;
    FDEngine = nullptr;
    fd_pWorkMem = (MByte *)malloc(WORKBUF_SIZE_FD);
    if (fd_pWorkMem == nullptr)
    {
        return false;
    }
    int fdret = AFD_FSDK_InitialFaceEngine((MPChar)APPID, (MPChar)FD_SDKKEY, fd_pWorkMem, WORKBUF_SIZE_FD, &FDEngine, AFD_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);

    MByte *fr_pWorkMem = nullptr;
    FREngine = nullptr;
    fr_pWorkMem = (MByte *)malloc(WORKBUF_SIZE_FD);
    if (fr_pWorkMem == nullptr)
    {
        free(fd_pWorkMem);
        return false;
    }
    int fr_ret = AFR_FSDK_InitialEngine((MPChar)APPID, (MPChar)FR_SDKKEY, fr_pWorkMem, WORKBUF_SIZE_FD, &FREngine);
    if (fdret != MOK || fr_ret != MOK)
    {
        std::cout << "初始化失败:" << "检测代码：" << fdret << "识别代码：" << fr_ret << std::endl;
        free(fr_pWorkMem);
        free(fd_pWorkMem);
        return false;
    }
    std::cout << "初始化成功" << std::endl;


    AFR_FSDK_FACEMODEL Feature = { 0 };
    cv::Mat cropFace;
    cv::Mat img = cv::imread("./JITtemp.bmp", 1);
    ASVLOFFSCREEN  Image = { 0 };
     Image.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
     Image.ppu8Plane[0] = nullptr;
     ConvertMatImage(img, &Image);
     Image.pi32Pitch[0] =  Image.i32Width * 3;

    /****** 检测人脸   ******/
    MRESULT  Ret = MERR_UNKNOWN;
    LPAFD_FSDK_FACERES  face  = nullptr;
    Ret = AFD_FSDK_StillImageFaceDetection(FDEngine, &Image, &face);
    if ( Ret != MOK || face->nFace < 1)
    {
        qDebug()<< "检测不到人脸";
        fprintf(stderr, "fail to Extract 1st FD Feature, error code: %d\r\n", Ret);
        free( Image.ppu8Plane[0]);
        Image.ppu8Plane[0] = NULL;
        img.release();
        if(Feature.pbFeature)
        {
            free(Feature.pbFeature);
            Feature.pbFeature = NULL;
        }
        AFD_FSDK_UninitialFaceEngine(FDEngine);
        AFR_FSDK_UninitialEngine(FREngine);
        return false;
    }
    /****** 提取特征   ******/
    AFR_FSDK_FACEINPUT faceResult;
    faceResult.lOrient = face->lfaceOrient[0];
    faceResult.rcFace.left = face->rcFace[0].left;
    faceResult.rcFace.top = face->rcFace[0].top;
    faceResult.rcFace.right = face->rcFace[0].right;
    faceResult.rcFace.bottom = face->rcFace[0].bottom;
    AFR_FSDK_FACEMODEL LocalFaceModels = { 0 };
    MRESULT nRet = AFR_FSDK_ExtractFRFeature(FREngine, &Image, &faceResult, &LocalFaceModels);

    if (nRet != MOK)
    {
        qDebug()<< "提取特征失败";
        fprintf(stderr, "fail to Extract 1st FR Feature, error code: %d\r\n", nRet);
        free(Image.ppu8Plane[0]);
        Image.ppu8Plane[0] = NULL;
        img.release();
        if(Feature.pbFeature)
        {
            free(Feature.pbFeature);
            Feature.pbFeature = NULL;
        }
        free(fr_pWorkMem);
        free(fd_pWorkMem);
        AFD_FSDK_UninitialFaceEngine(FDEngine);
        AFR_FSDK_UninitialEngine(FREngine);
        return false;
    }
    Feature.lFeatureSize = LocalFaceModels.lFeatureSize;
    Feature.pbFeature = (MByte*)malloc(Feature.lFeatureSize);
    memcpy(Feature.pbFeature, LocalFaceModels.pbFeature, Feature.lFeatureSize);
    FILE *outfile;
    outfile = fopen("./temp.dat","wb");
    fwrite(Feature.pbFeature,Feature.lFeatureSize,1,outfile);
    fclose(outfile);
    //切割有脸的部分
    int x,y,width,height;
    width = face->rcFace->right - face->rcFace->left;
    height = face->rcFace->bottom - face->rcFace->top;
    x = face->rcFace->left -(width/6);
    y = face->rcFace->top - (height/6);
    width = (width * 4) / 3;
    height = (height * 4) / 3;
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if ((x + width)>img.cols)
        width = img.cols - x;
    if ((y + height)>img.rows)
        height = img.rows - y;
    cv::Rect Rect(x,y, width, height);
    cropFace = img(Rect).clone();
    cropFace = cv::imwrite("./croptemp.bmp",cropFace);
    free(Image.ppu8Plane[0]);
    Image.ppu8Plane[0] = NULL;
    img.release();
    cropFace.release();
    if(Feature.pbFeature)
    {
        free(Feature.pbFeature);
        Feature.pbFeature = NULL;
    }

    AFD_FSDK_UninitialFaceEngine(FDEngine);
    AFR_FSDK_UninitialEngine(FREngine);
    free(fr_pWorkMem);
    free(fd_pWorkMem);
    return true;
}
/*
 * 插入相似度列表
 */
void AiThread::Insertsim(QString ID,float sim)
{
    IDSIMstruct tempstruct;
    tempstruct.ID = ID;
    tempstruct.sim = sim;
    Mutex.lock();
    idsim.push_back(tempstruct);
    Mutex.unlock();
}
/*
 * 获取最相似信息
 */
IDSIMstruct AiThread::getMaxIDS()
{
    IDSIMstruct tempidsim;
    tempidsim.ID = "";
    tempidsim.sim = 0;
    for(int i = 0; i < idsim.size();i++)
    {
        if(idsim.at(i).sim > tempidsim.sim)
        {
            tempidsim.ID = idsim.at(i).ID;
            tempidsim.sim = idsim.at(i).sim;
        }
    }
    return tempidsim;
}

/*
 * 线程函数
 */
void AiThread::run()
{
    Featurefiles = infodb->IDFSelect();
    if(Featurefiles.size() < 1)
    {
        QMessageBox::warning(NULL,"提示","数据库中没有数据，请插入数据","确定");
        return;
    }
    bool Ret = GetFeature();
    idsim.clear();
    if(!Ret)
    {
        emit sendAiThreadMsg(false);
        return;
    }
    QThreadPool threadpool;
    threadpool.setMaxThreadCount(8);
    for(int i = 0; i < Featurefiles.size();i++)
    {
        ComputeSim *computesim = new ComputeSim(this,Featurefiles.at(i));
        if(!computesim->autoDelete())
            computesim->setAutoDelete(true);
        qDebug()<<"开启线程:"<<Featurefiles.at(i).Feature;
        threadpool.start(computesim);
    }
    threadpool.waitForDone();
    qDebug()<<"Finish!";
    emit sendAiThreadMsg(true);
    return;
}
/*
 * 比对线程
 */
ComputeSim::ComputeSim(AiThread* aithread,IDFStruct idf)
{
    this->aithread = aithread;
    this->idf = idf;
}
ComputeSim::~ComputeSim()
{

}
/*
 * 比对线程处理函数
 */
void ComputeSim::run()
{
    MHandle FREngine;
    MByte *fr_pWorkMem = nullptr;
    FREngine = nullptr;
    fr_pWorkMem = (MByte *)malloc(WORKBUF_SIZE_FD);
    if (fr_pWorkMem == nullptr)
    {
        return;
    }
    int fr_ret = AFR_FSDK_InitialEngine((MPChar)APPID, (MPChar)FR_SDKKEY, fr_pWorkMem, WORKBUF_SIZE_FD, &FREngine);
    if ( fr_ret != MOK)
    {
        std::cout << "初始化失败:" << "识别代码：" << fr_ret << std::endl;
        return;
    }
    std::cout << "初始化成功" << std::endl;

    AFR_FSDK_FACEMODEL Feature1 = { 0 };
    AFR_FSDK_FACEMODEL Feature2 = { 0 };

    FILE *file1;
    file1 = fopen("./temp.dat","rb");
    Feature1.pbFeature = (MByte*)malloc(22020);
    fread(Feature1.pbFeature,22020,1,file1);
    Feature1.lFeatureSize = 22020;
    fclose(file1);

    FILE *file2;
    file2 = fopen(idf.Feature.toStdString().c_str(),"rb");
    Feature2.pbFeature = (MByte*)malloc(idf.Feature_size);
    fread(Feature2.pbFeature,idf.Feature_size,1,file2);
    Feature2.lFeatureSize = idf.Feature_size;
    fclose(file2);

    float sim = 0.0;
    MRESULT nRet = AFR_FSDK_FacePairMatching(FREngine, &Feature1, &Feature2, &sim);
    if(nRet != MOK)
    {
        qDebug()<<"失败";
        if(Feature1.pbFeature)
        {
            free(Feature1.pbFeature);
            Feature1.pbFeature = NULL;
        }
        if(Feature2.pbFeature)
        {
            free(Feature2.pbFeature);
            Feature2.pbFeature = NULL;
        }

        AFR_FSDK_UninitialEngine(FREngine);
        free(fr_pWorkMem);
        return;
    }
    if(Feature1.pbFeature)
    {
        free(Feature1.pbFeature);
        Feature1.pbFeature = NULL;
    }
    if(Feature2.pbFeature)
    {
        free(Feature2.pbFeature);
        Feature2.pbFeature = NULL;
    }

    AFR_FSDK_UninitialEngine(FREngine);
    free(fr_pWorkMem);
     qDebug()<<idf.Feature<<"相似度："<<sim;
     aithread->Insertsim(idf.Num,sim);

}
