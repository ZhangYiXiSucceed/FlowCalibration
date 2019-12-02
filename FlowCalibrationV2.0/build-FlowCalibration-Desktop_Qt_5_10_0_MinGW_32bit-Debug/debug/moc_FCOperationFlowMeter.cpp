/****************************************************************************
** Meta object code from reading C++ file 'FCOperationFlowmeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowCalibration/FCOperationFlowmeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FCOperationFlowmeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FCOperationFlowmeter_t {
    QByteArrayData data[32];
    char stringdata0[460];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FCOperationFlowmeter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FCOperationFlowmeter_t qt_meta_stringdata_FCOperationFlowmeter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FCOperationFlowmeter"
QT_MOC_LITERAL(1, 21, 11), // "ShowMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "uint16_t"
QT_MOC_LITERAL(4, 43, 13), // "ShowParameter"
QT_MOC_LITERAL(5, 57, 17), // "ShowNextParameter"
QT_MOC_LITERAL(6, 75, 17), // "ShowLastParameter"
QT_MOC_LITERAL(7, 93, 15), // "FindNextComport"
QT_MOC_LITERAL(8, 109, 15), // "FindLastComport"
QT_MOC_LITERAL(9, 125, 17), // "SendLinearCalPara"
QT_MOC_LITERAL(10, 143, 14), // "QVector<float>"
QT_MOC_LITERAL(11, 158, 17), // "SendCalibrationOK"
QT_MOC_LITERAL(12, 176, 14), // "ConnectComport"
QT_MOC_LITERAL(13, 191, 18), // "ConnectNextComport"
QT_MOC_LITERAL(14, 210, 18), // "ConnectLastComport"
QT_MOC_LITERAL(15, 229, 11), // "ReadRecData"
QT_MOC_LITERAL(16, 241, 15), // "ReadNextRecData"
QT_MOC_LITERAL(17, 257, 15), // "ReadLastRecData"
QT_MOC_LITERAL(18, 273, 11), // "TimerUpdate"
QT_MOC_LITERAL(19, 285, 19), // "ShowCalibrationTime"
QT_MOC_LITERAL(20, 305, 11), // "DutyCycleUp"
QT_MOC_LITERAL(21, 317, 13), // "DutyCycleDown"
QT_MOC_LITERAL(22, 331, 6), // "Switch"
QT_MOC_LITERAL(23, 338, 7), // "Measure"
QT_MOC_LITERAL(24, 346, 10), // "ClearWaves"
QT_MOC_LITERAL(25, 357, 5), // "Reset"
QT_MOC_LITERAL(26, 363, 20), // "FlowSpeedCalibration"
QT_MOC_LITERAL(27, 384, 14), // "CalculateConst"
QT_MOC_LITERAL(28, 399, 10), // "WriteConst"
QT_MOC_LITERAL(29, 410, 20), // "NullDriftCalibration"
QT_MOC_LITERAL(30, 431, 13), // "RecReadSignal"
QT_MOC_LITERAL(31, 445, 14) // "RecWriteSignal"

    },
    "FCOperationFlowmeter\0ShowMessage\0\0"
    "uint16_t\0ShowParameter\0ShowNextParameter\0"
    "ShowLastParameter\0FindNextComport\0"
    "FindLastComport\0SendLinearCalPara\0"
    "QVector<float>\0SendCalibrationOK\0"
    "ConnectComport\0ConnectNextComport\0"
    "ConnectLastComport\0ReadRecData\0"
    "ReadNextRecData\0ReadLastRecData\0"
    "TimerUpdate\0ShowCalibrationTime\0"
    "DutyCycleUp\0DutyCycleDown\0Switch\0"
    "Measure\0ClearWaves\0Reset\0FlowSpeedCalibration\0"
    "CalculateConst\0WriteConst\0"
    "NullDriftCalibration\0RecReadSignal\0"
    "RecWriteSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FCOperationFlowmeter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  154,    2, 0x06 /* Public */,
       4,    2,  159,    2, 0x06 /* Public */,
       5,    2,  164,    2, 0x06 /* Public */,
       6,    2,  169,    2, 0x06 /* Public */,
       7,    0,  174,    2, 0x06 /* Public */,
       8,    0,  175,    2, 0x06 /* Public */,
       9,    1,  176,    2, 0x06 /* Public */,
      11,    0,  179,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  180,    2, 0x08 /* Private */,
      13,    0,  181,    2, 0x08 /* Private */,
      14,    0,  182,    2, 0x08 /* Private */,
      15,    0,  183,    2, 0x08 /* Private */,
      16,    0,  184,    2, 0x08 /* Private */,
      17,    0,  185,    2, 0x08 /* Private */,
      18,    0,  186,    2, 0x08 /* Private */,
      19,    0,  187,    2, 0x08 /* Private */,
      20,    0,  188,    2, 0x08 /* Private */,
      21,    0,  189,    2, 0x08 /* Private */,
      22,    0,  190,    2, 0x08 /* Private */,
      23,    0,  191,    2, 0x08 /* Private */,
      24,    0,  192,    2, 0x08 /* Private */,
      25,    0,  193,    2, 0x08 /* Private */,
      26,    0,  194,    2, 0x08 /* Private */,
      27,    0,  195,    2, 0x08 /* Private */,
      28,    0,  196,    2, 0x08 /* Private */,
      29,    1,  197,    2, 0x08 /* Private */,
      30,    0,  200,    2, 0x08 /* Private */,
      31,    1,  201,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void FCOperationFlowmeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FCOperationFlowmeter *_t = static_cast<FCOperationFlowmeter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 1: _t->ShowParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->ShowNextParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->ShowLastParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->FindNextComport(); break;
        case 5: _t->FindLastComport(); break;
        case 6: _t->SendLinearCalPara((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 7: _t->SendCalibrationOK(); break;
        case 8: _t->ConnectComport(); break;
        case 9: _t->ConnectNextComport(); break;
        case 10: _t->ConnectLastComport(); break;
        case 11: _t->ReadRecData(); break;
        case 12: _t->ReadNextRecData(); break;
        case 13: _t->ReadLastRecData(); break;
        case 14: _t->TimerUpdate(); break;
        case 15: _t->ShowCalibrationTime(); break;
        case 16: _t->DutyCycleUp(); break;
        case 17: _t->DutyCycleDown(); break;
        case 18: _t->Switch(); break;
        case 19: _t->Measure(); break;
        case 20: _t->ClearWaves(); break;
        case 21: _t->Reset(); break;
        case 22: _t->FlowSpeedCalibration(); break;
        case 23: _t->CalculateConst(); break;
        case 24: _t->WriteConst(); break;
        case 25: _t->NullDriftCalibration((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->RecReadSignal(); break;
        case 27: _t->RecWriteSignal((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        case 27:
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
            typedef void (FCOperationFlowmeter::*_t)(QString , uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::ShowMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::ShowParameter)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::ShowNextParameter)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::ShowLastParameter)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::FindNextComport)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::FindLastComport)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)(QVector<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::SendLinearCalPara)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (FCOperationFlowmeter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FCOperationFlowmeter::SendCalibrationOK)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject FCOperationFlowmeter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FCOperationFlowmeter.data,
      qt_meta_data_FCOperationFlowmeter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FCOperationFlowmeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FCOperationFlowmeter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FCOperationFlowmeter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FCOperationFlowmeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void FCOperationFlowmeter::ShowMessage(QString _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FCOperationFlowmeter::ShowParameter(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FCOperationFlowmeter::ShowNextParameter(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FCOperationFlowmeter::ShowLastParameter(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FCOperationFlowmeter::FindNextComport()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FCOperationFlowmeter::FindLastComport()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FCOperationFlowmeter::SendLinearCalPara(QVector<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FCOperationFlowmeter::SendCalibrationOK()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
