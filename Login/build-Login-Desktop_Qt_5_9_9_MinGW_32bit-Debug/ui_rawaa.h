/********************************************************************************
** Form generated from reading UI file 'rawaa.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAWAA_H
#define UI_RAWAA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Rawaa
{
public:
    QLabel *label;
    QPushButton *pushButton_logout;

    void setupUi(QDialog *Rawaa)
    {
        if (Rawaa->objectName().isEmpty())
            Rawaa->setObjectName(QStringLiteral("Rawaa"));
        Rawaa->resize(400, 300);
        label = new QLabel(Rawaa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 150, 181, 16));
        pushButton_logout = new QPushButton(Rawaa);
        pushButton_logout->setObjectName(QStringLiteral("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(300, 20, 75, 23));

        retranslateUi(Rawaa);

        QMetaObject::connectSlotsByName(Rawaa);
    } // setupUi

    void retranslateUi(QDialog *Rawaa)
    {
        Rawaa->setWindowTitle(QApplication::translate("Rawaa", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Rawaa", "Rawaa dashboard", Q_NULLPTR));
        pushButton_logout->setText(QApplication::translate("Rawaa", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rawaa: public Ui_Rawaa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAWAA_H
