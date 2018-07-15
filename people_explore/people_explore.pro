#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T12:02:38
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia
QT       +=multimediawidgets
QT       +=sql
QT       +=axcontainer
QT       +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = people_explore
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += $$PWD/Libs/Opencv/lib/opencv_world310.lib
LIBS += $$PWD/Libs/AiFace/lib/AiFace.lib
LIBS += $$PWD/Libs/ARCFace/libs/libarcsoft_fsdk_face_detection.lib
LIBS += $$PWD/Libs/ARCFace/libs/libarcsoft_fsdk_face_recognition.lib

INCLUDEPATH += $$PWD/Libs/Opencv/include
INCLUDEPATH += $$PWD/Libs/ARCFace/include

SOURCES += main.cpp\
        mainwidget.cpp \
    infomanager.cpp \
    infodatabase.cpp \
    attendmanager.cpp \
    cmeracontrol.cpp \
    aifacecontrol.cpp \
    inputinfo.cpp \
    aithread.cpp \
    loadingdialog.cpp

HEADERS  += mainwidget.h \
    infomanager.h \
    infodatabase.h \
    attendmanager.h \
    cmeracontrol.h \
    aifacecontrol.h \
    aifacekey.h \
    inputinfo.h \
    basicstruct.h \
    aithread.h \
    loadingdialog.h

FORMS    += mainwidget.ui \
    infomanager.ui \
    attendmanager.ui \
    inputinfo.ui \
    loadingdialog.ui
