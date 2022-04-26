/********************************************************************************
** Form generated from reading UI file 'chefprotocol.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEFPROTOCOL_H
#define UI_CHEFPROTOCOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChefProtocol
{
public:
    QLabel *label;
    QPushButton *pushButton_logout1;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *Ajouter;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Prenom;
    QLineEdit *lineEdit_CIN;
    QLineEdit *lineEdit_Role;
    QLineEdit *lineEdit_Mail;
    QWidget *tab_2;
    QLabel *label_7;
    QLineEdit *lineEdit_IDS;
    QPushButton *supprimer;
    QWidget *tab_3;
    QTableView *tableView;
    QLineEdit *line_recherche;
    QLabel *label_16;
    QComboBox *comboBox;
    QLabel *label_17;
    QWidget *tab_4;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QLineEdit *lineEdit_MID;
    QLineEdit *lineEdit_MNOM;
    QLineEdit *lineEdit_MPRENOM;
    QLineEdit *lineEdit_MROLE;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_MMAIL;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_MCIN;
    QWidget *tab_5;
    QLineEdit *lineEdit_10;
    QTextEdit *textEdit;
    QPushButton *envoyer;
    QLineEdit *lineEdit_9;
    QLabel *label_18;
    QLabel *label_19;
    QWidget *tab_7;
    QTextBrowser *textpdf;
    QPushButton *generer;

    void setupUi(QDialog *ChefProtocol)
    {
        if (ChefProtocol->objectName().isEmpty())
            ChefProtocol->setObjectName(QStringLiteral("ChefProtocol"));
        ChefProtocol->resize(644, 369);
        label = new QLabel(ChefProtocol);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 140, 141, 31));
        pushButton_logout1 = new QPushButton(ChefProtocol);
        pushButton_logout1->setObjectName(QStringLiteral("pushButton_logout1"));
        pushButton_logout1->setGeometry(QRect(560, 20, 75, 23));
        tabWidget = new QTabWidget(ChefProtocol);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 621, 271));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 47, 14));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 47, 14));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 47, 14));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 130, 47, 14));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 160, 47, 14));
        Ajouter = new QPushButton(tab);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(110, 220, 75, 23));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 160, 47, 14));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 20, 47, 14));
        lineEdit_ID = new QLineEdit(tab);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(80, 20, 113, 20));
        lineEdit_Nom = new QLineEdit(tab);
        lineEdit_Nom->setObjectName(QStringLiteral("lineEdit_Nom"));
        lineEdit_Nom->setGeometry(QRect(80, 40, 113, 20));
        lineEdit_Prenom = new QLineEdit(tab);
        lineEdit_Prenom->setObjectName(QStringLiteral("lineEdit_Prenom"));
        lineEdit_Prenom->setGeometry(QRect(80, 70, 113, 20));
        lineEdit_CIN = new QLineEdit(tab);
        lineEdit_CIN->setObjectName(QStringLiteral("lineEdit_CIN"));
        lineEdit_CIN->setGeometry(QRect(80, 100, 113, 20));
        lineEdit_Role = new QLineEdit(tab);
        lineEdit_Role->setObjectName(QStringLiteral("lineEdit_Role"));
        lineEdit_Role->setGeometry(QRect(80, 140, 113, 20));
        lineEdit_Mail = new QLineEdit(tab);
        lineEdit_Mail->setObjectName(QStringLiteral("lineEdit_Mail"));
        lineEdit_Mail->setGeometry(QRect(80, 170, 113, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 60, 47, 14));
        lineEdit_IDS = new QLineEdit(tab_2);
        lineEdit_IDS->setObjectName(QStringLiteral("lineEdit_IDS"));
        lineEdit_IDS->setGeometry(QRect(60, 60, 113, 20));
        supprimer = new QPushButton(tab_2);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(70, 110, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 421, 201));
        line_recherche = new QLineEdit(tab_3);
        line_recherche->setObjectName(QStringLiteral("line_recherche"));
        line_recherche->setGeometry(QRect(470, 100, 121, 20));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(490, 80, 91, 20));
        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(471, 160, 131, 22));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(510, 140, 47, 14));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 130, 75, 23));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 50, 47, 14));
        lineEdit_MID = new QLineEdit(tab_4);
        lineEdit_MID->setObjectName(QStringLiteral("lineEdit_MID"));
        lineEdit_MID->setGeometry(QRect(160, 50, 113, 20));
        lineEdit_MNOM = new QLineEdit(tab_4);
        lineEdit_MNOM->setObjectName(QStringLiteral("lineEdit_MNOM"));
        lineEdit_MNOM->setGeometry(QRect(160, 80, 113, 20));
        lineEdit_MPRENOM = new QLineEdit(tab_4);
        lineEdit_MPRENOM->setObjectName(QStringLiteral("lineEdit_MPRENOM"));
        lineEdit_MPRENOM->setGeometry(QRect(160, 110, 113, 20));
        lineEdit_MROLE = new QLineEdit(tab_4);
        lineEdit_MROLE->setObjectName(QStringLiteral("lineEdit_MROLE"));
        lineEdit_MROLE->setGeometry(QRect(160, 140, 113, 20));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 80, 47, 14));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 120, 47, 14));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 150, 47, 14));
        lineEdit_MMAIL = new QLineEdit(tab_4);
        lineEdit_MMAIL->setObjectName(QStringLiteral("lineEdit_MMAIL"));
        lineEdit_MMAIL->setGeometry(QRect(160, 170, 113, 20));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 180, 47, 14));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 210, 47, 14));
        lineEdit_MCIN = new QLineEdit(tab_4);
        lineEdit_MCIN->setObjectName(QStringLiteral("lineEdit_MCIN"));
        lineEdit_MCIN->setGeometry(QRect(160, 210, 113, 20));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        lineEdit_10 = new QLineEdit(tab_5);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(50, 20, 501, 20));
        textEdit = new QTextEdit(tab_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 70, 491, 171));
        envoyer = new QPushButton(tab_5);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(550, 200, 61, 21));
        lineEdit_9 = new QLineEdit(tab_5);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(50, 40, 501, 25));
        label_18 = new QLabel(tab_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 20, 41, 20));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 40, 41, 20));
        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        textpdf = new QTextBrowser(tab_7);
        textpdf->setObjectName(QStringLiteral("textpdf"));
        textpdf->setGeometry(QRect(20, 30, 491, 201));
        generer = new QPushButton(tab_7);
        generer->setObjectName(QStringLiteral("generer"));
        generer->setGeometry(QRect(520, 100, 89, 28));
        tabWidget->addTab(tab_7, QString());

        retranslateUi(ChefProtocol);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(ChefProtocol);
    } // setupUi

    void retranslateUi(QDialog *ChefProtocol)
    {
        ChefProtocol->setWindowTitle(QApplication::translate("ChefProtocol", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChefProtocol", "Dashboard du chef protocol", Q_NULLPTR));
        pushButton_logout1->setText(QApplication::translate("ChefProtocol", "Logout", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChefProtocol", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChefProtocol", "Prenom", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChefProtocol", "CIN", Q_NULLPTR));
        label_5->setText(QApplication::translate("ChefProtocol", "Role", Q_NULLPTR));
        label_6->setText(QString());
        Ajouter->setText(QApplication::translate("ChefProtocol", "Ajouter", Q_NULLPTR));
        label_12->setText(QApplication::translate("ChefProtocol", "Mail", Q_NULLPTR));
        label_13->setText(QApplication::translate("ChefProtocol", "ID", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ChefProtocol", "Ajouter", Q_NULLPTR));
        label_7->setText(QApplication::translate("ChefProtocol", "ID", Q_NULLPTR));
        supprimer->setText(QApplication::translate("ChefProtocol", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ChefProtocol", "Supprimer", Q_NULLPTR));
        label_16->setText(QApplication::translate("ChefProtocol", "RECHERCHE", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ChefProtocol", "ID", Q_NULLPTR)
         << QApplication::translate("ChefProtocol", "NOM", Q_NULLPTR)
         << QApplication::translate("ChefProtocol", "PRENOM", Q_NULLPTR)
         << QApplication::translate("ChefProtocol", "CIN", Q_NULLPTR)
        );
        label_17->setText(QApplication::translate("ChefProtocol", "TRI", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ChefProtocol", "Liste", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ChefProtocol", "Modifier", Q_NULLPTR));
        label_8->setText(QApplication::translate("ChefProtocol", "ID", Q_NULLPTR));
        label_9->setText(QApplication::translate("ChefProtocol", "NOM", Q_NULLPTR));
        label_10->setText(QApplication::translate("ChefProtocol", "Prenom", Q_NULLPTR));
        label_11->setText(QApplication::translate("ChefProtocol", "Role", Q_NULLPTR));
        label_14->setText(QApplication::translate("ChefProtocol", "Mail", Q_NULLPTR));
        label_15->setText(QApplication::translate("ChefProtocol", "CIN", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ChefProtocol", "Modifier", Q_NULLPTR));
        envoyer->setText(QApplication::translate("ChefProtocol", "Envoyer", Q_NULLPTR));
        label_18->setText(QApplication::translate("ChefProtocol", "Mail", Q_NULLPTR));
        label_19->setText(QApplication::translate("ChefProtocol", "Objet", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("ChefProtocol", "Page", Q_NULLPTR));
        generer->setText(QApplication::translate("ChefProtocol", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("ChefProtocol", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChefProtocol: public Ui_ChefProtocol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEFPROTOCOL_H
