/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_video
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pb_importervid;
    QPushButton *pb_pause;
    QPushButton *pb_play;
    QPushButton *pb_stop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QStringLiteral("video"));
        video->resize(800, 600);
        centralwidget = new QWidget(video);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 100, 551, 371));
        pb_importervid = new QPushButton(widget);
        pb_importervid->setObjectName(QStringLiteral("pb_importervid"));
        pb_importervid->setGeometry(QRect(10, 310, 121, 41));
        QFont font;
        font.setPointSize(13);
        pb_importervid->setFont(font);
        pb_importervid->setStyleSheet(QLatin1String("background-color: rgb(220, 220, 0);\n"
"color: rgb(0, 0, 0);"));
        pb_pause = new QPushButton(widget);
        pb_pause->setObjectName(QStringLiteral("pb_pause"));
        pb_pause->setGeometry(QRect(150, 310, 101, 41));
        pb_pause->setFont(font);
        pb_pause->setStyleSheet(QLatin1String("background-color: rgb(220, 220, 0);\n"
"color: rgb(0, 0, 0);"));
        pb_play = new QPushButton(widget);
        pb_play->setObjectName(QStringLiteral("pb_play"));
        pb_play->setGeometry(QRect(270, 310, 91, 41));
        pb_play->setFont(font);
        pb_play->setStyleSheet(QLatin1String("background-color: rgb(220, 220, 0);\n"
"color: rgb(0, 0, 0);"));
        pb_stop = new QPushButton(widget);
        pb_stop->setObjectName(QStringLiteral("pb_stop"));
        pb_stop->setGeometry(QRect(410, 310, 101, 41));
        pb_stop->setFont(font);
        pb_stop->setStyleSheet(QLatin1String("background-color: rgb(220, 220, 0);\n"
"color: rgb(0, 0, 0);"));
        video->setCentralWidget(centralwidget);
        menubar = new QMenuBar(video);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        video->setMenuBar(menubar);
        statusbar = new QStatusBar(video);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        video->setStatusBar(statusbar);

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QMainWindow *video)
    {
        video->setWindowTitle(QApplication::translate("video", "MainWindow", Q_NULLPTR));
        pb_importervid->setText(QApplication::translate("video", "Importer", Q_NULLPTR));
        pb_pause->setText(QApplication::translate("video", "Pause", Q_NULLPTR));
        pb_play->setText(QApplication::translate("video", "play", Q_NULLPTR));
        pb_stop->setText(QApplication::translate("video", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
