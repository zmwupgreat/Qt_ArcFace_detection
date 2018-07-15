#include "infodatabase.h"
#include <QString>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
/*
 * 创建数据库文件
 */
InFoDatabase* InFoDatabase::Infodb = NULL;
InFoDatabase::InFoDatabase()
{
    //查找信息数据库是否存在
    QFile db_file(DATABASE_PATH);
    if(db_file.exists())
    {
        //连接默认数据库
        if(!infodata(DATABASE_PATH))
        {
            qDebug()<<"信息数据库连接失败!";
            QMessageBox::warning(NULL,"提示","信息数据库打开失败","确定");
        }
    }
    else
    {
        QString dbpath = "./data/database";
        QDir dbDir;
        if(!dbDir.exists(dbpath))
            dbDir.mkpath(dbpath);
        create_infodb();
    }
}


/*
 * 创建数据库表
 */
void InFoDatabase::create_infodb()
{
    main_db = QSqlDatabase::addDatabase("QSQLITE");
    main_db.setDatabaseName(DATABASE_PATH);
    main_db.open();
    QSqlQuery create_table_query;
    QString table_str = QString("CREATE TABLE INFOMANAGER (Num varchar NOT NULL PRIMARY KEY,");
    table_str += QString("Name varchar NOT NULL,");
    table_str += QString("Gender varchar NOT NULL,");
    table_str += QString("Age varchar NOT NULL,");
    table_str += QString("Apart varchar NOT NULL,");
    table_str += QString("Feature TEXT NOT NULL,");
    table_str += QString("Feature_size int NOT NULL,");
    table_str += QString("Image TEXT)");
    bool success = create_table_query.exec(table_str);
    if(!success)
    {
        QMessageBox::warning(NULL,"提示","信息数据库表创建失败","确定");
        return;
    }

    QSqlQuery create_table_query1;
    QString table_str1 = QString("CREATE TABLE ATTENEDMANAGER (Time varchar NOT NULL PRIMARY KEY,");
    table_str1 += QString("ID varchar NOT NULL,");
    table_str1 += QString("Name varchar NOT NULL,");
    table_str1 += QString("Gender varchar NOT NULL,");
    table_str1 += QString("Age varchar NOT NULL,");
    table_str1 += QString("Apart varchar NOT NULL,");
    table_str1 += QString("Image varchar NOT NULL);");
    bool success1 = create_table_query1.exec(table_str1);
    if(!success1)
    {
        QMessageBox::warning(NULL,"提示","签到数据表创建失败","确定");
        return;
    }

}


/*
 * 关闭数据库
 */
void InFoDatabase::InFoClose()
{
    main_db.close();
}


/*
 *连接数据库
 */
bool InFoDatabase::infodata(QString dbpath)
{
    main_db = QSqlDatabase::addDatabase("QSQLITE");
    main_db.setDatabaseName(dbpath);
    if(main_db.isOpen())
        main_db.close();
    bool db_open = main_db.open();
    return db_open;
}


/*
 * 查询显示元素
 */
bool InFoDatabase::Infoforshow(QSqlQueryModel *model, QString condition)
{
    if(!main_db.isOpen())
        main_db.open();
    QString str = QString("select Num,Name,Gender,Age,Apart from INFOMANAGER where 1=1 ");
    str += condition;
    str += "order by Num asc";
    model->setQuery(str);
    InFoClose();
    return true;
}
bool InFoDatabase::dataforshow(QSqlQueryModel *model, QString condition)
{
    if(!main_db.isOpen())
            main_db.open();
        QString str = QString("select Time,ID,Name,Gender,Age,Apart from ATTENEDMANAGER where 1=1 ");
        str += condition;
        str += "order by Time desc";
        model->setQuery(str);
        InFoClose();
        return true;
}
/*
 * 根据条件查询
 */
