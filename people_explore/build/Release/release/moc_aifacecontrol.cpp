/****************************************************************************
** Meta object code from reading C++ file 'aifacecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../aifacecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aifacecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AIFaceControl_t {
    QByteArrayData data[4];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AIFaceControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AIFaceControl_t qt_meta_stringdata_AIFaceControl = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AIFaceControl"
QT_MOC_LITERAL(1, 14, 13), // "sendAiFaceMsg"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3) // "msg"

    },
    "AIFaceControl\0sendAiFaceMsg\0\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AIFaceControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void AIFaceControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AIFaceControl *_t = static_cast<AIFaceControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAiFaceMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AIFaceControl::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AIFaceControl::sendAiFaceMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AIFaceControl::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AIFaceControl.data,
      qt_meta_data_AIFaceControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AIFaceControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AIFaceControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AIFaceControl.stringdata0))
        return static_cast<void*>(const_cast< AIFaceControl*>(this));
    return QThread::qt_metacast(_clname);
}

int AIFaceControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void AIFaceControl::sendAiFaceMsg(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
