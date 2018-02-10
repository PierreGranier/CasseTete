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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      24,   19,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,
      64,   10,   10,   10, 0x08,
      74,   10,   10,   10, 0x08,
      86,   10,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,
     106,   10,   10,   10, 0x08,
     117,   10,   10,   10, 0x08,
     132,   10,   10,   10, 0x08,
     151,   10,   10,   10, 0x08,
     169,   10,   10,   10, 0x08,
     184,   10,   10,   10, 0x08,
     199,   10,   10,   10, 0x08,
     214,   10,   10,   10, 0x08,
     229,   10,   10,   10, 0x08,
     244,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Interface[] = {
    "Interface\0\0solve()\0item\0"
    "itemSelected(QListWidgetItem*)\0zoomIn()\0"
    "zoomOut()\0turnRight()\0turnLeft()\0"
    "turnUp()\0turnDown()\0switchPieceT()\0"
    "switchPieceAngle()\0switchPiecePlus()\0"
    "switchPieceL()\0switchPieceZ()\0"
    "switchPieceP()\0switchPieceY()\0"
    "switchPieceD()\0switchPieceG()\0"
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Interface *_t = static_cast<Interface *>(_o);
        switch (_id) {
        case 0: _t->solve(); break;
        case 1: _t->itemSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->turnRight(); break;
        case 5: _t->turnLeft(); break;
        case 6: _t->turnUp(); break;
        case 7: _t->turnDown(); break;
        case 8: _t->switchPieceT(); break;
        case 9: _t->switchPieceAngle(); break;
        case 10: _t->switchPiecePlus(); break;
        case 11: _t->switchPieceL(); break;
        case 12: _t->switchPieceZ(); break;
        case 13: _t->switchPieceP(); break;
        case 14: _t->switchPieceY(); break;
        case 15: _t->switchPieceD(); break;
        case 16: _t->switchPieceG(); break;
        default: ;
        }
    }
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
