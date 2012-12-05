/****************************************************************************
** Meta object code from reading C++ file 'MyWidget.h'
**
** Created: Thu Mar 11 03:20:49 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      20,    9,    9,    9, 0x05,
      42,    9,    9,    9, 0x05,
      57,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   77,    9,    9, 0x0a,
     101,    9,    9,    9, 0x0a,
     113,    9,    9,    9, 0x0a,
     125,    9,    9,    9, 0x0a,
     138,    9,    9,    9, 0x0a,
     151,    9,    9,    9, 0x0a,
     170,    9,    9,    9, 0x0a,
     190,    9,    9,    9, 0x0a,
     206,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWidget[] = {
    "MyWidget\0\0resized()\0zoomValueChanged(int)\0"
    "imageChanged()\0setZoomSlider(bool)\0"
    "angle\0rotatePixmap(int)\0nextImage()\0"
    "prevImage()\0adjustSize()\0setZoom(int)\0"
    "rotatePixmapLeft()\0rotatePixmapRight()\0"
    "fitInView(bool)\0openImage()\0"
};

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget,
      qt_meta_data_MyWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget))
        return static_cast<void*>(const_cast< MyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resized(); break;
        case 1: zoomValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: imageChanged(); break;
        case 3: setZoomSlider((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: rotatePixmap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: nextImage(); break;
        case 6: prevImage(); break;
        case 7: adjustSize(); break;
        case 8: setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: rotatePixmapLeft(); break;
        case 10: rotatePixmapRight(); break;
        case 11: fitInView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: openImage(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MyWidget::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyWidget::zoomValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyWidget::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MyWidget::setZoomSlider(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
