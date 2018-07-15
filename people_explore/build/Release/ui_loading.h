/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QLabel *label;

    void setupUi(QWidget *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QStringLiteral("Loading"));
        Loading->resize(539, 139);
        Loading->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        label = new QLabel(Loading);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 471, 61));
        label->setStyleSheet(QString::fromUtf8("font: 30pt \"\345\256\213\344\275\223\";"));

        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QWidget *Loading)
    {
        Loading->setWindowTitle(QApplication::translate("Loading", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Loading", "\346\255\243\345\234\250\345\244\204\347\220\206\344\270\255\357\274\214\350\257\267\347\250\215\345\220\216......", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
