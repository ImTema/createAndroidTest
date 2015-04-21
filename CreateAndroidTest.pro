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
    settings.cpp \
    dialog.cpp \
    checkbox.cpp \
    answer.cpp \
    radio.cpp \
    sequence.cpp \
    matching.cpp \
    short.cpp

HEADERS  += mainwindow.h \
    question.h \
    settings.h \
    dialog.h \
    checkbox.h \
    answer.h \
    radio.h \
    sequence.h \
    matching.h \
    short.h

FORMS    += mainwindow.ui \
    dialog.ui
