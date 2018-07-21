#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <QDir>
#include <QThread>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "basicstruct.h"
#include "cmeracontrol.h"
#include "inputinfo.h"
#include "aifacecontrol.h"
#include "aithread.h"
#include "infodatabase.h"
#include "loadingdialog.h"
#include "infomanager.h"
#include "attendmanager.h"
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    LoadingDialog *waiting;

/*
 * 检查数据目录完整
 */
    void CheckDir();


/*
 * 初始化各个模块
 */
    void InitObject();
    void InitProcess();
    void InitSlots();

/*
 * 摄像头模块
 */
    CmeraControl *CameraControl;
    QGraphicsScene *cameraScene;
    static int CAMERA_WIDTH;
    static int CAMERA_HEIGHT;
/*
 * AIFace模块
 */
    AIFaceControl *AiFaceControl;
    AiThread *aithread;

/*
 * 录入信息
 */
    InputInfo *InputWidget;

/*
 * 数据库
 */
    InFoDatabase *infodb;
/*
 * 信息管理
 */
    InFoManager *infomanager;

/*
 * 签到管理
 */
    AttendManager *attenedmanager;

/*
 * 重写鼠标事件
 */
private:
    QPoint last;//智能指针
protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


/*
 * 槽函数
 */
private slots:
    void handleCamera(QImage cameraFrame);
    void handleInputMSG(bool result);
    void handleAIFaceMSG(bool result);
    void handleAIThreadMSG(bool result);

    //按钮槽
    void onBtnexitClicked();
    void onInputClicked();
    void onAttenedClicked();
    void onInfoBtnClicked();
    void onAtteninfoClicked();
};


#endif // MAINWIDGET_H
