#ifndef AIFACECONTROL_H
#define AIFACECONTROL_H
#include <QObject>
#include <QThread>
#include <QImage>
#include <QMutex>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "aifacekey.h"
#include "merror.h"
#include "arcsoft_fsdk_face_detection.h"
#include "arcsoft_fsdk_face_recognition.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>
#include <QVector>
#include <QFile>
#include <QDir>
#include "basicstruct.h"
#include "infodatabase.h"
#define WORKBUF_SIZE_FD (40*1024*1024)
#define EXITMSG 7070
class AiRecogntion;
class AiThread;
class AIFaceControl : public QThread
{
    Q_OBJECT
public:
    AIFaceControl();
    ~AIFaceControl();
/*
 * 创建新的特征文件
 */
    bool InsertFeature(QString ID, QString imgpath, int &Feature_size);
/*
 * 开启插入线程
 */
    void AIFace_start();

    void setBasicInfo(Basic_Info binfo);
/*
 * 关闭线程
 */
    void AifaceStop();
/*
 * 获取完整信息结构体
 */
    InFoStruct GetInFoStruct();

private:
    void run();
/*
 * arcface初始化引擎，获取特征，比对
 */
    void InitEngine(MHandle &FDEngine, MHandle &FREngine);//初始化引擎
    bool GetFeature(MHandle &FDEngine, MHandle &FREngine, QString imgpath, AFR_FSDK_FACEMODEL &Feature,cv::Mat &cropFace);
    Basic_Info binfo;
    InFoStruct Info;

signals:
    void sendAiFaceMsg(bool msg);
};
bool ConvertMatImage(cv::Mat &input, ASVLOFFSCREEN *output);//读取图片
bool readBmpFromBuffer(char* sOutBmp, uint8_t **imageData, int *pWidth, int *pHeight);
#endif
