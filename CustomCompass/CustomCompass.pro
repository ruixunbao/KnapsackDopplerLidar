#-------------------------------------------------
#
# Project created by QtCreator 2017-07-30T12:34:16
#
#-------------------------------------------------

QT       += core gui
#LIBS += -lDbgHelp
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomCompass
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    direction_needle.cpp \
    speed_bar.cpp \
    wind_display.cpp \
    heights_label.cpp

HEADERS += \
        mainwindow.h \
    direction_needle.h \
    speed_bar.h \
    wind_display.h \
    heights_label.h

FORMS +=
