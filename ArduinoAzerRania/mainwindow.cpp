#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "parking.h"
#include "QSqlDatabase"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("PORTE OUVERTE");


    else if (data=="0")

        ui->label_3->setText("PORTE FERMEE");

}

void MainWindow::on_pushButton_clicked()
{
    parking P ;
     int ID_EMP=ui->lineEdit->text().toInt();
      bool test=P.verifier(ID_EMP);
     ui->lineEdit->clear();
     if (test){
        A.write_to_arduino("1");
     }
     else
         A.write_to_arduino("0");
}


