#-------------------------------------------------
#
# Project created by QtCreator 2015-04-05T22:01:18
#
#-------------------------------------------------

QT       += core gui\
            xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CreateAndroidTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    question.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    question.h \
    settings.h

FORMS    += mainwindow.ui
