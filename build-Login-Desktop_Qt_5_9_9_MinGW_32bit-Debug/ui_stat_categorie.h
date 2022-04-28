/********************************************************************************
** Form generated from reading UI file 'stat_categorie.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_CATEGORIE_H
#define UI_STAT_CATEGORIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stat_categorie
{
public:
    QLabel *label;

    void setupUi(QWidget *stat_categorie)
    {
        if (stat_categorie->objectName().isEmpty())
            stat_categorie->setObjectName(QStringLiteral("stat_categorie"));
        stat_categorie->resize(1116, 684);
        label = new QLabel(stat_categorie);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 1041, 611));

        retranslateUi(stat_categorie);

        QMetaObject::connectSlotsByName(stat_categorie);
    } // setupUi

    void retranslateUi(QWidget *stat_categorie)
    {
        stat_categorie->setWindowTitle(QApplication::translate("stat_categorie", "Form", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stat_categorie: public Ui_stat_categorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_CATEGORIE_H
