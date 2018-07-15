#ifndef AITHREAD_H
#define AITHREAD_H

#include <QObject>
#include <QThread>
#include <QRunnable>
#include <QThread>
#include <QThreadPool>
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
class AiThread : public QThread
{
    Q_OBJECT
public:
    AiThread();
    ~AiThread();
    void AiThreadStart();
    void Insertsim(QString ID,float sim);
    IDSIMstruct getMaxIDS();
    QMutex fileMutex;
    void AiThreadStop();
private slots:
    void handlerunaMsg();
signals:
    void sendAiThreadMsg(bool);
private:
    InFoDatabase *infodb;
    QVector<IDFStruct> Featurefiles;
    QVector<IDSIMstruct> idsim;
    QMutex Mutex;
    bool ConvertMatImage(cv::Mat &input, ASVLOFFSCREEN *output);//读取图片
    bool readBmpFromBuffer(char* sOutBmp, uint8_t **imageData, int *pWidth, int *pHeight);
    bool GetFeature();
    void run();
};

class ComputeSim : public QObject , public QRunnable
{
    Q_OBJECT
public:
    ComputeSim(AiThread* aithread,IDFStruct idf);
    ~ComputeSim();
signals:
    void sendrunnaMsg();
protected:
    void run();
private:
    AiThread *aithread;
    IDFStruct idf;
};
#endif // AITHREAD_H
