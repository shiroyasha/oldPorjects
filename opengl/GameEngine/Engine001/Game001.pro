# -------------------------------------------------
# Project created by QtCreator 2010-04-25T10:35:01
# -------------------------------------------------
QT -= gui core

TARGET = Game001

SOURCES += main.cpp \
    MyGame.cpp

HEADERS += MyGame.h

DESTDIR = build

LIBS += -Llib \
    -lSDL \
    -lSDL_image \
    -lEngineCore \
    -lGL -lGLU

