#ifndef INPUTINFO_H
#define INPUTINFO_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QTextEdit>
#include <QImage>

#include "basicstruct.h"

namespace Ui {
class InputInfo;
}

class InputInfo : public QWidget
{
    Q_OBJECT

public:
    explicit InputInfo(QWidget *parent = 0);
    ~InputInfo();
    Basic_Info GetBasicInfo();
/*
 * 清除信息
 */
    void CleanEdit();
/*
 * 展示照片
 */
    void setPic(QImage image);

private:
    Ui::InputInfo *ui;
    Basic_Info binfo;

/*
 * 按钮槽
 */
private slots:
    void onOKBtnclicked();
    void onCancelBtnclicked();

/*
 * 返回消息
 */
signals:
    void sendInputInfoMsg(bool);

/*
 * 重写鼠标事件
 */
private:
    QPoint last;//智能指针
protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // INPUTINFO_H
