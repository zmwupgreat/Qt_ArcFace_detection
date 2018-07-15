/********************************************************************************
** Form generated from reading UI file 'infomanager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOMANAGER_H
#define UI_INFOMANAGER_H

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

class Ui_InFoManager
{
public:
    QTableView *datatableView;
    QLabel *photolabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox;
    QLabel *namelabel;
    QLabel *IDlabel;
    QLabel *Agelabel;
    QLabel *Apartlabel;
    QLabel *Genderlabel;
    QToolButton *exitbtn;

    void setupUi(QWidget *InFoManager)
    {
        if (InFoManager->objectName().isEmpty())
            InFoManager->setObjectName(QStringLiteral("InFoManager"));
        InFoManager->resize(1280, 720);
        InFoManager->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        datatableView = new QTableView(InFoManager);
        datatableView->setObjectName(QStringLiteral("datatableView"));
        datatableView->setGeometry(QRect(30, 130, 601, 561));
        datatableView->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        photolabel = new QLabel(InFoManager);
        photolabel->setObjectName(QStringLiteral("photolabel"));
        photolabel->setGeometry(QRect(670, 280, 171, 221));
        photolabel->setAutoFillBackground(false);
        photolabel->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255)"));
        label = new QLabel(InFoManager);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(870, 280, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(3);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_2 = new QLabel(InFoManager);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(870, 330, 61, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_3 = new QLabel(InFoManager);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(870, 380, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_4 = new QLabel(InFoManager);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(870, 430, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_5 = new QLabel(InFoManager);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(870, 480, 61, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 16pt \"Adobe \345\256\213\344\275\223 Std L\";color:white;font-size:bold"));
        label_6 = new QLabel(InFoManager);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 30, 261, 61));
        label_6->setStyleSheet(QString::fromUtf8("color:white;font: 28pt \"Adobe \346\245\267\344\275\223 Std R\";font-weight:bold"));
        groupBox = new QGroupBox(InFoManager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(650, 230, 601, 361));
        groupBox->setTitle(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        namelabel = new QLabel(groupBox);
        namelabel->setObjectName(QStringLiteral("namelabel"));
        namelabel->setGeometry(QRect(300, 50, 231, 31));
        namelabel->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        IDlabel = new QLabel(groupBox);
        IDlabel->setObjectName(QStringLiteral("IDlabel"));
        IDlabel->setGeometry(QRect(300, 100, 231, 31));
        IDlabel->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Agelabel = new QLabel(groupBox);
        Agelabel->setObjectName(QStringLiteral("Agelabel"));
        Agelabel->setGeometry(QRect(300, 150, 231, 31));
        Agelabel->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Apartlabel = new QLabel(groupBox);
        Apartlabel->setObjectName(QStringLiteral("Apartlabel"));
        Apartlabel->setGeometry(QRect(300, 200, 231, 31));
        Apartlabel->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        Genderlabel = new QLabel(groupBox);
        Genderlabel->setObjectName(QStringLiteral("Genderlabel"));
        Genderlabel->setGeometry(QRect(300, 250, 231, 31));
        Genderlabel->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        exitbtn = new QToolButton(InFoManager);
        exitbtn->setObjectName(QStringLiteral("exitbtn"));
        exitbtn->setGeometry(QRect(1110, 30, 131, 41));
        groupBox->raise();
        datatableView->raise();
        photolabel->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        exitbtn->raise();

        retranslateUi(InFoManager);

        QMetaObject::connectSlotsByName(InFoManager);
    } // setupUi

    void retranslateUi(QWidget *InFoManager)
    {
        InFoManager->setWindowTitle(QApplication::translate("InFoManager", "Form", Q_NULLPTR));
        photolabel->setText(QString());
        label->setText(QApplication::translate("InFoManager", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("InFoManager", "\345\267\245\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("InFoManager", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("InFoManager", "\351\203\250\351\227\250\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("InFoManager", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("InFoManager", "\344\272\272\345\221\230\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        namelabel->setText(QString());
        IDlabel->setText(QString());
        Agelabel->setText(QString());
        Apartlabel->setText(QString());
        Genderlabel->setText(QString());
        exitbtn->setText(QApplication::translate("InFoManager", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InFoManager: public Ui_InFoManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOMANAGER_H
