/****************************************************************************
** Meta object code from reading C++ file 'playlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../playlistmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistmodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13PlaylistModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13PlaylistModelE = QtMocHelpers::stringData(
    "PlaylistModel",
    "currentIndexChanged",
    "",
    "countChanged",
    "addItem",
    "url",
    "removeItem",
    "index",
    "count",
    "getUrl",
    "next",
    "previous",
    "currentIndex"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13PlaylistModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    3 /* Public */,
       3,    0,   63,    2, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   64,    2, 0x02,    5 /* Public */,
       6,    1,   67,    2, 0x02,    7 /* Public */,
       8,    0,   70,    2, 0x102,    9 /* Public | MethodIsConst  */,
       9,    1,   71,    2, 0x102,   10 /* Public | MethodIsConst  */,
      10,    0,   74,    2, 0x02,   12 /* Public */,
      11,    0,   75,    2, 0x02,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      12, QMetaType::Int, 0x00015103, uint(0), 0,
       8, QMetaType::Int, 0x00015001, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlaylistModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QStringListModel::staticMetaObject>(),
    qt_meta_stringdata_ZN13PlaylistModelE.offsetsAndSizes,
    qt_meta_data_ZN13PlaylistModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13PlaylistModelE_t,
        // property 'currentIndex'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'count'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlaylistModel, std::true_type>,
        // method 'currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'countChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'removeItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'count'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getUrl'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlaylistModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PlaylistModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentIndexChanged(); break;
        case 1: _t->countChanged(); break;
        case 2: _t->addItem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->removeItem((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getUrl((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->next(); break;
        case 7: _t->previous(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (PlaylistModel::*)();
            if (_q_method_type _q_method = &PlaylistModel::currentIndexChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (PlaylistModel::*)();
            if (_q_method_type _q_method = &PlaylistModel::countChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->count(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *PlaylistModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13PlaylistModelE.stringdata0))
        return static_cast<void*>(this);
    return QStringListModel::qt_metacast(_clname);
}

int PlaylistModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStringListModel::qt_metacall(_c, _id, _a);
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
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PlaylistModel::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlaylistModel::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
