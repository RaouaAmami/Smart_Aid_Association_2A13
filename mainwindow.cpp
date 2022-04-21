#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<arduino.h>
#include<QObject>
#include<QtSerialPort>
#include<QtSerialPort/QSerialPort> //classe rassemblant des fonctions permettent l'echange des données
#include<QtSerialPort/QSerialPortInfo> //classe fournissant des informations sur les ports disponibles*

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<< "arduino is available and connected to : " << A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to : " << A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available : " << A.getarduino_port_name();
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    QString Sstring = QString(data);
         Sstring.remove("\r\n");

 if (Sstring== "0")
ui->label->setText("mouvement détécté ");

else if (Sstring == "1")
ui->label->setText("Pas de mouvement");
}

void MainWindow::on_pushButton_clicked()
{
A.write_to_arduino("2");
}

