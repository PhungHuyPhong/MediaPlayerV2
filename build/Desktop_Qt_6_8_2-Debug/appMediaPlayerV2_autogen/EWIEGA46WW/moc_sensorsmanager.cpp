/****************************************************************************
** Meta object code from reading C++ file 'sensorsmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../sensorsmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensorsmanager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14SensorsManagerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14SensorsManagerE = QtMocHelpers::stringData(
    "SensorsManager",
    "lightChanged",
    "",
    "proximityChanged",
    "accelerometerChanged",
    "gestureDetectedChanged",
    "temperatureChanged",
    "setTempSensorActive",
    "active",
    "setLightSensorActive",
    "setGestureSensorActive",
    "ambientBrightness",
    "isNear",
    "acceleration",
    "QVariantMap",
    "gestureDetected",
    "temperature"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14SensorsManagerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    6 /* Public */,
       3,    0,   63,    2, 0x06,    7 /* Public */,
       4,    0,   64,    2, 0x06,    8 /* Public */,
       5,    0,   65,    2, 0x06,    9 /* Public */,
       6,    0,   66,    2, 0x06,   10 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   67,    2, 0x02,   11 /* Public */,
       9,    1,   70,    2, 0x02,   13 /* Public */,
      10,    1,   73,    2, 0x02,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,

 // properties: name, type, flags, notifyId, revision
      11, QMetaType::Int, 0x00015001, uint(0), 0,
      12, QMetaType::Bool, 0x00015001, uint(1), 0,
      13, 0x80000000 | 14, 0x00015009, uint(2), 0,
      15, QMetaType::QString, 0x00015001, uint(3), 0,
      16, QMetaType::Float, 0x00015001, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SensorsManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14SensorsManagerE.offsetsAndSizes,
    qt_meta_data_ZN14SensorsManagerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14SensorsManagerE_t,
        // property 'ambientBrightness'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'isNear'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'acceleration'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // property 'gestureDetected'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'temperature'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SensorsManager, std::true_type>,
        // method 'lightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'proximityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'accelerometerChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gestureDetectedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'temperatureChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTempSensorActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setLightSensorActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setGestureSensorActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void SensorsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SensorsManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->lightChanged(); break;
        case 1: _t->proximityChanged(); break;
        case 2: _t->accelerometerChanged(); break;
        case 3: _t->gestureDetectedChanged(); break;
        case 4: _t->temperatureChanged(); break;
        case 5: _t->setTempSensorActive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->setLightSensorActive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->setGestureSensorActive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (SensorsManager::*)();
            if (_q_method_type _q_method = &SensorsManager::lightChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (SensorsManager::*)();
            if (_q_method_type _q_method = &SensorsManager::proximityChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (SensorsManager::*)();
            if (_q_method_type _q_method = &SensorsManager::accelerometerChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (SensorsManager::*)();
            if (_q_method_type _q_method = &SensorsManager::gestureDetectedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (SensorsManager::*)();
            if (_q_method_type _q_method = &SensorsManager::temperatureChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->ambientBrightness(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isNear(); break;
        case 2: *reinterpret_cast< QVariantMap*>(_v) = _t->acceleration(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->gestureDetected(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->temperature(); break;
        default: break;
        }
    }
}

const QMetaObject *SensorsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SensorsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14SensorsManagerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SensorsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SensorsManager::lightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SensorsManager::proximityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SensorsManager::accelerometerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SensorsManager::gestureDetectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SensorsManager::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
