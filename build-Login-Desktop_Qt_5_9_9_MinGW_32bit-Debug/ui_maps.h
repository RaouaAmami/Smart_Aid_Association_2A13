/********************************************************************************
** Form generated from reading UI file 'maps.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPS_H
#define UI_MAPS_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_map
{
public:
    QWidget *centralwidget;
    QLineEdit *le_adresspart2;
    QLabel *labelInformations_2;
    QLabel *labelLatitude;
    QLineEdit *editLongitude;
    QQuickWidget *quickWidget;
    QLabel *labelLongitude;
    QPushButton *chercher;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPositionLatitude_2;
    QLabel *positionLatitude_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelPositionLongitude_2;
    QLabel *positionLongitude_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *editLatitude;
    QPushButton *boutonAller;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *map)
    {
        if (map->objectName().isEmpty())
            map->setObjectName(QStringLiteral("map"));
        map->resize(1075, 706);
        centralwidget = new QWidget(map);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        le_adresspart2 = new QLineEdit(centralwidget);
        le_adresspart2->setObjectName(QStringLiteral("le_adresspart2"));
        le_adresspart2->setGeometry(QRect(90, 410, 827, 20));
        labelInformations_2 = new QLabel(centralwidget);
        labelInformations_2->setObjectName(QStringLiteral("labelInformations_2"));
        labelInformations_2->setGeometry(QRect(181, 643, 825, 13));
        labelInformations_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelLatitude = new QLabel(centralwidget);
        labelLatitude->setObjectName(QStringLiteral("labelLatitude"));
        labelLatitude->setGeometry(QRect(100, 440, 46, 23));
        editLongitude = new QLineEdit(centralwidget);
        editLongitude->setObjectName(QStringLiteral("editLongitude"));
        editLongitude->setGeometry(QRect(429, 441, 133, 20));
        quickWidget = new QQuickWidget(centralwidget);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));
        quickWidget->setGeometry(QRect(100, 30, 827, 331));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quickWidget->sizePolicy().hasHeightForWidth());
        quickWidget->setSizePolicy(sizePolicy);
        quickWidget->setMinimumSize(QSize(0, 0));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        quickWidget->setSource(QUrl(QStringLiteral("qrc:/qml/mapview.qml")));
        labelLongitude = new QLabel(centralwidget);
        labelLongitude->setObjectName(QStringLiteral("labelLongitude"));
        labelLongitude->setGeometry(QRect(371, 440, 54, 23));
        chercher = new QPushButton(centralwidget);
        chercher->setObjectName(QStringLiteral("chercher"));
        chercher->setGeometry(QRect(100, 380, 827, 23));
        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(100, 470, 821, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelPositionLatitude_2 = new QLabel(layoutWidget_4);
        labelPositionLatitude_2->setObjectName(QStringLiteral("labelPositionLatitude_2"));

        horizontalLayout_4->addWidget(labelPositionLatitude_2);

        positionLatitude_2 = new QLabel(layoutWidget_4);
        positionLatitude_2->setObjectName(QStringLiteral("positionLatitude_2"));

        horizontalLayout_4->addWidget(positionLatitude_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        labelPositionLongitude_2 = new QLabel(layoutWidget_4);
        labelPositionLongitude_2->setObjectName(QStringLiteral("labelPositionLongitude_2"));

        horizontalLayout_4->addWidget(labelPositionLongitude_2);

        positionLongitude_2 = new QLabel(layoutWidget_4);
        positionLongitude_2->setObjectName(QStringLiteral("positionLongitude_2"));

        horizontalLayout_4->addWidget(positionLongitude_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        editLatitude = new QLineEdit(centralwidget);
        editLatitude->setObjectName(QStringLiteral("editLatitude"));
        editLatitude->setGeometry(QRect(150, 441, 133, 20));
        boutonAller = new QPushButton(centralwidget);
        boutonAller->setObjectName(QStringLiteral("boutonAller"));
        boutonAller->setGeometry(QRect(810, 440, 75, 23));
        map->setCentralWidget(centralwidget);
        menubar = new QMenuBar(map);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1075, 26));
        map->setMenuBar(menubar);
        statusbar = new QStatusBar(map);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        map->setStatusBar(statusbar);

        retranslateUi(map);

        QMetaObject::connectSlotsByName(map);
    } // setupUi

    void retranslateUi(QMainWindow *map)
    {
        map->setWindowTitle(QApplication::translate("map", "MainWindow", Q_NULLPTR));
        labelInformations_2->setText(QApplication::translate("map", "Informations :", Q_NULLPTR));
        labelLatitude->setText(QApplication::translate("map", "Latitude :", Q_NULLPTR));
        labelLongitude->setText(QApplication::translate("map", "Longitude :", Q_NULLPTR));
        chercher->setText(QApplication::translate("map", "Find Location", Q_NULLPTR));
        labelPositionLatitude_2->setText(QApplication::translate("map", "Latitude :", Q_NULLPTR));
        positionLatitude_2->setText(QApplication::translate("map", "---", Q_NULLPTR));
        labelPositionLongitude_2->setText(QApplication::translate("map", "Longitude :", Q_NULLPTR));
        positionLongitude_2->setText(QApplication::translate("map", "---", Q_NULLPTR));
        boutonAller->setText(QApplication::translate("map", "Aller !", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class map: public Ui_map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPS_H
