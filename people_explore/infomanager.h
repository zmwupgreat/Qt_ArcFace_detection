#ifndef INFOMANAGER_H
#define INFOMANAGER_H

#include <QWidget>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QTableView>
#include "infodatabase.h"
namespace Ui {
class InFoManager;
}

class InFoManager : public QWidget
{
    Q_OBJECT

public:
    explicit InFoManager(QWidget *parent = 0);
    ~InFoManager();
/*
 * 数据表
 */
    void InitTable();
    void InittableModel();
    void realseModel();

private:
    Ui::InFoManager *ui;
    InFoDatabase *infodb;
/*
 * 数据表
 */
    QSqlQueryModel *tableModel;
private slots:
    void onbtnexitClicked();
    void onmodelindexClicked();
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

#endif // INFOMANAGER_H
