/****************************************************************************
** Meta object code from reading C++ file 'fares.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Login/fares.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fares.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Fares_t {
    QByteArrayData data[20];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fares_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fares_t qt_meta_stringdata_Fares = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Fares"
QT_MOC_LITERAL(1, 6, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 55, 22), // "on_tableView_activated"
QT_MOC_LITERAL(5, 78, 5), // "index"
QT_MOC_LITERAL(6, 84, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(7, 108, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 130, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(9, 157, 4), // "arg1"
QT_MOC_LITERAL(10, 162, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(11, 186, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(12, 210, 35), // "on_lineEdit_4_cursorPositionC..."
QT_MOC_LITERAL(13, 246, 4), // "arg2"
QT_MOC_LITERAL(14, 251, 25), // "on_pushButton_pdf_clicked"
QT_MOC_LITERAL(15, 277, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(16, 301, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(17, 325, 12), // "update_label"
QT_MOC_LITERAL(18, 338, 17), // "on_Logout_clicked"
QT_MOC_LITERAL(19, 356, 17) // "on_logout_clicked"

    },
    "Fares\0on_pushButton_4_clicked\0\0"
    "on_pushButton_3_clicked\0on_tableView_activated\0"
    "index\0on_pushButton_5_clicked\0"
    "on_pushButton_clicked\0on_checkBox_2_stateChanged\0"
    "arg1\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0"
    "on_lineEdit_4_cursorPositionChanged\0"
    "arg2\0on_pushButton_pdf_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_8_clicked\0"
    "update_label\0on_Logout_clicked\0"
    "on_logout_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fares[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    2,  101,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Fares::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fares *_t = static_cast<Fares *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        //case 5: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_7_clicked(); break;
        case 8: _t->on_lineEdit_4_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_pushButton_pdf_clicked(); break;
        //case 10: _t->on_pushButton_2_clicked(); break;
        //case 11: _t->on_pushButton_8_clicked(); break;
        case 12: _t->update_label(); break;
        //case 13: _t->on_Logout_clicked(); break;
        case 14: _t->on_logout_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Fares::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Fares.data,
      qt_meta_data_Fares,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Fares::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fares::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Fares.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Fares::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
