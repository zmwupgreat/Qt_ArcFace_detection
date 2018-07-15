#ifndef CMERACONTROL_H
#define CMERACONTROL_H

#include <QThread>
#include <QImage>
#include <QMutex>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

class CmeraControl : public QThread
{
    Q_OBJECT
public:
    CmeraControl(int width, int height);
    ~CmeraControl();
    bool startCamera();
    void stopCamera();
    cv::Mat captureCamera();

/*
 * 向主界面发送处理后的视频图像
 */
signals:
    void sendFrame(QImage frame);

private:
    bool isExit;
    QMutex mutex;
    int width, height;
    cv::VideoCapture *cameraCapture;
    cv::Mat cameraFrame;


/*
 * 线程函数
 */
    void run();
    QImage MatToQImage(cv::Mat mat);
};

#endif // CMERACONTROL_H
