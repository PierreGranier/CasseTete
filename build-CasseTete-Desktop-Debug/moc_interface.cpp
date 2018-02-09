/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CasseTete/View/interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Interface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      19,   10,   10,   10, 0x08,
      28,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      50,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,
      70,   10,   10,   10, 0x08,
      81,   10,   10,   10, 0x08,
      96,   10,   10,   10, 0x08,
     115,   10,   10,   10, 0x08,
     133,   10,   10,   10, 0x08,
     148,   10,   10,   10, 0x08,
     163,   10,   10,   10, 0x08,
     178,   10,   10,   10, 0x08,
     193,   10,   10,   10, 0x08,
     208,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Interface[] = {
    "Interface\0\0solve()\0zoomIn()\0zoomOut()\0"
    "turnRight()\0turnLeft()\0turnUp()\0"
    "turnDown()\0switchPieceT()\0switchPieceAngle()\0"
    "switchPiecePlus()\0switchPieceL()\0"
    "switchPieceZ()\0switchPieceP()\0"
    "switchPieceY()\0switchPieceD()\0"
    "switchPieceG()\0"
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Interface *_t = static_cast<Interface *>(_o);
        switch (_id) {
        case 0: _t->solve(); break;
        case 1: _t->zoomIn(); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->turnRight(); break;
        case 4: _t->turnLeft(); break;
        case 5: _t->turnUp(); break;
        case 6: _t->turnDown(); break;
        case 7: _t->switchPieceT(); break;
        case 8: _t->switchPieceAngle(); break;
        case 9: _t->switchPiecePlus(); break;
        case 10: _t->switchPieceL(); break;
        case 11: _t->switchPieceZ(); break;
        case 12: _t->switchPieceP(); break;
        case 13: _t->switchPieceY(); break;
        case 14: _t->switchPieceD(); break;
        case 15: _t->switchPieceG(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Interface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Interface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Interface,
      qt_meta_data_Interface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Interface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Interface))
        return static_cast<void*>(const_cast< Interface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
