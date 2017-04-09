#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T00:53:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zork_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Character.cpp \
    item.cpp \
    Room.cpp \
    ZorkUL.cpp \
    ship.cpp \
    time.cpp

HEADERS  += mainwindow.h \
    Character.h \
    Room.h \
    item.h \
    ZorkUL.h \
    ship.h \
    timenow.h

FORMS    += mainwindow.ui

DISTFILES += \
    zork_GUI.pro.user
