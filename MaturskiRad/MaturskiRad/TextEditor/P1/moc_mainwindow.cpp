/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Apr 7 21:41:44 2010
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
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      19,   11,   11,   11, 0x09,
      26,   11,   11,   11, 0x09,
      33,   11,   11,   11, 0x09,
      40,   11,   11,   11, 0x09,
      49,   11,   11,   11, 0x09,
      64,   11,   11,   11, 0x09,
      82,   11,   11,   11, 0x09,
     101,   11,   11,   11, 0x09,
     110,   11,   11,   11, 0x09,
     133,   11,  129,   11, 0x09,
     147,   11,   11,   11, 0x09,
     162,   11,   11,   11, 0x09,
     181,   11,   11,   11, 0x09,
     198,   11,   11,   11, 0x09,
     226,   11,   11,   11, 0x09,
     245,   11,   11,   11, 0x09,
     256,   11,   11,   11, 0x09,
     267,   11,   11,   11, 0x09,
     281,   11,   11,   11, 0x09,
     299,   11,   11,   11, 0x09,
     312,   11,   11,   11, 0x09,
     326,   11,   11,   11, 0x09,
     343,   11,   11,   11, 0x09,
     355,   11,   11,   11, 0x09,
     366,   11,   11,   11, 0x09,
     389,   11,   11,   11, 0x09,
     396,   11,   11,   11, 0x09,
     402,   11,   11,   11, 0x09,
     410,   11,   11,   11, 0x09,
     419,   11,   11,   11, 0x09,
     430,   11,   11,   11, 0x09,
     442,   11,   11,   11, 0x09,
     454,   11,   11,   11, 0x09,
     467,   11,   11,   11, 0x09,
     480,   11,   11,   11, 0x09,
     498,   11,   11,   11, 0x09,
     507,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0undo()\0redo()\0open()\0"
    "save()\0saveAs()\0configureGui()\0"
    "configureGui(int)\0configureGui(bool)\0"
    "newTab()\0closeTabFromMenu()\0int\0"
    "closeTab(int)\0quitFromMenu()\0"
    "toggleFindWidget()\0toggleGotoLine()\0"
    "requestedClosing(TextEdit*)\0"
    "findFirst(QString)\0findNext()\0findPrev()\0"
    "replaceNext()\0replacePrevious()\0"
    "replaceAll()\0gotoLine(int)\0setGotoMaximum()\0"
    "selectAll()\0deselect()\0toggleCopyAction(bool)\0"
    "copy()\0cut()\0paste()\0indent()\0unindent()\0"
    "uppercase()\0lowercase()\0capitalize()\0"
    "selectFont()\0selectFontColor()\0zoomIn()\0"
    "zoomOut()\0"
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
        case 0: undo(); break;
        case 1: redo(); break;
        case 2: open(); break;
        case 3: save(); break;
        case 4: saveAs(); break;
        case 5: configureGui(); break;
        case 6: configureGui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: configureGui((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: newTab(); break;
        case 9: closeTabFromMenu(); break;
        case 10: { int _r = closeTab((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: quitFromMenu(); break;
        case 12: toggleFindWidget(); break;
        case 13: toggleGotoLine(); break;
        case 14: requestedClosing((*reinterpret_cast< TextEdit*(*)>(_a[1]))); break;
        case 15: findFirst((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: findNext(); break;
        case 17: findPrev(); break;
        case 18: replaceNext(); break;
        case 19: replacePrevious(); break;
        case 20: replaceAll(); break;
        case 21: gotoLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: setGotoMaximum(); break;
        case 23: selectAll(); break;
        case 24: deselect(); break;
        case 25: toggleCopyAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: copy(); break;
        case 27: cut(); break;
        case 28: paste(); break;
        case 29: indent(); break;
        case 30: unindent(); break;
        case 31: uppercase(); break;
        case 32: lowercase(); break;
        case 33: capitalize(); break;
        case 34: selectFont(); break;
        case 35: selectFontColor(); break;
        case 36: zoomIn(); break;
        case 37: zoomOut(); break;
        default: ;
        }
        _id -= 38;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
