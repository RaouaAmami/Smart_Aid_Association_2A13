#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "evenement.cpp"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),

     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->event->setModel(e.afficher());
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_afficher_clicked()
{
     ui->event->setModel(e.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    int Id_event=ui->line_id->text().toInt();
      QString labelle=ui->line_libelle->text();
      QString lieu=ui->line_libelle->text();
      QString type=ui->line_libelle->text();

       int datee=ui->linedate->text().toInt();
       evenement e(Id_event,labelle,lieu,type,datee);

       bool test=e.ajouter();
       QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->event->setModel(e.afficher());
         }
         else
            { msgBox.setText("Echec d'ajout");}
             msgBox.exec();
}



void MainWindow::on_pushButton_supp_clicked()
{
    evenement e;
    e.Set_id_event(ui->line_id->text().toInt());
        bool test=e.supprimer(e.Get_id_event());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->event->setModel(e.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}
            msgBox.exec();
}
