/********************************************************************************
** Form generated from reading UI file 'stat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_H
#define UI_STAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stat
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Stat)
    {
        if (Stat->objectName().isEmpty())
            Stat->setObjectName(QStringLiteral("Stat"));
        Stat->resize(972, 438);
        layoutWidget = new QWidget(Stat);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 50, 801, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Stat);

        QMetaObject::connectSlotsByName(Stat);
    } // setupUi

    void retranslateUi(QWidget *Stat)
    {
        Stat->setWindowTitle(QApplication::translate("Stat", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Stat: public Ui_Stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_H
