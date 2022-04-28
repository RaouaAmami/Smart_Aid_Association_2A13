/********************************************************************************
** Form generated from reading UI file 'malek.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALEK_H
#define UI_MALEK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Malek
{
public:
    QPushButton *logout;
    QLabel *label_date;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_libelle;
    QTableView *event;
    QLabel *label_type;
    QLabel *label_3;
    QLineEdit *line_id;
    QLineEdit *line_libelle;
    QLineEdit *line_lieu;
    QComboBox *comboType;
    QDateEdit *dateEdit;
    QComboBox *combotri;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_pdf;
    QLineEdit *line_recherche;
    QPushButton *pushButton_modif;
    QPushButton *pushButton_supp;
    QPushButton *stat;

    void setupUi(QDialog *Malek)
    {
        if (Malek->objectName().isEmpty())
            Malek->setObjectName(QStringLiteral("Malek"));
        Malek->resize(1063, 668);
        logout = new QPushButton(Malek);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(940, 20, 75, 23));
        label_date = new QLabel(Malek);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setGeometry(QRect(40, 320, 56, 16));
        label_date->setStyleSheet(QLatin1String("background-color: rgb(214, 209, 192);\n"
"font: 75 9pt \"MS Shell Dlg 2\";"));
        label_4 = new QLabel(Malek);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 56, 16));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(214, 209, 192);\n"
"font: 75 9pt \"MS Shell Dlg 2\";"));
        pushButton = new QPushButton(Malek);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 100, 221, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(249, 183, 255);"));
        label_libelle = new QLabel(Malek);
        label_libelle->setObjectName(QStringLiteral("label_libelle"));
        label_libelle->setGeometry(QRect(45, 196, 51, 20));
        label_libelle->setStyleSheet(QLatin1String("background-color: rgb(214, 209, 192);\n"
"font: 75 9pt \"MS Shell Dlg 2\";"));
        event = new QTableView(Malek);
        event->setObjectName(QStringLiteral("event"));
        event->setGeometry(QRect(240, 350, 791, 261));
        label_type = new QLabel(Malek);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setGeometry(QRect(40, 280, 56, 16));
        label_type->setStyleSheet(QLatin1String("background-color: rgb(214, 209, 192);\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
""));
        label_3 = new QLabel(Malek);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 240, 56, 16));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(214, 209, 192);\n"
"font: 75 9pt \"MS Shell Dlg 2\";"));
        line_id = new QLineEdit(Malek);
        line_id->setObjectName(QStringLiteral("line_id"));
        line_id->setGeometry(QRect(130, 160, 113, 20));
        line_libelle = new QLineEdit(Malek);
        line_libelle->setObjectName(QStringLiteral("line_libelle"));
        line_libelle->setGeometry(QRect(160, 200, 113, 20));
        line_lieu = new QLineEdit(Malek);
        line_lieu->setObjectName(QStringLiteral("line_lieu"));
        line_lieu->setGeometry(QRect(160, 240, 113, 20));
        comboType = new QComboBox(Malek);
        comboType->setObjectName(QStringLiteral("comboType"));
        comboType->setGeometry(QRect(151, 280, 131, 22));
        dateEdit = new QDateEdit(Malek);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 320, 110, 22));
        combotri = new QComboBox(Malek);
        combotri->setObjectName(QStringLiteral("combotri"));
        combotri->setGeometry(QRect(380, 290, 73, 22));
        label_10 = new QLabel(Malek);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(555, 280, 91, 20));
        label_11 = new QLabel(Malek);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 290, 81, 16));
        pushButton_2 = new QPushButton(Malek);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(910, 220, 93, 28));
        pushButton_pdf = new QPushButton(Malek);
        pushButton_pdf->setObjectName(QStringLiteral("pushButton_pdf"));
        pushButton_pdf->setGeometry(QRect(320, 630, 221, 28));
        line_recherche = new QLineEdit(Malek);
        line_recherche->setObjectName(QStringLiteral("line_recherche"));
        line_recherche->setGeometry(QRect(660, 280, 113, 22));
        pushButton_modif = new QPushButton(Malek);
        pushButton_modif->setObjectName(QStringLiteral("pushButton_modif"));
        pushButton_modif->setGeometry(QRect(10, 400, 221, 31));
        pushButton_modif->setStyleSheet(QLatin1String("\n"
"background-color: rgb(251, 116, 255);"));
        pushButton_supp = new QPushButton(Malek);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(60, 500, 93, 28));
        stat = new QPushButton(Malek);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(800, 630, 93, 28));

        retranslateUi(Malek);

        QMetaObject::connectSlotsByName(Malek);
    } // setupUi

    void retranslateUi(QDialog *Malek)
    {
        Malek->setWindowTitle(QApplication::translate("Malek", "Dialog", Q_NULLPTR));
        logout->setText(QApplication::translate("Malek", "logout", Q_NULLPTR));
        label_date->setText(QApplication::translate("Malek", "DATE", Q_NULLPTR));
        label_4->setText(QApplication::translate("Malek", "ID", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Malek", "ajouter un evenement", Q_NULLPTR));
        label_libelle->setText(QApplication::translate("Malek", "LIBELLE", Q_NULLPTR));
        label_type->setText(QApplication::translate("Malek", "TYPE ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Malek", "LIEU", Q_NULLPTR));
        label_10->setText(QApplication::translate("Malek", "RECHERCHER :", Q_NULLPTR));
        label_11->setText(QApplication::translate("Malek", "TRIER PAR :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Malek", "calendrier", Q_NULLPTR));
        pushButton_pdf->setText(QApplication::translate("Malek", "afficher le tableau en pdf", Q_NULLPTR));
        pushButton_modif->setText(QApplication::translate("Malek", "MISE A JOUR D'UN EVENEMENT ", Q_NULLPTR));
        pushButton_supp->setText(QApplication::translate("Malek", "supprimer", Q_NULLPTR));
        stat->setText(QApplication::translate("Malek", "stat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Malek: public Ui_Malek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALEK_H
