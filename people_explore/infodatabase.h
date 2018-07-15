#ifndef INFODATABASE_H
#define INFODATABASE_H
#define DATABASE_PATH "./data/database/Info.db"

#include<QObject>
#include<QtSql/qsql.h>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QVector>

#include "basicstruct.h"

class InFoDatabase
{
public:
/*
 * 连接和创建数据库、表
 */
    bool infodata(QString dbpath);
    void create_infodb();


/*
 * 查询显示元素
 */
    bool Infoforshow(QSqlQueryModel *model, QString condition);
    bool dataforshow(QSqlQueryModel *model, QString condition);
/*
 * 根据条件查询
 */
    InFoStruct InfoSelect(QString condition);
    Attenedinfo get_attenedinfo(QString condition);

/*
 * 获取ID-Feature视图
 */
    QVector<IDFStruct> IDFSelect();


/*
 * 插入数据
 */
    bool InsertInfo(InFoStruct info);
    bool InsertAttenedInfo(Attenedinfo info);

/*
 * 单例模式初始化信息数据库
 */
    static InFoDatabase* Get_Infodb()
    {
        if(Infodb == NULL)
        {
            Infodb = new InFoDatabase;
        }
        return Infodb;
    }
    static InFoDatabase* Get_InFoDatabase()
    {
        return Get_Infodb();
    }


/*
 * 关闭数据库
 */
    void InFoClose();
private:
    InFoDatabase();
    static InFoDatabase *Infodb;
    QSqlDatabase main_db;
};

#endif // INFODATABASE_H
