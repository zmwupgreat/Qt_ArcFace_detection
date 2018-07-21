#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif

int MainWidget::CAMERA_WIDTH = 640;
int MainWidget::CAMERA_HEIGHT = 480;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    CheckDir();
    InitObject();
    InitProcess();
    InitSlots();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}


/*
 * 检查数据目录是否完整
 */
void MainWidget::CheckDir()
{
    QDir dataDir;
    QDir databaseDir;
    QDir FeatureDir;
    QDir ImageDir;
    QDir JITimageDir;
    QString dataPath = "data/";
    QString dbPath = "data/database/";
    QString FeaturePath = "data/Feature/";
    QString ImagePath = "data/Image/";
    QString cropPath = "data/JITimage/";

    if(!dataDir.exists(dataPath))
        dataDir.mkpath(dataPath);
    if(!databaseDir.exists(dbPath))
        databaseDir.mkpath(dbPath);
    if(!FeatureDir.exists(FeaturePath))
        FeatureDir.mkpath(FeaturePath);
    if(!ImageDir.exists(ImagePath))
        ImageDir.mkpath(ImagePath);
    if(!JITimageDir.exists(cropPath));
        JITimageDir.mkpath(cropPath);
}



/*
 * 初始化各个模块
 */
void MainWidget::InitObject()
{
    cameraScene = new QGraphicsScene(2,2,CAMERA_WIDTH,CAMERA_HEIGHT,ui->CameragraphicsView);
    ui->CameragraphicsView->setScene(cameraScene);
    CameraControl = new CmeraControl(CAMERA_WIDTH,CAMERA_HEIGHT);
    connect(CameraControl,SIGNAL(sendFrame(QImage)),this,SLOT(handleCamera(QImage)));

    InputWidget = new InputInfo();

    AiFaceControl = new AIFaceControl();
    connect(AiFaceControl,SIGNAL(sendAiFaceMsg(bool)),this,SLOT(handleAIFaceMSG(bool)));

    aithread = new AiThread();
    connect(aithread,SIGNAL(sendAiThreadMsg(bool)),this,SLOT(handleAIThreadMSG(bool)));

    waiting = new LoadingDialog();

    infomanager = new InFoManager();
    attenedmanager = new AttendManager();

    infodb = InFoDatabase::Get_InFoDatabase();
}


/*
 * 初始化线程
 */
void MainWidget::InitProcess()
{
    if(!CameraControl->startCamera())
    {
        qDebug()<<"camera wrong!";
        exit(0);
    }
}
/*
 * 初始化槽
 */
void MainWidget::InitSlots()
{
    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(onBtnexitClicked()));
    connect(ui->InputButton,SIGNAL(clicked(bool)),this,SLOT(onInputClicked()));
    connect(ui->OneKeyButton,SIGNAL(clicked(bool)),this,SLOT(onAttenedClicked()));
    connect(ui->InfoButton,SIGNAL(clicked(bool)),this,SLOT(onInfoBtnClicked()));
    connect(ui->AttendButton,SIGNAL(clicked(bool)),this,SLOT(onAtteninfoClicked()));
}

/*
 * 摄像头模块
 */
void MainWidget::handleCamera(QImage cameraFrame)
{
    cameraScene->clear();
    cameraScene->addPixmap(QPixmap::fromImage(cameraFrame));
    ui->CameragraphicsView->show();

}
/*
 *录入界面
 */
void MainWidget::onInputClicked()
{
    connect(InputWidget,SIGNAL(sendInputInfoMsg(bool)),this,SLOT(handleInputMSG(bool)));
    cv::Mat cropFrame = CameraControl->captureCamera();
    cv::imwrite("./temp.bmp",cropFrame);
    InputWidget->CleanEdit();
    QImage img;
    img.load("./temp.bmp");
    img = img.scaled(161,211,Qt::KeepAspectRatio);
    InputWidget->setPic(img);
    InputWidget->show();
}
/*
 * 获取录入信息
 */
void MainWidget::handleInputMSG(bool result)
{
    if(!result)
        return;
    AiFaceControl->setBasicInfo(InputWidget->GetBasicInfo());
    AiFaceControl->AIFace_start();
}
/*
 * AIFace
 */
