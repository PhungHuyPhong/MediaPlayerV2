/****************************************************************************
** Meta object code from reading C++ file 'bluetoothmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../bluetoothmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN16BluetoothManagerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN16BluetoothManagerE = QtMocHelpers::stringData(
    "BluetoothManager",
    "scanningChanged",
    "",
    "devicesChanged",
    "connectionChanged",
    "errorOccurred",
    "error",
    "startDiscovery",
    "stopDiscovery",
    "connectToDevice",
    "address",
    "disconnect",
    "scanning",
    "devices",
    "QVariantList",
    "connectedDevice",
    "QVariantMap"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN16BluetoothManagerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    4 /* Public */,
       3,    0,   63,    2, 0x06,    5 /* Public */,
       4,    0,   64,    2, 0x06,    6 /* Public */,
       5,    1,   65,    2, 0x06,    7 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   68,    2, 0x02,    9 /* Public */,
       8,    0,   69,    2, 0x02,   10 /* Public */,
       9,    1,   70,    2, 0x02,   11 /* Public */,
      11,    0,   73,    2, 0x02,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      12, QMetaType::Bool, 0x00015001, uint(0), 0,
      13, 0x80000000 | 14, 0x00015009, uint(1), 0,
      15, 0x80000000 | 16, 0x00015009, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject BluetoothManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN16BluetoothManagerE.offsetsAndSizes,
    qt_meta_data_ZN16BluetoothManagerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN16BluetoothManagerE_t,
        // property 'scanning'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'devices'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'connectedDevice'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BluetoothManager, std::true_type>,
        // method 'scanningChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'devicesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startDiscovery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopDiscovery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectToDevice'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'disconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BluetoothManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->scanningChanged(); break;
        case 1: _t->devicesChanged(); break;
        case 2: _t->connectionChanged(); break;
        case 3: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->startDiscovery(); break;
        case 5: _t->stopDiscovery(); break;
        case 6: { bool _r = _t->connectToDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->disconnect(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (BluetoothManager::*)();
            if (_q_method_type _q_method = &BluetoothManager::scanningChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (BluetoothManager::*)();
            if (_q_method_type _q_method = &BluetoothManager::devicesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (BluetoothManager::*)();
            if (_q_method_type _q_method = &BluetoothManager::connectionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (BluetoothManager::*)(const QString & );
            if (_q_method_type _q_method = &BluetoothManager::errorOccurred; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isScanning(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->devices(); break;
        case 2: *reinterpret_cast< QVariantMap*>(_v) = _t->connectedDevice(); break;
        default: break;
        }
    }
}

const QMetaObject *BluetoothManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN16BluetoothManagerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluetoothManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void BluetoothManager::scanningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BluetoothManager::devicesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BluetoothManager::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BluetoothManager::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
