#include "infomanager.h"
#include "ui_infomanager.h"

#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QTableView>
#include <QMouseEvent>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif

InFoManager::InFoManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InFoManager)
{
    ui->setupUi(this);
    infodb = InFoDatabase::Get_InFoDatabase();
    InitTable();
    connect(ui->exitbtn,SIGNAL(clicked(bool)),this,SLOT(onbtnexitClicked()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

InFoManager::~InFoManager()
{
    delete ui;
}
/*
 * 初始化数据表
 */

void InFoManager::InitTable()
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
    InittableModel();//初始化数据模型
    connect(ui->datatableView,SIGNAL(clicked(QModelIndex)),SLOT(onmodelindexClicked()));

}
/*
 * 初始化数据模型
 */

void InFoManager::InittableModel()
{
    tableModel->clear();
    infodb->Infoforshow(tableModel,"");
    ui->datatableView->setModel(tableModel);
    tableModel->setHeaderData(0,Qt::Horizontal,"工号");
    tableModel->setHeaderData(1,Qt::Horizontal,"姓名");
    tableModel->setHeaderData(2,Qt::Horizontal,"性别");
    tableModel->setHeaderData(3,Qt::Horizontal,"年龄");
    tableModel->setHeaderData(4,Qt::Horizontal,"部门");
    ui->datatableView->show();
}
/*
 * 显示选中行信息
 */
void InFoManager::onmodelindexClicked()
{
    int row = ui->datatableView->currentIndex().row();
    QString showID = tableModel->data(tableModel->index(row,0),Qt::DisplayRole).toString();
    QString condition = QString("and Num='%1'").arg(showID);
    InFoStruct infostruct = infodb->InfoSelect(condition);

    QImage photo;
    photo.load(infostruct.Image);
    photo = photo.scaled(171,221,Qt::KeepAspectRatio);
    ui->photolabel->setPixmap(QPixmap::fromImage(photo));
    ui->namelabel->setText(infostruct.Name);
    ui->IDlabel->setText(infostruct.Num);
    ui->Genderlabel->setText(infostruct.Gender);
    ui->Agelabel->setText(infostruct.Age);
    ui->Apartlabel->setText(infostruct.Apart);
}

/*
 * 退出信息管理界面
 */
void InFoManager::onbtnexitClicked()
{
    this->close();
}
/*
 * 重写鼠标事件
 */
void InFoManager::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void InFoManager::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void InFoManager::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
