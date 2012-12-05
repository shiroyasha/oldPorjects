/****************************************************************************
** Meta object code from reading C++ file 'MPlayerProcess.h'
**
** Created: Sun Apr 4 13:01:59 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MPlayerProcess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MPlayerProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MPlayerProcess[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      35,   15,   15,   15, 0x05,
      54,   15,   15,   15, 0x05,
      75,   15,   15,   15, 0x05,
      99,   15,   15,   15, 0x05,
     124,   15,   15,   15, 0x05,
     133,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     147,   15,   15,   15, 0x0a,
     167,   15,   15,   15, 0x0a,
     185,   15,   15,   15, 0x0a,
     207,   15,   15,   15, 0x0a,
     222,   15,   15,   15, 0x0a,
     236,   15,   15,   15, 0x0a,
     250,   15,   15,   15, 0x0a,
     269,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MPlayerProcess[] = {
    "MPlayerProcess\0\0mediaPosition(int)\0"
    "volumeChanged(int)\0durationChanged(int)\0"
    "volumeLevelChanged(int)\0"
    "fileNameChanged(QString)\0paused()\0"
    "sizeChanged()\0openStream(QString)\0"
    "togglePlayPause()\0setMediaPosition(int)\0"
    "setVolume(int)\0setLoop(bool)\0setSpeed(int)\0"
    "setAudioDelay(int)\0readStandardOutput()\0"
};

const QMetaObject MPlayerProcess::staticMetaObject = {
    { &QProcess::staticMetaObject, qt_meta_stringdata_MPlayerProcess,
      qt_meta_data_MPlayerProcess, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MPlayerProcess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MPlayerProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MPlayerProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MPlayerProcess))
        return static_cast<void*>(const_cast< MPlayerProcess*>(this));
    return QProcess::qt_metacast(_clname);
}

int MPlayerProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProcess::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mediaPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: volumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: durationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: volumeLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: fileNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: paused(); break;
        case 6: sizeChanged(); break;
        case 7: openStream((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: togglePlayPause(); break;
        case 9: setMediaPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: setLoop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: setAudioDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: readStandardOutput(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MPlayerProcess::mediaPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MPlayerProcess::volumeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MPlayerProcess::durationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MPlayerProcess::volumeLevelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MPlayerProcess::fileNameChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MPlayerProcess::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MPlayerProcess::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
