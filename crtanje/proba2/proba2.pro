#-------------------------------------------------
#
# Project created by QtCreator 2010-07-23T11:24:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = proba2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += -I/usr/X11R6/include `pkg-config --cflags cairo`

LIBS    += `pkg-config --libs cairo` -L/usr/X11R6/lib -lX11
