#ifndef BASICSTRUCT_H
#define BASICSTRUCT_H
/*
 * Info数据结构
 */
typedef struct InFoStruct
{
    QString Num;
    QString Gender;
    QString Name;
    QString Age;
    QString Apart;
    QString Feature;
    int Feature_size;
    QString Image;
}InFoStruct;


/*
 * Feature-ID数据结构
 */
typedef struct IDFStruct
{
    QString Num;
    QString Feature;
    int Feature_size;
}IDFStruct;


/*
 *输入信息数据结构
 */
typedef struct Basic_Info
{
    QString ID;
    QString Name;
    QString Gender;
    QString Age;
    QString Apart;

}Basic_Info;
/*
 * ID-SIM数据结构
 */
typedef struct IDSIMstruct
{
    QString ID;
    float sim;
}IDSIMstruct;

/*
 * 签到信息数据结构
 */
typedef struct Attenedinfo
{
    QString Time;
    QString ID;
    QString Name;
    QString Gender;
    QString Age;
    QString Apart;
    QString image;
}Attenedinfo;
#endif // BASICSTRUCT_H
