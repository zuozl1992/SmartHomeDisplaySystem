#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T18:40:31
#
#-------------------------------------------------

QT          += core gui widgets

TARGET      = SHClient
TEMPLATE    = app

include(NetWork/network.pri)

SOURCES     += \
            main.cpp \
            mainpage.cpp

HEADERS     += \
            mainpage.h \
            config.h

FORMS       += \
            mainpage.ui

RC_FILE += \
            version.rc

RESOURCES += \
            images.qrc
