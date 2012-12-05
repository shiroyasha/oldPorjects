TEMPLATE    = app
CONFIG      -= moc
DESTDIR     = .
INCLUDEPATH += $$system(python getconfig.py INCLUDEPY)
LIBS        += $$system(python getconfig.py BLDLIBRARY) \
               -lpthread -ldl -lutil
DEFINES     += PYTHON_LIB_PATH=$$system(python getconfig.py site-packages) \
               MODULE_NAME=\\\"testmodule\\\" \
               MODULE_PATH=\\\"$$DESTDIR\\\"
QMAKE_CLEAN += testmodule.pyc

SOURCES += main.cpp
