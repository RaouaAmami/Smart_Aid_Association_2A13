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
    /*parking P ;
     data=A.read_from_arduino();

      QString Sstring = QString(data);
      Sstring.remove("\r\n");
      ui->label_3->setText(data);

      qDebug() << Sstring;
       bool test=P.verifier(Sstring);
      if (test){
         A.write_to_arduino("0");
      }
      else
          A.write_to_arduino("1");*/
}

void MainWindow::on_pushButton_clicked()
{
   parking P ;
    data=A.read_from_arduino();

     QString Sstring = QString(data);
     Sstring.remove("\r\n");
     ui->label_3->setText(data);

     qDebug() << Sstring;
      bool test=P.verifier(Sstring);
     if (test){
        A.write_to_arduino("0");
     }
     else
         A.write_to_arduino("1");
}


