/****************************************************************************
** Meta object code from reading C++ file 'chefprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Login/chefprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chefprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChefProtocol_t {
    QByteArrayData data[16];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChefProtocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChefProtocol_t qt_meta_stringdata_ChefProtocol = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ChefProtocol"
QT_MOC_LITERAL(1, 13, 29), // "on_pushButton_logout1_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 18), // "on_Ajouter_clicked"
QT_MOC_LITERAL(4, 63, 19), // "on_afficher_clicked"
QT_MOC_LITERAL(5, 83, 20), // "on_supprimer_clicked"
QT_MOC_LITERAL(6, 104, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 128, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(8, 151, 4), // "arg1"
QT_MOC_LITERAL(9, 156, 28), // "on_line_recherche_textEdited"
QT_MOC_LITERAL(10, 185, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(11, 217, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 239, 8), // "sendMail"
QT_MOC_LITERAL(13, 248, 8), // "mailSent"
QT_MOC_LITERAL(14, 257, 18), // "on_envoyer_clicked"
QT_MOC_LITERAL(15, 276, 18) // "on_generer_clicked"

    },
    "ChefProtocol\0on_pushButton_logout1_clicked\0"
    "\0on_Ajouter_clicked\0on_afficher_clicked\0"
    "on_supprimer_clicked\0on_pushButton_3_clicked\0"
    "on_lineEdit_textEdited\0arg1\0"
    "on_line_recherche_textEdited\0"
    "on_comboBox_currentIndexChanged\0"
    "on_pushButton_clicked\0sendMail\0mailSent\0"
    "on_envoyer_clicked\0on_generer_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChefProtocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
       9,    1,   87,    2, 0x08 /* Private */,
      10,    1,   90,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChefProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChefProtocol *_t = static_cast<ChefProtocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_logout1_clicked(); break;
        case 1: _t->on_Ajouter_clicked(); break;
        case 2: _t->on_afficher_clicked(); break;
        case 3: _t->on_supprimer_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        //case 5: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_line_recherche_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        //case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->sendMail(); break;
        case 10: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_envoyer_clicked(); break;
        case 12: _t->on_generer_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ChefProtocol::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChefProtocol.data,
      qt_meta_data_ChefProtocol,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChefProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChefProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChefProtocol.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChefProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
