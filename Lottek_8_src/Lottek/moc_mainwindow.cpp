/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Nov 8 11:45:32 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com

*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      26,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   57,   11,   11, 0x09,
      89,   11,   11,   11, 0x29,
     101,   11,   11,   11, 0x09,
     135,  119,   11,   11, 0x09,
     172,  165,   11,   11, 0x09,
     241,  220,   11,   11, 0x09,
     271,   12,   11,   11, 0x09,
     300,   11,   11,   11, 0x09,
     331,  319,   11,   11, 0x09,
     346,   11,   11,   11, 0x29,
     357,   11,   11,   11, 0x09,
     377,  371,   11,   11, 0x09,
     403,  400,   11,   11, 0x09,
     441,   11,   11,   11, 0x29,
     475,  400,   11,   11, 0x09,
     506,   11,   11,   11, 0x29,
     533,   11,   11,   11, 0x09,
     549,   11,   11,   11, 0x09,
     571,   11,   11,   11, 0x09,
     583,   11,   11,   11, 0x09,
     601,   11,   11,   11, 0x09,
     621,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0title,message\0"
    "messageSignal(QString,QString)\0"
    "withShowMessage\0checkPage(bool)\0"
    "checkPage()\0cancelcheckPage()\0"
    "requestid,error\0httpRequestFinished(int,bool)\0"
    "header\0httpResponseHeaderReceived(QHttpResponseHeader)\0"
    "bytesRead,totalBytes\0httpDataReadProgress(int,int)\0"
    "messageSlot(QString,QString)\0"
    "setRandomNumbers()\0ignoreCount\0"
    "clickAdd(bool)\0clickAdd()\0clickDelete()\0"
    "state\0setCheckBoxState(bool)\0on\0"
    "showOrHideDrawingFormMenuAction(bool)\0"
    "showOrHideDrawingFormMenuAction()\0"
    "showOrHideFormMenuAction(bool)\0"
    "showOrHideFormMenuAction()\0startNewTimer()\0"
    "changeColorAndValue()\0showAbout()\0"
    "showAboutAction()\0readConfiguration()\0"
    "writeConfiguration()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: checkPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: checkPage(); break;
        case 3: cancelcheckPage(); break;
        case 4: httpRequestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: httpResponseHeaderReceived((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 6: httpDataReadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: messageSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: setRandomNumbers(); break;
        case 9: clickAdd((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: clickAdd(); break;
        case 11: clickDelete(); break;
        case 12: setCheckBoxState((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 13: showOrHideDrawingFormMenuAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: showOrHideDrawingFormMenuAction(); break;
        case 15: showOrHideFormMenuAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: showOrHideFormMenuAction(); break;
        case 17: startNewTimer(); break;
        case 18: changeColorAndValue(); break;
        case 19: showAbout(); break;
        case 20: showAboutAction(); break;
        case 21: readConfiguration(); break;
        case 22: writeConfiguration(); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
