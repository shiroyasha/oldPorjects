/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 10 14:31:43 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      24,   11,   11,   11, 0x09,
      49,   11,   11,   11, 0x09,
      66,   11,   11,   11, 0x09,
      81,   11,   11,   11, 0x09,
     107,   11,   11,   11, 0x09,
     128,   11,   11,   11, 0x09,
     150,   11,   11,   11, 0x09,
     171,   11,   11,   11, 0x09,
     190,   11,   11,   11, 0x09,
     210,   11,   11,   11, 0x09,
     230,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFiles()\0"
    "setVideoSliderValue(int)\0setDuration(int)\0"
    "setVolume(int)\0setVolumeSliderValue(int)\0"
    "setFileName(QString)\0togglePlayPauseIcon()\0"
    "setVideoWidgetSize()\0toggleFullScreen()\0"
    "toggleToolBar(bool)\0setAspectRatio(int)\0"
    "openFileFromAnotherProcess(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFiles(); break;
        case 1: setVideoSliderValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setDuration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setVolumeSliderValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: togglePlayPauseIcon(); break;
        case 7: setVideoWidgetSize(); break;
        case 8: toggleFullScreen(); break;
        case 9: toggleToolBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setAspectRatio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: openFileFromAnotherProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
