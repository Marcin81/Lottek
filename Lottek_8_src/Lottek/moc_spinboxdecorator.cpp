/****************************************************************************
** Meta object code from reading C++ file 'spinboxdecorator.h'
**
** Created: Fri Nov 6 16:55:26 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com

*****************************************************************************/

#include "spinboxdecorator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spinboxdecorator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SpinBoxDecorator[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   33,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpinBoxDecorator[] = {
    "SpinBoxDecorator\0\0valueChanged()\0value\0"
    "serviceValueChanged(int)\0"
};

const QMetaObject SpinBoxDecorator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SpinBoxDecorator,
      qt_meta_data_SpinBoxDecorator, 0 }
};

const QMetaObject *SpinBoxDecorator::metaObject() const
{
    return &staticMetaObject;
}

void *SpinBoxDecorator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpinBoxDecorator))
        return static_cast<void*>(const_cast< SpinBoxDecorator*>(this));
    if (!strcmp(_clname, "boost::noncopyable"))
        return static_cast< boost::noncopyable*>(const_cast< SpinBoxDecorator*>(this));
    return QObject::qt_metacast(_clname);
}

int SpinBoxDecorator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged(); break;
        case 1: serviceValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SpinBoxDecorator::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
