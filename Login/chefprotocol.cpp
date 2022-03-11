#include "chefprotocol.h"
#include "ui_chefprotocol.h"
#include "mainwindow.h"
#include "employee.h"
#include <QtWidgets>
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>
#include "connection.h"




ChefProtocol::ChefProtocol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChefProtocol)
{
    ui->setupUi(this);
    ui->tableView->setModel(E.afficher());
}

ChefProtocol::~ChefProtocol()
{
    delete ui;
}

void ChefProtocol::on_pushButton_logout1_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void ChefProtocol::on_Ajouter_clicked()
{
    int ID_EMP=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    int CIN=ui->lineEdit_CIN->text().toInt();
    QString mail=ui->lineEdit_Mail->text();
    QString role=ui->lineEdit_Role->text();


    employee E(ID_EMP,nom,prenom,CIN,role,mail);
    bool testa=E.ajouter();
    QMessageBox msg;
    if (testa){


            msg.setText("Employee ajouté");
            ui->tableView->setModel(E.afficher());
            ui->lineEdit_ID->clear();
            ui->lineEdit_Nom->clear();
            ui->lineEdit_Prenom->clear();
            ui->lineEdit_CIN->clear();
            ui->lineEdit_Mail->clear();
            ui->lineEdit_Role->clear();

    }
    //if (testa){


       // QMessageBox::information(nullptr,QObject::tr("OK"),
                                // QObject::tr("Ajout effectué"));

   // }
    //else
       // QMessageBox::critical(nullptr,QObject::tr("OK"),


                                   // QObject::tr("Ajout NON effectué"));


}


void ChefProtocol::on_afficher_clicked()
{
  ui->tableView->setModel(E.afficher());
}

void ChefProtocol::on_supprimer_clicked()
{
    employee E;
   E.setID(ui->lineEdit_IDS->text().toInt());
        bool test=E.supprimer(E.getID());
        QMessageBox msgBox;
        if (test)
        {
            ui->tableView->setModel(E.afficher());
            ui->lineEdit_IDS->clear();
        }

        //if(test)
           //{ msgBox.setText("Suppression avec succes.");
      // ui->event->setModel(e.afficher());

       // }
       // else
          // { msgBox.setText("Echec de suppression");}
           // msgBox.exec();
}
