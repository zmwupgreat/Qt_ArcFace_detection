#include "attendmanager.h"
#include "ui_attendmanager.h"
#include <QDebug>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
AttendManager::AttendManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttendManager)
{
    ui->setupUi(this);
    infodb = InFoDatabase::Get_InFoDatabase();
    InitTable();
    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(onBtnExitClicked()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

AttendManager::~AttendManager()
{
    delete ui;
}
/*
 * 初始化数据表
 */
void AttendManager::InitTable()
{
    //确定数据表格式
    ui->datatableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->datatableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->datatableView->setShowGrid(true);
    ui->datatableView->horizontalHeader()->setStretchLastSection(true);
    ui->datatableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->datatableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->datatableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->datatableView->verticalHeader()->setVisible(false);
    tableModel = new QSqlQueryModel;
    InittableModel();
    connect(ui->datatableView,SIGNAL(clicked(QModelIndex)),this,SLOT(onModelIndexClicked()));
}
/*
 * 初始化数据模型
 */
void AttendManager::InittableModel()
{
    tableModel->clear();
    infodb->dataforshow(tableModel,"");
    ui->datatableView->setModel(tableModel);
    tableModel->setHeaderData(0,Qt::Horizontal,"签到时间");
    tableModel->setHeaderData(1,Qt::Horizontal,"工号");
    tableModel->setHeaderData(2,Qt::Horizontal,"姓名");
    tableModel->setHeaderData(3,Qt::Horizontal,"性别");
    tableModel->setHeaderData(4,Qt::Horizontal,"年龄");
    tableModel->setHeaderData(5,Qt::Horizontal,"部门");
    ui->datatableView->show();
}
/*
 * 显示选中行信息
 */
void AttendManager::onModelIndexClicked()
{
    int row = ui->datatableView->currentIndex().row();
    QString showTime = tableModel->data(tableModel->index(row,0),Qt::DisplayRole).toString();
    QString condition = QString("and Time='%1'").arg(showTime);
    Attenedinfo info = infodb->get_attenedinfo(condition);
    qDebug()<<info.image;
    QImage photo;
    photo.load(info.image);
    photo = photo.scaled(171,221,Qt::KeepAspectRatio);
    ui->photolabel->setPixmap(QPixmap::fromImage(photo));
    ui->IDlabel->setText(info.ID);
    ui->Namelabel->setText(info.Name);
    ui->Apartlabel->setText(info.Apart);
    ui->Timelabel->setText(info.Time);
}
/*
 * 关闭窗口
 */
void AttendManager::onBtnExitClicked()
{
    this->close();
}
/*
 * 重写鼠标事件
 */
void AttendManager::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void AttendManager::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void AttendManager::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
