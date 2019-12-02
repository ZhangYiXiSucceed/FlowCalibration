/****************************************************************************
** Meta object code from reading C++ file 'FCParameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowCalibration/FCParameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FCParameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FCParameter_t {
    QByteArrayData data[16];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FCParameter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FCParameter_t qt_meta_stringdata_FCParameter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FCParameter"
QT_MOC_LITERAL(1, 12, 11), // "ShowMessage"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "uint16_t"
QT_MOC_LITERAL(4, 34, 17), // "ReadLinearCalPara"
QT_MOC_LITERAL(5, 52, 18), // "WriteLinearCalPara"
QT_MOC_LITERAL(6, 71, 14), // "QVector<float>"
QT_MOC_LITERAL(7, 86, 30), // "SendNullDriftCalibrationSignal"
QT_MOC_LITERAL(8, 117, 4), // "Read"
QT_MOC_LITERAL(9, 122, 5), // "Write"
QT_MOC_LITERAL(10, 128, 16), // "RecLinearCalPara"
QT_MOC_LITERAL(11, 145, 20), // "WriteCalibrationPara"
QT_MOC_LITERAL(12, 166, 13), // "CopySpeedData"
QT_MOC_LITERAL(13, 180, 12), // "CopyParaData"
QT_MOC_LITERAL(14, 193, 20), // "NullDriftCalibration"
QT_MOC_LITERAL(15, 214, 18) // "RecCalibrationInfo"

    },
    "FCParameter\0ShowMessage\0\0uint16_t\0"
    "ReadLinearCalPara\0WriteLinearCalPara\0"
    "QVector<float>\0SendNullDriftCalibrationSignal\0"
    "Read\0Write\0RecLinearCalPara\0"
    "WriteCalibrationPara\0CopySpeedData\0"
    "CopyParaData\0NullDriftCalibration\0"
    "RecCalibrationInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FCParameter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       4,    0,   79,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      11,    1,   91,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FCParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FCParameter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 1: _t->ReadLinearCalPara(); break;
        case 2: _t->WriteLinearCalPara((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 3: _t->SendNullDriftCalibrationSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Read(); break;
        case 5: _t->Write(); break;
        case 6: _t->RecLinearCalPara((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 7: _t->WriteCalibrationPara((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->CopySpeedData(); break;
        case 9: _t->CopyParaData(); break;
        case 10: _t->NullDriftCalibration(); break;
        case 11: _t->RecCalibrationInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FCParameter::*)(QString , uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCParameter::ShowMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FCParameter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCParameter::ReadLinearCalPara)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FCParameter::*)(QVector<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCParameter::WriteLinearCalPara)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FCParameter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCParameter::SendNullDriftCalibrationSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FCParameter::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FCParameter.data,
    qt_meta_data_FCParameter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FCParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FCParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FCParameter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FCParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FCParameter::ShowMessage(QString _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FCParameter::ReadLinearCalPara()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FCParameter::WriteLinearCalPara(QVector<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FCParameter::SendNullDriftCalibrationSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
