#include "aifacecontrol.h"
#include <QDebug>
#include <string>
#define FEATURE_PATH "./data/Feature/"
#define IMAGE_PATH "./data/Image/"

#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif

AIFaceControl::AIFaceControl()
{

}

AIFaceControl::~AIFaceControl()
{
    quit();
    wait();
}
void AIFaceControl::AifaceStop()
{
    this->exit(0);
}
/*
 * 初始化引擎
 */
void AIFaceControl::InitEngine(MHandle &FDEngine, MHandle &FREngine)
{
    MInt32 nScale = 16;
    MInt32 nMaxFace = 1;
    MByte *fd_pWorkMem = nullptr;
    FDEngine = nullptr;
    fd_pWorkMem = (MByte *)malloc(WORKBUF_SIZE_FD);
    if (fd_pWorkMem == nullptr)
    {
        return;
    }
    int fdret = AFD_FSDK_InitialFaceEngine((MPChar)APPID, (MPChar)FD_SDKKEY, fd_pWorkMem, WORKBUF_SIZE_FD, &FDEngine, AFD_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);

    MByte *fr_pWorkMem = nullptr;
    FREngine = nullptr;
    fr_pWorkMem = (MByte *)malloc(WORKBUF_SIZE_FD);
    if (fr_pWorkMem == nullptr)
    {
        return;
    }
    int fr_ret = AFR_FSDK_InitialEngine((MPChar)APPID, (MPChar)FR_SDKKEY, fr_pWorkMem, WORKBUF_SIZE_FD, &FREngine);
    if (fdret != MOK || fr_ret != MOK)
    {
        std::cout << "初始化失败:" << "检测代码：" << fdret << "识别代码：" << fr_ret << std::endl;
        return;
    }
    std::cout << "初始化成功" << std::endl;
    return;
}


/*
 * 图片预操作
 */
bool readBmpFromBuffer(char* sOutBmp, uint8_t **imageData, int *pWidth, int *pHeight)
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
bool ConvertMatImage(cv::Mat &input, ASVLOFFSCREEN *output)
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
 * arcface获取特征值
 */
bool AIFaceControl::GetFeature(MHandle &FDEngine, MHandle &FREngine, QString imgpath, AFR_FSDK_FACEMODEL &Feature,cv::Mat &cropFace)
{
        cv::Mat img = cv::imread(imgpath.toStdString(), 1);
        ASVLOFFSCREEN  Image = { 0 };
         Image.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
         Image.ppu8Plane[0] = nullptr;
        ConvertMatImage(img, &Image);
         Image.pi32Pitch[0] =  Image.i32Width * 3;

        /****** 检测人脸   ******/
        MRESULT  Ret = MERR_UNKNOWN;
        LPAFD_FSDK_FACERES  face  = nullptr;
         Ret = AFD_FSDK_StillImageFaceDetection(FDEngine, & Image, &face );
        if ( Ret != MOK || face->nFace < 1)
        {
            qDebug()<< "检测不到人脸";
            free( Image.ppu8Plane[0]);
            img.release();
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
            img.release();
            return false;
        }
        Feature.lFeatureSize = LocalFaceModels.lFeatureSize;
        Feature.pbFeature = (MByte*)malloc(Feature.lFeatureSize);
        memcpy(Feature.pbFeature, LocalFaceModels.pbFeature, Feature.lFeatureSize);
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
        free(Image.ppu8Plane[0]);
        img.release();
        return true;
}



/*
 * 创建新的特征文件
 */
bool AIFaceControl::InsertFeature(QString ID, QString imgpath, int &Feature_size)
{
    MHandle FDEngine;
    MHandle FREngine;
    cv::Mat cropFace;

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
    if(Feature.pbFeature)
    {
        free(Feature.pbFeature);
        Feature.pbFeature = NULL;
    }
    bool Ret = GetFeature(FDEngine,FREngine,imgpath,Feature,cropFace);
    if(!Ret)
    {
        if(Feature.pbFeature)
        {
            free(Feature.pbFeature);
            Feature.pbFeature = NULL;
        }
        AFD_FSDK_UninitialFaceEngine(FDEngine);
        AFR_FSDK_UninitialEngine(FREngine);
        free(fr_pWorkMem);
        free(fd_pWorkMem);
        return false;
    }
    //特征值长度
    Feature_size = Feature.lFeatureSize;
    /*
    unsigned char *buffer;
    buffer = (unsigned char*)malloc(Feature.lFeatureSize);
    memcpy(buffer,Feature.pbFeature,Feature.lFeatureSize);
    */
    FILE *outfile;
    QString filename = FEATURE_PATH + ID + ".dat";
    std::string str = filename.toStdString();
    outfile = fopen(str.c_str(),"wb");
    if(outfile == NULL)
    {
        if(Feature.pbFeature)
        {
            free(Feature.pbFeature);
            Feature.pbFeature = NULL;
        }
        AFD_FSDK_UninitialFaceEngine(FDEngine);
        AFR_FSDK_UninitialEngine(FREngine);
        free(fr_pWorkMem);
        free(fd_pWorkMem);
        return false;
    }
    fwrite(Feature.pbFeature,Feature.lFeatureSize,1,outfile);
    if(Feature.pbFeature)
    {
        free(Feature.pbFeature);
        Feature.pbFeature = NULL;
    }
    AFD_FSDK_UninitialFaceEngine(FDEngine);
    AFR_FSDK_UninitialEngine(FREngine);
    free(fr_pWorkMem);
    free(fd_pWorkMem);
    QString Imagename = IMAGE_PATH + ID + ".bmp";
    cv::imwrite(Imagename.toStdString(),cropFace);
    return true;
}

/*
 *传递个人信息
 */
void AIFaceControl::setBasicInfo(Basic_Info binfo)
{
    this->binfo.ID = binfo.ID;
    this->binfo.Name = binfo.Name;
    this->binfo.Age = binfo.Age;
    this->binfo.Gender = binfo.Gender;
    this->binfo.Apart = binfo.Apart;
}
/*
 * 开启线程
 */
void AIFaceControl::AIFace_start()
{
    if(!this->isRunning())
        start();
}
/*
 * 线程函数
 */
void AIFaceControl::run()
{
    QString imgpath = "./temp.bmp";
    int Feature_size;
    bool msg = InsertFeature(binfo.ID,imgpath,Feature_size);
    Info.Num = binfo.ID;
    Info.Name = binfo.Name;
    Info.Age = binfo.Age;
    Info.Apart = binfo.Apart;
    Info.Gender = binfo.Gender;
    Info.Feature = FEATURE_PATH + binfo.ID + ".dat";
    Info.Feature_size = Feature_size;
    Info.Image = IMAGE_PATH + binfo.ID + ".bmp";
    emit sendAiFaceMsg(msg);   
}
/*
 *获取完整信息
 */
InFoStruct AIFaceControl::GetInFoStruct()
{
    return Info;
}