InFoStruct InFoDatabase::InfoSelect(QString condition)
{
    InFoStruct infostruct;
    if(!main_db.isOpen())
        main_db.open();
    QSqlQuery infoquery;
    QString str = QString("select * from INFOMANAGER where 1=1 ");
    str += condition;
    bool select_success = infoquery.exec(str);
    if(!select_success)
    {
        QMessageBox::warning(NULL,"提示","获取人员信息失败","确定");
        infoquery.clear();
        main_db.close();
        return infostruct;
    }
    infoquery.first();
    infostruct.Num = infoquery.value(0).toString();
    infostruct.Name = infoquery.value(1).toString();
    infostruct.Gender = infoquery.value(2).toString();
    infostruct.Age = infoquery.value(3).toString();
    infostruct.Apart = infoquery.value(4).toString();
    infostruct.Feature = infoquery.value(5).toString();
    infostruct.Feature_size = infoquery.value(6).toInt();
    infostruct.Image = infoquery.value(7).toString();
    infoquery.clear();
    main_db.close();
    return infostruct;
}

Attenedinfo InFoDatabase::get_attenedinfo(QString condition)
{
    Attenedinfo info;
    if(!main_db.isOpen())
        main_db.open();
    QSqlQuery infoquery;
    QString str = QString("select * from ATTENEDMANAGER where 1=1 ");
    str += condition;
    bool success = infoquery.exec(str);
    if(!success)
    {
        QMessageBox::warning(NULL,"提示","获取签到信息失败","确定");
        infoquery.clear();
        main_db.close();
        return info;
    }
    infoquery.first();
    info.Time = infoquery.value(0).toString();
    info.ID = infoquery.value(1).toString();
    info.Name = infoquery.value(2).toString();
    info.Gender = infoquery.value(3).toString();
    info.Age = infoquery.value(4).toString();
    info.Apart = infoquery.value(5).toString();
    info.image = infoquery.value(6).toString();
    infoquery.clear();
    main_db.close();
    return info;
}

/*
 * 获取ID-Feature视图
 */
QVector<IDFStruct> InFoDatabase::IDFSelect()
{
    QVector<IDFStruct> IDF;
    if(!main_db.isOpen())
        main_db.open();
    QSqlQuery IFquery;
    QString str = QString("select Num,Feature,Feature_size from INFOMANAGER where 1=1;");//Num,Feature,Feature_size
    bool select_success  = IFquery.exec(str);
    if(!select_success)
    {
        QMessageBox::warning(NULL,"提示","获取Feature-ID视图失败","确定");
        IFquery.clear();
        main_db.close();
        return IDF;
    }
    else
    {
        IFquery.first();
        while(true)
        {
            IDFStruct idfstruct;
            idfstruct.Num = IFquery.value(0).toString();
            idfstruct.Feature = IFquery.value(1).toString();
            idfstruct.Feature_size = IFquery.value(2).toInt();
            IDF.push_back(idfstruct);
            if(!IFquery.next())
            {
                break;
            }
        }
    }
    IFquery.clear();
    main_db.close();
    return IDF;
}


/*
 * 向数据库插入数据
 */
bool InFoDatabase::InsertInfo(InFoStruct info)
{
    if(!main_db.isOpen())
        main_db.open();
    QSqlQuery insert_query;
    QString str = QString("insert into INFOMANAGER values(");
    str += QString("'%1'").arg(info.Num);
    str += QString(",'%1'").arg(info.Name);
    str += QString(",'%1'").arg(info.Gender);
    str += QString(",'%1'").arg(info.Age);
    str += QString(",'%1'").arg(info.Apart);
    str += QString(",'%1'").arg(info.Feature);
    str += QString(",'%1'").arg(info.Feature_size);
    str += QString(",'%1');").arg(info.Image);
    bool insert_success = insert_query.exec(str);
    if(!insert_success)
    {
        qDebug()<<"false";
        return false;
    }
    else
    {
        qDebug()<<"true";
        return true;
    }
}
bool InFoDatabase::InsertAttenedInfo(Attenedinfo info)
{
    if(!main_db.isOpen())
        main_db.open();
    QSqlQuery insert_query;
    QString str = QString("insert into ATTENEDMANAGER values(");
    str += QString("'%1'").arg(info.Time);
    str += QString(",'%1'").arg(info.ID);
    str += QString(",'%1'").arg(info.Name);
    str += QString(",'%1'").arg(info.Gender);
    str += QString(",'%1'").arg(info.Age);
    str += QString(",'%1'").arg(info.Apart);
    str += QString(",'%1');").arg(info.image);
    bool insert_success = insert_query.exec(str);
    if(!insert_success)
    {
        qDebug()<<"插入失败";
        return false;
    }
    return true;
}
