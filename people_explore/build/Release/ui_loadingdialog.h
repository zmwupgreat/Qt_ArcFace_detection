/********************************************************************************
** Form generated from reading UI file 'loadingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDIALOG_H
#define UI_LOADINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LoadingDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *LoadingDialog)
    {
        if (LoadingDialog->objectName().isEmpty())
            LoadingDialog->setObjectName(QStringLiteral("LoadingDialog"));
        LoadingDialog->resize(624, 140);
        LoadingDialog->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        label = new QLabel(LoadingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 521, 41));
        label->setStyleSheet(QString::fromUtf8("font: 25 28pt \"Adobe \345\256\213\344\275\223 Std L\";"));

        retranslateUi(LoadingDialog);

        QMetaObject::connectSlotsByName(LoadingDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadingDialog)
    {
        LoadingDialog->setWindowTitle(QApplication::translate("LoadingDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LoadingDialog", "\344\273\273\345\212\241\346\255\243\345\234\250\345\244\204\347\220\206\344\270\255\357\274\214\350\257\267\347\255\211\345\276\205......", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadingDialog: public Ui_LoadingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDIALOG_H
