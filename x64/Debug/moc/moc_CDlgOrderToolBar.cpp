/****************************************************************************
** Meta object code from reading C++ file 'CDlgOrderToolBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CDlgOrderToolBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CDlgOrderToolBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDlgOrderToolBar_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDlgOrderToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDlgOrderToolBar_t qt_meta_stringdata_CDlgOrderToolBar = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CDlgOrderToolBar"
QT_MOC_LITERAL(1, 17, 24), // "mbsigSentBtnCheckClicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 23), // "mbsigSentBtnEditClicked"
QT_MOC_LITERAL(4, 67, 8), // "senddata"
QT_MOC_LITERAL(5, 76, 4), // "data"
QT_MOC_LITERAL(6, 81, 22), // "mslotOnBtnCheckClicked"
QT_MOC_LITERAL(7, 104, 21) // "mslotOnBtnEditClicked"

    },
    "CDlgOrderToolBar\0mbsigSentBtnCheckClicked\0"
    "\0mbsigSentBtnEditClicked\0senddata\0"
    "data\0mslotOnBtnCheckClicked\0"
    "mslotOnBtnEditClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDlgOrderToolBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       4,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void CDlgOrderToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CDlgOrderToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mbsigSentBtnCheckClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->mbsigSentBtnEditClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->senddata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->mslotOnBtnCheckClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->mslotOnBtnEditClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CDlgOrderToolBar::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDlgOrderToolBar::mbsigSentBtnCheckClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CDlgOrderToolBar::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDlgOrderToolBar::mbsigSentBtnEditClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CDlgOrderToolBar::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDlgOrderToolBar::senddata)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDlgOrderToolBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CDlgOrderToolBar.data,
    qt_meta_data_CDlgOrderToolBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CDlgOrderToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDlgOrderToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgOrderToolBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CDlgOrderToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CDlgOrderToolBar::mbsigSentBtnCheckClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDlgOrderToolBar::mbsigSentBtnEditClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CDlgOrderToolBar::senddata(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
