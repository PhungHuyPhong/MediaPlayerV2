/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mediaplayer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11MediaPlayerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN11MediaPlayerE = QtMocHelpers::stringData(
    "MediaPlayer",
    "playbackStateChanged",
    "",
    "positionChanged",
    "durationChanged",
    "volumeChanged",
    "currentTrackChanged",
    "playingChanged",
    "play",
    "pause",
    "stop",
    "playPause",
    "next",
    "previous",
    "playbackState",
    "playing",
    "position",
    "duration",
    "volume",
    "currentTrackTitle",
    "currentTrackArtist",
    "canGoPrevious",
    "canGoNext"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN11MediaPlayerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       9,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,   10 /* Public */,
       3,    0,   87,    2, 0x06,   11 /* Public */,
       4,    0,   88,    2, 0x06,   12 /* Public */,
       5,    0,   89,    2, 0x06,   13 /* Public */,
       6,    0,   90,    2, 0x06,   14 /* Public */,
       7,    0,   91,    2, 0x06,   15 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   92,    2, 0x02,   16 /* Public */,
       9,    0,   93,    2, 0x02,   17 /* Public */,
      10,    0,   94,    2, 0x02,   18 /* Public */,
      11,    0,   95,    2, 0x02,   19 /* Public */,
      12,    0,   96,    2, 0x02,   20 /* Public */,
      13,    0,   97,    2, 0x02,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      14, QMetaType::QString, 0x00015001, uint(0), 0,
      15, QMetaType::Bool, 0x00015001, uint(5), 0,
      16, QMetaType::Int, 0x00015103, uint(1), 0,
      17, QMetaType::Int, 0x00015001, uint(2), 0,
      18, QMetaType::Int, 0x00015103, uint(3), 0,
      19, QMetaType::QString, 0x00015001, uint(4), 0,
      20, QMetaType::QString, 0x00015001, uint(4), 0,
      21, QMetaType::Bool, 0x00015001, uint(4), 0,
      22, QMetaType::Bool, 0x00015001, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MediaPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN11MediaPlayerE.offsetsAndSizes,
    qt_meta_data_ZN11MediaPlayerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN11MediaPlayerE_t,
        // property 'playbackState'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'playing'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'position'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'duration'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'volume'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'currentTrackTitle'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentTrackArtist'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'canGoPrevious'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'canGoNext'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MediaPlayer, std::true_type>,
        // method 'playbackStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'positionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentTrackChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MediaPlayer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->playbackStateChanged(); break;
        case 1: _t->positionChanged(); break;
        case 2: _t->durationChanged(); break;
        case 3: _t->volumeChanged(); break;
        case 4: _t->currentTrackChanged(); break;
        case 5: _t->playingChanged(); break;
        case 6: _t->play(); break;
        case 7: _t->pause(); break;
        case 8: _t->stop(); break;
        case 9: _t->playPause(); break;
        case 10: _t->next(); break;
        case 11: _t->previous(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::playbackStateChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::positionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::durationChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::volumeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::currentTrackChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (MediaPlayer::*)();
            if (_q_method_type _q_method = &MediaPlayer::playingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->playbackState(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->playing(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->position(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->duration(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->volume(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->currentTrackTitle(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->currentTrackArtist(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->canGoPrevious(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->canGoNext(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setPosition(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setVolume(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN11MediaPlayerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MediaPlayer::playbackStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaPlayer::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaPlayer::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MediaPlayer::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MediaPlayer::currentTrackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MediaPlayer::playingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