void MainWidget::handleAIFaceMSG(bool result)
{
    QFile file("./temp.bmp");
    if(file.exists())
        file.remove();
    if(!result)
    {
        QMessageBox::warning(this,"错误","AIFace检测不到人脸","确定",NULL);
        return;
    }
    InFoStruct info = AiFaceControl->GetInFoStruct();
    bool Ret = infodb->InsertInfo(info);
    if(!Ret)
    {
        QMessageBox::warning(this,"错误","插入数据库失败","确定",NULL);
        return;
    }

    QImage infoimg;
    infoimg.load(info.Image);
    infoimg = infoimg.scaled(101,141,Qt::KeepAspectRatio);
    ui->Infopic->setPixmap(QPixmap::fromImage(infoimg));
    ui->infoIDlabel->setText(info.Num);
    ui->infoNamelabel->setText(info.Name);
    ui->infoAgelabel->setText(info.Age);
    ui->infoGenderlabel->setText(info.Gender);
    ui->infoApartlabel->setText(info.Apart);
}


/*
 * 一键签到
 */
void MainWidget::onAttenedClicked()
{
    cv::Mat cropFrame = CameraControl->captureCamera();
    cv::imwrite("./JITtemp.bmp",cropFrame);
    aithread->AiThreadStart();
    waiting->show();
}

void MainWidget::handleAIThreadMSG(bool result)
{
    waiting->reject();
    if(!result)
    {
        QMessageBox::warning(this,"错误","人脸比对失败","确定",NULL);
        return;
    }
    IDSIMstruct idsim =  aithread->getMaxIDS();
    if(idsim.sim < 0.3)
    {
         QMessageBox::warning(this,"提示","该员工不在数据库中，请导入信息","确定",NULL);
         return;
    }
    QString condition = QString("and Num='%1'").arg(idsim.ID);
    InFoStruct infostruct = infodb->InfoSelect(condition);
    QImage jitimg;
    jitimg.load("./croptemp.bmp");
    jitimg = jitimg.scaled(171,221,Qt::KeepAspectRatio);
    ui->JITpiclabel->setPixmap(QPixmap::fromImage(jitimg));
    QString SIM = QString::number(idsim.sim*100, 'f', 2);
    QString sim_Result = QString("%1\%").arg(SIM);
    ui->simlabel->setText(sim_Result);
    QImage infopic1,infopic2;
    infopic1.load(infostruct.Image);
    infopic1 = infopic1.scaled(171,221,Qt::KeepAspectRatio);
    ui->Infopiclabel->setPixmap(QPixmap::fromImage(infopic1));
    infopic2.load(infostruct.Image);
    infopic2 = infopic2.scaled(131,171,Qt::KeepAspectRatio);
    ui->Infopic->setPixmap(QPixmap::fromImage(infopic2));
    ui->infoIDlabel->setText(infostruct.Num);
    ui->infoNamelabel->setText(infostruct.Name);
    ui->infoGenderlabel->setText(infostruct.Gender);
    ui->infoAgelabel->setText(infostruct.Age);
    ui->infoApartlabel->setText(infostruct.Apart);
    QFile::remove("./temp.dat");

    Attenedinfo attenedinfo;
    QDateTime time = QDateTime::currentDateTime();
    attenedinfo.Time = time.toString("yyyy/MM/dd hh:mm:ss");
    attenedinfo.ID = infostruct.Num;
    attenedinfo.Name = infostruct.Name;
    attenedinfo.Age = infostruct.Age;
    attenedinfo.Apart = infostruct.Apart;
    attenedinfo.Gender = infostruct.Gender;
    QString cropimage = "./data/JITimage/"+time.toString("yyyy_MM_dd")+time.toString("hhmmss")+".bmp";
    QFile::copy("./croptemp.bmp",cropimage);
    attenedinfo.image =cropimage;

    bool Ret = infodb->InsertAttenedInfo(attenedinfo);
    if(!Ret)
    {
        QMessageBox::warning(this,"错误","插入数据库失败","确定",NULL);
        return;
    }
}
/*
 * 信息管理
 */
void MainWidget::onInfoBtnClicked()
{
    infomanager->InitTable();
    infomanager->show();
}
/*
 * 签到管理
 */
void MainWidget::onAtteninfoClicked()
{
    attenedmanager->InitTable();
    attenedmanager->show();
}
/*
 * 退出程序
 */
void MainWidget::onBtnexitClicked()
{
    this->close();
    AiFaceControl->AifaceStop();
    aithread->AiThreadStop();
    CameraControl->stopCamera();
    qApp->exit(0);
}


/*
 * 重写鼠标事件
 */
void MainWidget::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void MainWidget::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
MainWidget::~MainWidget()
{
    delete ui;
    delete CameraControl;
    delete cameraScene;
    delete InputWidget;
    delete AiFaceControl;
    delete aithread;
    delete infomanager;
}

