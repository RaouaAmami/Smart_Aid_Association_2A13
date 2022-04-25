#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "employee.h"
#include "chefprotocol.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QPixmap pix(":/ressources/img/loginicon.png");
    int w = 150 ;
    int h = 150 ;
    ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->LineEdit_username->text();
    QString password = ui->LineEdit_password->text();




   employee E ;
   QString page =E.login(username,password);

   if(page=="1"){
           QMessageBox::information(this,"Login","Identifiant et mot de pass correct");
           hide();
           chefprotocol = new ChefProtocol(this);
           chefprotocol->show();

       }
       else if(page=="2"){
           QMessageBox::information(this,"Login","Identifiant et mot de pass correct");
           hide();
           rawaa = new Rawaa(this);
           rawaa->show();

       }
   else if(page=="3"){
       QMessageBox::information(this,"Login","Identifiant et mot de pass correct");
       hide();
       //rawaa = new Rawaa(this); RANIA
       //rawaa->show();
   }
   else if(page=="4"){
       QMessageBox::information(this,"Login","Identifiant et mot de pass correct");
       hide();
       //rawaa = new Rawaa(this); MALEK
       //rawaa->show();
   }
   else if(page=="5"){
       QMessageBox::information(this,"Login","Identifiant et mot de pass correct");
       hide();
       //rawaa = new Rawaa(this); FARES
       //rawaa->show();
   }
       else{
            QMessageBox::warning(this,"Login","Identifiant ou Mot De passe Incorrecte");

}
}
