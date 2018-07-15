/********************************************************************************
** Form generated from reading UI file 'inputinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTINFO_H
#define UI_INPUTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputInfo
{
public:
    QLabel *Titlelabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QToolButton *confirmButton;
    QToolButton *cancelButton;
    QLineEdit *IDEdit;
    QLineEdit *NameEdit;
    QLineEdit *GenderEdit;
    QLineEdit *AgeEdit;
    QLineEdit *ApartEdit;
    QLabel *piclabel;

    void setupUi(QWidget *InputInfo)
    {
        if (InputInfo->objectName().isEmpty())
            InputInfo->setObjectName(QStringLiteral("InputInfo"));
        InputInfo->resize(600, 434);
        InputInfo->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        Titlelabel = new QLabel(InputInfo);
        Titlelabel->setObjectName(QStringLiteral("Titlelabel"));
        Titlelabel->setGeometry(QRect(30, 10, 121, 31));
        Titlelabel->setStyleSheet(QString::fromUtf8("color:white;font: 20pt \"Adobe \346\245\267\344\275\223 Std R\";font-weight:bold"));
        label = new QLabel(InputInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 51, 31));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(255, 255, 255);font-size:bold"));
        label_2 = new QLabel(InputInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 140, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(255, 255, 255);font-size:bold"));
        label_3 = new QLabel(InputInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 190, 51, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(255, 255, 255);font-size:bold"));
        label_4 = new QLabel(InputInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 240, 51, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(255, 255, 255);font-size:bold"));
        label_5 = new QLabel(InputInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 290, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";color:rgb(255, 255, 255);font-size:bold"));
        confirmButton = new QToolButton(InputInfo);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(190, 360, 80, 31));
        cancelButton = new QToolButton(InputInfo);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(330, 360, 80, 31));
        IDEdit = new QLineEdit(InputInfo);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));
        IDEdit->setGeometry(QRect(130, 90, 221, 31));
        IDEdit->setStyleSheet(QStringLiteral("background-color:white"));
        NameEdit = new QLineEdit(InputInfo);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(130, 140, 221, 31));
        NameEdit->setStyleSheet(QStringLiteral("background-color:white"));
        GenderEdit = new QLineEdit(InputInfo);
        GenderEdit->setObjectName(QStringLiteral("GenderEdit"));
        GenderEdit->setGeometry(QRect(130, 190, 221, 31));
        GenderEdit->setStyleSheet(QStringLiteral("background-color:white"));
        AgeEdit = new QLineEdit(InputInfo);
        AgeEdit->setObjectName(QStringLiteral("AgeEdit"));
        AgeEdit->setGeometry(QRect(130, 240, 221, 31));
        AgeEdit->setStyleSheet(QStringLiteral("background-color:white"));
        ApartEdit = new QLineEdit(InputInfo);
        ApartEdit->setObjectName(QStringLiteral("ApartEdit"));
        ApartEdit->setGeometry(QRect(130, 290, 221, 31));
        ApartEdit->setStyleSheet(QStringLiteral("background-color:white"));
        piclabel = new QLabel(InputInfo);
        piclabel->setObjectName(QStringLiteral("piclabel"));
        piclabel->setGeometry(QRect(400, 90, 161, 211));
        piclabel->setStyleSheet(QStringLiteral("background-color:white"));

        retranslateUi(InputInfo);

        QMetaObject::connectSlotsByName(InputInfo);
    } // setupUi

    void retranslateUi(QWidget *InputInfo)
    {
        InputInfo->setWindowTitle(QApplication::translate("InputInfo", "Form", Q_NULLPTR));
        Titlelabel->setText(QApplication::translate("InputInfo", "\347\231\273\350\256\260\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("InputInfo", "\345\267\245\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputInfo", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputInfo", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("InputInfo", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("InputInfo", "\351\203\250\351\227\250\357\274\232", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("InputInfo", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InputInfo", "\345\217\226\346\266\210", Q_NULLPTR));
        piclabel->setText(QApplication::translate("InputInfo", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputInfo: public Ui_InputInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTINFO_H
