/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *buttonLayout;
    QToolButton *OneKeyButton;
    QToolButton *InputButton;
    QToolButton *InfoButton;
    QToolButton *AttendButton;
    QLabel *JITpiclabel;
    QLabel *Infopiclabel;
    QLabel *simlabel;
    QGroupBox *groupBox;
    QLabel *Infopic;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *infoIDlabel;
    QLabel *infoNamelabel;
    QLabel *infoAgelabel;
    QLabel *infoGenderlabel;
    QLabel *infoApartlabel;
    QLabel *label_4;
    QGraphicsView *CameragraphicsView;
    QToolButton *exitButton;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1280, 720);
        MainWidget->setAutoFillBackground(false);
        MainWidget->setStyleSheet(QStringLiteral("background-color:rgb(0,206,209)"));
        horizontalLayoutWidget = new QWidget(MainWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 610, 641, 91));
        buttonLayout = new QHBoxLayout(horizontalLayoutWidget);
        buttonLayout->setSpacing(7);
        buttonLayout->setContentsMargins(11, 11, 11, 11);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setContentsMargins(0, 3, 0, 3);
        OneKeyButton = new QToolButton(horizontalLayoutWidget);
        OneKeyButton->setObjectName(QStringLiteral("OneKeyButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OneKeyButton->sizePolicy().hasHeightForWidth());
        OneKeyButton->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(OneKeyButton);

        InputButton = new QToolButton(horizontalLayoutWidget);
        InputButton->setObjectName(QStringLiteral("InputButton"));
        sizePolicy.setHeightForWidth(InputButton->sizePolicy().hasHeightForWidth());
        InputButton->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(InputButton);

        InfoButton = new QToolButton(horizontalLayoutWidget);
        InfoButton->setObjectName(QStringLiteral("InfoButton"));
        sizePolicy.setHeightForWidth(InfoButton->sizePolicy().hasHeightForWidth());
        InfoButton->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(InfoButton);

        AttendButton = new QToolButton(horizontalLayoutWidget);
        AttendButton->setObjectName(QStringLiteral("AttendButton"));
        sizePolicy.setHeightForWidth(AttendButton->sizePolicy().hasHeightForWidth());
        AttendButton->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(AttendButton);

        JITpiclabel = new QLabel(MainWidget);
        JITpiclabel->setObjectName(QStringLiteral("JITpiclabel"));
        JITpiclabel->setGeometry(QRect(720, 130, 171, 221));
        JITpiclabel->setAutoFillBackground(false);
        JITpiclabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        Infopiclabel = new QLabel(MainWidget);
        Infopiclabel->setObjectName(QStringLiteral("Infopiclabel"));
        Infopiclabel->setGeometry(QRect(1070, 130, 171, 221));
        Infopiclabel->setAutoFillBackground(false);
        Infopiclabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        simlabel = new QLabel(MainWidget);
        simlabel->setObjectName(QStringLiteral("simlabel"));
        simlabel->setGeometry(QRect(940, 200, 81, 91));
        simlabel->setAutoFillBackground(false);
        simlabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(710, 400, 541, 271));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignCenter);
        Infopic = new QLabel(groupBox);
        Infopic->setObjectName(QStringLiteral("Infopic"));
        Infopic->setGeometry(QRect(40, 50, 131, 171));
        Infopic->setStyleSheet(QStringLiteral("background-color:white"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 60, 41, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 90, 41, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(240, 120, 41, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 150, 41, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 180, 41, 21));
        infoIDlabel = new QLabel(groupBox);
        infoIDlabel->setObjectName(QStringLiteral("infoIDlabel"));
        infoIDlabel->setGeometry(QRect(290, 60, 131, 16));
        infoNamelabel = new QLabel(groupBox);
        infoNamelabel->setObjectName(QStringLiteral("infoNamelabel"));
        infoNamelabel->setGeometry(QRect(290, 90, 131, 16));
        infoAgelabel = new QLabel(groupBox);
        infoAgelabel->setObjectName(QStringLiteral("infoAgelabel"));
        infoAgelabel->setGeometry(QRect(290, 120, 131, 16));
        infoGenderlabel = new QLabel(groupBox);
        infoGenderlabel->setObjectName(QStringLiteral("infoGenderlabel"));
        infoGenderlabel->setGeometry(QRect(290, 150, 131, 16));
        infoApartlabel = new QLabel(groupBox);
        infoApartlabel->setObjectName(QStringLiteral("infoApartlabel"));
        infoApartlabel->setGeometry(QRect(290, 180, 131, 16));
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 30, 311, 41));
        label_4->setStyleSheet(QString::fromUtf8("color:white;font: 28pt \"Adobe \346\245\267\344\275\223 Std R\";font-weight:bold"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setWordWrap(false);
        CameragraphicsView = new QGraphicsView(MainWidget);
        CameragraphicsView->setObjectName(QStringLiteral("CameragraphicsView"));
        CameragraphicsView->setGeometry(QRect(30, 110, 640, 480));
        CameragraphicsView->setAutoFillBackground(true);
        CameragraphicsView->setStyleSheet(QStringLiteral("background-color:white"));
        CameragraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        CameragraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        exitButton = new QToolButton(MainWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(1110, 30, 111, 31));
        groupBox_2 = new QGroupBox(MainWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(710, 110, 541, 261));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->raise();
        horizontalLayoutWidget->raise();
        JITpiclabel->raise();
        Infopiclabel->raise();
        simlabel->raise();
        groupBox->raise();
        label_4->raise();
        CameragraphicsView->raise();
        exitButton->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        OneKeyButton->setText(QApplication::translate("MainWidget", "\344\270\200\351\224\256\347\255\276\345\210\260", Q_NULLPTR));
        InputButton->setText(QApplication::translate("MainWidget", "\345\275\225\345\205\245\344\277\241\346\201\257", Q_NULLPTR));
        InfoButton->setText(QApplication::translate("MainWidget", "\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        AttendButton->setText(QApplication::translate("MainWidget", "\350\200\203\345\213\244\347\256\241\347\220\206", Q_NULLPTR));
        JITpiclabel->setText(QString());
        Infopiclabel->setText(QString());
        simlabel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWidget", "\344\277\241\346\201\257\346\230\276\347\244\272", Q_NULLPTR));
        Infopic->setText(QString());
        label_5->setText(QApplication::translate("MainWidget", "\345\267\245\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWidget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWidget", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWidget", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWidget", "\351\203\250\351\227\250\357\274\232", Q_NULLPTR));
        infoIDlabel->setText(QString());
        infoNamelabel->setText(QString());
        infoAgelabel->setText(QString());
        infoGenderlabel->setText(QString());
        infoApartlabel->setText(QString());
        label_4->setText(QApplication::translate("MainWidget", "\344\272\272\350\204\270\346\243\200\347\264\242\350\200\203\345\213\244\347\263\273\347\273\237", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWidget", "\345\256\236\346\227\266\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
