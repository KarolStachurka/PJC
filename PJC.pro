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
    helix.cpp \
    plant.cpp \
    lettuce.cpp \
    simulationthread.cpp \
    myqgraphicsscene.cpp \
    grass.cpp \
    organism.cpp \
    slug.cpp \
    cabbage.cpp \
    worm.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    field.h \
    board.h \
    snail.h \
    helix.h \
    plant.h \
    lettuce.h \
    simulationthread.h \
    myqgraphicsscene.h \
    grass.h \
    organism.h \
    slug.h \
    cabbage.h \
    worm.h \
    game.h

FORMS    += mainwindow.ui
