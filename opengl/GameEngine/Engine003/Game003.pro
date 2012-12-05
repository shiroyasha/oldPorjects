QT -= gui core

TARGET = Game003

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
        -lGraphicsCore \
	-lGL \
	-lGLU
