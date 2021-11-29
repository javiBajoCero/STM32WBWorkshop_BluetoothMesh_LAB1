/****************************************************************************
** Meta object code from reading C++ file 'javible.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BLE_test/javible.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'javible.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_javiBLE_t {
    QByteArrayData data[56];
    char stringdata0[1037];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_javiBLE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_javiBLE_t qt_meta_stringdata_javiBLE = {
    {
QT_MOC_LITERAL(0, 0, 7), // "javiBLE"
QT_MOC_LITERAL(1, 8, 19), // "bledevicediscovered"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 4), // "addr"
QT_MOC_LITERAL(5, 39, 20), // "bleservicediscovered"
QT_MOC_LITERAL(6, 60, 27), // "blecharacteristicdiscovered"
QT_MOC_LITERAL(7, 88, 4), // "uuid"
QT_MOC_LITERAL(8, 93, 5), // "flags"
QT_MOC_LITERAL(9, 99, 6), // "qdebug"
QT_MOC_LITERAL(10, 106, 4), // "data"
QT_MOC_LITERAL(11, 111, 16), // "bledeviceupdated"
QT_MOC_LITERAL(12, 128, 4), // "rssi"
QT_MOC_LITERAL(13, 133, 8), // "manufact"
QT_MOC_LITERAL(14, 142, 27), // "deviceDiscoveryCacelledSLOT"
QT_MOC_LITERAL(15, 170, 20), // "deviceDiscoveredSLOT"
QT_MOC_LITERAL(16, 191, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(17, 212, 6), // "device"
QT_MOC_LITERAL(18, 219, 17), // "deviceUpdatedSLOT"
QT_MOC_LITERAL(19, 237, 28), // "QBluetoothDeviceInfo::Fields"
QT_MOC_LITERAL(20, 266, 13), // "updatedFields"
QT_MOC_LITERAL(21, 280, 18), // "discoveryerrorSLOT"
QT_MOC_LITERAL(22, 299, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(23, 337, 5), // "error"
QT_MOC_LITERAL(24, 343, 21), // "discoveryfinishedSLOT"
QT_MOC_LITERAL(25, 365, 15), // "controlConected"
QT_MOC_LITERAL(26, 381, 24), // "controlConnectionUpdated"
QT_MOC_LITERAL(27, 406, 30), // "QLowEnergyConnectionParameters"
QT_MOC_LITERAL(28, 437, 10), // "parameters"
QT_MOC_LITERAL(29, 448, 18), // "controlDisonnected"
QT_MOC_LITERAL(30, 467, 24), // "controlDiscoveryFinished"
QT_MOC_LITERAL(31, 492, 12), // "controlError"
QT_MOC_LITERAL(32, 505, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(33, 533, 24), // "controlServiceDiscovered"
QT_MOC_LITERAL(34, 558, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(35, 573, 19), // "controlStateChanged"
QT_MOC_LITERAL(36, 593, 37), // "QLowEnergyController::Control..."
QT_MOC_LITERAL(37, 631, 5), // "state"
QT_MOC_LITERAL(38, 637, 19), // "serviceStateChanged"
QT_MOC_LITERAL(39, 657, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(40, 689, 8), // "newstate"
QT_MOC_LITERAL(41, 698, 28), // "serviceCharacteristicChanged"
QT_MOC_LITERAL(42, 727, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(43, 752, 4), // "info"
QT_MOC_LITERAL(44, 757, 5), // "value"
QT_MOC_LITERAL(45, 763, 25), // "serviceCharacteristicRead"
QT_MOC_LITERAL(46, 789, 28), // "serviceCharacteristicWritten"
QT_MOC_LITERAL(47, 818, 21), // "serviceDescriptorRead"
QT_MOC_LITERAL(48, 840, 20), // "QLowEnergyDescriptor"
QT_MOC_LITERAL(49, 861, 24), // "serviceDescriptorWritten"
QT_MOC_LITERAL(50, 886, 12), // "serviceError"
QT_MOC_LITERAL(51, 899, 31), // "QLowEnergyService::ServiceError"
QT_MOC_LITERAL(52, 931, 7), // "scanBLE"
QT_MOC_LITERAL(53, 939, 29), // "connnectAndScanforServicesBLE"
QT_MOC_LITERAL(54, 969, 42), // "connectServiceAndScanforchara..."
QT_MOC_LITERAL(55, 1012, 24) // "notifythischaracteristic"

    },
    "javiBLE\0bledevicediscovered\0\0name\0"
    "addr\0bleservicediscovered\0"
    "blecharacteristicdiscovered\0uuid\0flags\0"
    "qdebug\0data\0bledeviceupdated\0rssi\0"
    "manufact\0deviceDiscoveryCacelledSLOT\0"
    "deviceDiscoveredSLOT\0QBluetoothDeviceInfo\0"
    "device\0deviceUpdatedSLOT\0"
    "QBluetoothDeviceInfo::Fields\0updatedFields\0"
    "discoveryerrorSLOT\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0discoveryfinishedSLOT\0controlConected\0"
    "controlConnectionUpdated\0"
    "QLowEnergyConnectionParameters\0"
    "parameters\0controlDisonnected\0"
    "controlDiscoveryFinished\0controlError\0"
    "QLowEnergyController::Error\0"
    "controlServiceDiscovered\0QBluetoothUuid\0"
    "controlStateChanged\0"
    "QLowEnergyController::ControllerState\0"
    "state\0serviceStateChanged\0"
    "QLowEnergyService::ServiceState\0"
    "newstate\0serviceCharacteristicChanged\0"
    "QLowEnergyCharacteristic\0info\0value\0"
    "serviceCharacteristicRead\0"
    "serviceCharacteristicWritten\0"
    "serviceDescriptorRead\0QLowEnergyDescriptor\0"
    "serviceDescriptorWritten\0serviceError\0"
    "QLowEnergyService::ServiceError\0scanBLE\0"
    "connnectAndScanforServicesBLE\0"
    "connectServiceAndScanforcharacteristicsBLE\0"
    "notifythischaracteristic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_javiBLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  154,    2, 0x06 /* Public */,
       5,    1,  159,    2, 0x06 /* Public */,
       6,    2,  162,    2, 0x06 /* Public */,
       9,    1,  167,    2, 0x06 /* Public */,
      11,    3,  170,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  177,    2, 0x0a /* Public */,
      15,    1,  178,    2, 0x0a /* Public */,
      18,    2,  181,    2, 0x0a /* Public */,
      21,    1,  186,    2, 0x0a /* Public */,
      24,    0,  189,    2, 0x0a /* Public */,
      25,    0,  190,    2, 0x0a /* Public */,
      26,    1,  191,    2, 0x0a /* Public */,
      29,    0,  194,    2, 0x0a /* Public */,
      30,    0,  195,    2, 0x0a /* Public */,
      31,    1,  196,    2, 0x0a /* Public */,
      33,    1,  199,    2, 0x0a /* Public */,
      35,    1,  202,    2, 0x0a /* Public */,
      38,    1,  205,    2, 0x0a /* Public */,
      41,    2,  208,    2, 0x0a /* Public */,
      45,    2,  213,    2, 0x0a /* Public */,
      46,    2,  218,    2, 0x0a /* Public */,
      47,    2,  223,    2, 0x0a /* Public */,
      49,    2,  228,    2, 0x0a /* Public */,
      50,    1,  233,    2, 0x0a /* Public */,
      52,    0,  236,    2, 0x0a /* Public */,
      53,    1,  237,    2, 0x0a /* Public */,
      54,    1,  240,    2, 0x0a /* Public */,
      55,    1,  243,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    7,    8,
    QMetaType::Void, QMetaType::QVariant,   10,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    4,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 19,   17,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   23,
    QMetaType::Void, 0x80000000 | 34,    7,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void, 0x80000000 | 42, QMetaType::QByteArray,   43,   44,
    QMetaType::Void, 0x80000000 | 42, QMetaType::QByteArray,   43,   44,
    QMetaType::Void, 0x80000000 | 42, QMetaType::QByteArray,   43,   44,
    QMetaType::Void, 0x80000000 | 48, QMetaType::QByteArray,   43,   44,
    QMetaType::Void, 0x80000000 | 48, QMetaType::QByteArray,   43,   44,
    QMetaType::Void, 0x80000000 | 51,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void javiBLE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<javiBLE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bledevicediscovered((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->bleservicediscovered((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->blecharacteristicdiscovered((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->qdebug((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 4: _t->bledeviceupdated((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 5: _t->deviceDiscoveryCacelledSLOT(); break;
        case 6: _t->deviceDiscoveredSLOT((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 7: _t->deviceUpdatedSLOT((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1])),(*reinterpret_cast< QBluetoothDeviceInfo::Fields(*)>(_a[2]))); break;
        case 8: _t->discoveryerrorSLOT((*reinterpret_cast< const QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 9: _t->discoveryfinishedSLOT(); break;
        case 10: _t->controlConected(); break;
        case 11: _t->controlConnectionUpdated((*reinterpret_cast< const QLowEnergyConnectionParameters(*)>(_a[1]))); break;
        case 12: _t->controlDisonnected(); break;
        case 13: _t->controlDiscoveryFinished(); break;
        case 14: _t->controlError((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 15: _t->controlServiceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 16: _t->controlStateChanged((*reinterpret_cast< QLowEnergyController::ControllerState(*)>(_a[1]))); break;
        case 17: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 18: _t->serviceCharacteristicChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 19: _t->serviceCharacteristicRead((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 20: _t->serviceCharacteristicWritten((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 21: _t->serviceDescriptorRead((*reinterpret_cast< const QLowEnergyDescriptor(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 22: _t->serviceDescriptorWritten((*reinterpret_cast< const QLowEnergyDescriptor(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 23: _t->serviceError((*reinterpret_cast< QLowEnergyService::ServiceError(*)>(_a[1]))); break;
        case 24: _t->scanBLE(); break;
        case 25: _t->connnectAndScanforServicesBLE((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->connectServiceAndScanforcharacteristicsBLE((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->notifythischaracteristic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::ControllerState >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyDescriptor >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyDescriptor >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (javiBLE::*)(QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&javiBLE::bledevicediscovered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (javiBLE::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&javiBLE::bleservicediscovered)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (javiBLE::*)(QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&javiBLE::blecharacteristicdiscovered)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (javiBLE::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&javiBLE::qdebug)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (javiBLE::*)(QVariant , QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&javiBLE::bledeviceupdated)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject javiBLE::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_javiBLE.data,
    qt_meta_data_javiBLE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *javiBLE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *javiBLE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_javiBLE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int javiBLE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void javiBLE::bledevicediscovered(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void javiBLE::bleservicediscovered(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void javiBLE::blecharacteristicdiscovered(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void javiBLE::qdebug(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void javiBLE::bledeviceupdated(QVariant _t1, QVariant _t2, QVariant _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
