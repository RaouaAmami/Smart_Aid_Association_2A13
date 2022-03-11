#include "mainwindow.h"
#include "connection.h"
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test==true)
    {
        w.show();
        //m.show();
      //d.show();


      qDebug()<<"connection reussite";          /*     */
      //QMessageBox::information(nullptr,QObject::tr("database is open"),
        //                       QObject::tr("Connection successfull\n""click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        qDebug()<<"connection failed";
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("Connection failed\n""click cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
}
