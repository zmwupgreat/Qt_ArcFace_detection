/********************************************************************************
** Form generated from reading UI file 'attendmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDMANAGER_H
#define UI_ATTENDMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttendManager
{
public:
    QTableView *datatableView;
    QLabel *label_8;
    QGroupBox *groupBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *photolabel;
    QLabel *IDlabel;
    QLabel *Namelabel;
    QLabel *Apartlabel;
    QLabel *Timelabel;
    QToolButton *exitButton;

    void setupUi(QWidget *AttendManager)
    {
        if (AttendManager->objectName().isEmpty())
            AttendManager->setObjectName(QStringLiteral("AttendManager"));
        AttendManager->resize(1280, 720);
        AttendManager->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        datatableView = new QTableView(AttendManager);
        datatableView->setObjectName(QStringLiteral("datatableView"));
        datatableView->setGeometry(QRect(30, 130, 601, 561));
        datatableView->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255)"));
        label_8 = new QLabel(AttendManager);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 30, 241, 51));
        label_8->setStyleSheet(QString::fromUtf8("color:white;font: 28pt \"Adobe \346\245\267\344\275\223 Std R\";font-weight:bold"));
        groupBox = new QGroupBox(AttendManager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(650, 230, 601, 361));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 130, 61, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 180, 61, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(250, 230, 101, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 80, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        photolabel = new QLabel(groupBox);
        photolabel->setObjectName(QStringLiteral("photolabel"));
        photolabel->setGeometry(QRect(30, 70, 171, 221));
        photolabel->setAutoFillBackground(false);
        photolabel->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255)"));
        IDlabel = new QLabel(groupBox);
        IDlabel->setObjectName(QStringLiteral("IDlabel"));
        IDlabel->setGeometry(QRect(370, 80, 201, 31));
        IDlabel->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Namelabel = new QLabel(groupBox);
        Namelabel->setObjectName(QStringLiteral("Namelabel"));
        Namelabel->setGeometry(QRect(370, 130, 201, 31));
        Namelabel->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Apartlabel = new QLabel(groupBox);
        Apartlabel->setObjectName(QStringLiteral("Apartlabel"));
        Apartlabel->setGeometry(QRect(370, 180, 201, 31));
        Apartlabel->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Timelabel = new QLabel(groupBox);
        Timelabel->setObjectName(QStringLiteral("Timelabel"));
        Timelabel->setGeometry(QRect(370, 230, 201, 31));
        Timelabel->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        exitButton = new QToolButton(AttendManager);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(1110, 30, 131, 41));
        groupBox->raise();
        datatableView->raise();
        label_8->raise();
        exitButton->raise();

        retranslateUi(AttendManager);

        QMetaObject::connectSlotsByName(AttendManager);
    } // setupUi

    void retranslateUi(QWidget *AttendManager)
    {
        AttendManager->setWindowTitle(QApplication::translate("AttendManager", "Form", Q_NULLPTR));
        label_8->setText(QApplication::translate("AttendManager", "\350\200\203\345\213\244\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_5->setText(QApplication::translate("AttendManager", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("AttendManager", "\351\203\250\351\227\250\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("AttendManager", "\347\255\276\345\210\260\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("AttendManager", "\345\267\245\345\217\267:", Q_NULLPTR));
        photolabel->setText(QString());
        IDlabel->setText(QString());
        Namelabel->setText(QString());
        Apartlabel->setText(QString());
        Timelabel->setText(QString());
        exitButton->setText(QApplication::translate("AttendManager", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AttendManager: public Ui_AttendManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDMANAGER_H
