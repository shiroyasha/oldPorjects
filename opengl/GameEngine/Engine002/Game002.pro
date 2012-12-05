QT -= gui core

TARGET = Game002

SOURCES += main.cpp \
	   MyGame.cpp

HEADERS += MyGame.h

DESTDIR = build

INCLUDEPATH += ./lib/EngineCore \
	       ./lib/GraphicsCore

LIBS += -Llib \
	-lSDL \
	-lSDL_image \
	-lEngineCore \
	-lGL \
	-lGLU
