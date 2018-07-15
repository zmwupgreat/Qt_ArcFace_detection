#include "inputinfo.h"
#include "ui_inputinfo.h"
#include <QMessageBox>

InputInfo::InputInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputInfo)
{
    ui->setupUi(this);
    connect(ui->confirmButton,SIGNAL(clicked(bool)),this,SLOT(onOKBtnclicked()));
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(onCancelBtnclicked()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

InputInfo::~InputInfo()
{
    delete ui;
}
/*
 * 清除Edit
 */
void InputInfo::CleanEdit()
{
    ui->IDEdit->clear();
    ui->NameEdit->clear();
    ui->AgeEdit->clear();
    ui->ApartEdit->clear();
    ui->GenderEdit->clear();
    ui->piclabel->clear();
}


/*
 * 展示照片
 */
void InputInfo::setPic(QImage image)
{
    ui->piclabel->setPixmap(QPixmap::fromImage(image));
}


/*
 * 确定按钮
 */
void InputInfo::onOKBtnclicked()
{
     if(ui->IDEdit->text().isEmpty()
             ||ui->NameEdit->text().isEmpty()
             ||ui->GenderEdit->text().isEmpty()
             ||ui->AgeEdit->text().isEmpty()
             ||ui->ApartEdit->text().isEmpty())
     {
         QMessageBox::information(this,"提示","请输入完整个人信息");
         return;
     }
     binfo.ID = ui->IDEdit->text();
     binfo.Name = ui->NameEdit->text();
     binfo.Gender = ui->GenderEdit->text();
     binfo.Age = ui->AgeEdit->text();
     binfo.Apart = ui->ApartEdit->text();
     emit sendInputInfoMsg(true);
     this->close();
}


/*
 * 取消按钮
 */
void InputInfo::onCancelBtnclicked()
{
    emit sendInputInfoMsg(false);
    this->close();
}

/*
 *获取基本信息
 */
Basic_Info InputInfo::GetBasicInfo()
{
    return binfo;
}



/*
 * 重写鼠标事件
 */
void InputInfo::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void InputInfo::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void InputInfo::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
