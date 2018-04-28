#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T13:26:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console c++11
TARGET = PJC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    field.cpp \
    board.cpp \
    snail.cpp \
    helix.cpp

HEADERS  += mainwindow.h \
    field.h \
    board.h \
    snail.h \
    helix.h

FORMS    += mainwindow.ui
