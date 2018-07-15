#ifndef ATTENDMANAGER_H
#define ATTENDMANAGER_H

#include <QWidget>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMouseEvent>
#include <QTableView>
#include <QTreeView>
#include "infodatabase.h"
#include "basicstruct.h"
namespace Ui {
class AttendManager;
}

class AttendManager : public QWidget
{
    Q_OBJECT

public:
    explicit AttendManager(QWidget *parent = 0);
    ~AttendManager();

/*
 * 数据表
 */
    void InitTable();
    void InittableModel();

private:
    Ui::AttendManager *ui;
    InFoDatabase *infodb;
    QSqlQueryModel *tableModel;
private slots:
    void onBtnExitClicked();
    void onModelIndexClicked();


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

#endif // ATTENDMANAGER_H
