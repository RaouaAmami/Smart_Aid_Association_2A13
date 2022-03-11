#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QTableView>
#include <QTableWidget>
#include <QPushButton>
#include <QDate>
#include <QObject>
#include "benevol.h"
#include <QMainWindow>
#include <QIntValidator>
#include <QWidget>






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tablebenevol->setModel(Ben.afficher());
    ui->lineEdit->setValidator ( new QIntValidator(100, 999, this));

}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_pushButton_Ajouter_clicked()
{
    int id_benevol=ui->lineEdit->text().toInt();
    QString nom_benevol=ui->lineEdit_2->text();
    QString prenom_benevol=ui->lineEdit_3->text();
    int tel_benevol=ui->lineEdit_5->text().toInt();
    QString adresse_benevol=ui->lineEdit_6->text();

     benevol Ben(id_benevol,nom_benevol,prenom_benevol,tel_benevol,adresse_benevol);
     bool test=Ben.Ajouter();

     if(test)
     {
         //Refresh(actualiser)
         ui->tablebenevol->setModel(Ben.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click cancelto exit."),QMessageBox::Cancel);


      }
     else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_benevol=ui->lineEdit->text().toInt();
    bool test=Ben.supprimer(id_benevol);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "Click Cancel to exit"), QMessageBox::Cancel);
}



void MainWindow::on_modifier_clicked()
{

                    int id_benevol= ui->lineEdit->text().toInt();
                    QString nom_benevol=ui->lineEdit_2->text();
                    QString prenom_benevol=ui->lineEdit_3->text();
                    int tel_benevol= ui->lineEdit_5->text().toInt();
                    QString adresse_benevol=ui->lineEdit_6->text();


                benevol Ben(id_benevol ,nom_benevol ,prenom_benevol ,tel_benevol ,adresse_benevol);
                ui->lineEdit->setText("");
                ui->lineEdit_2->setText("");
                ui->lineEdit_3->setText("");
                ui->lineEdit_5->setText("");
                ui->lineEdit_6->setText("");





               bool test = Ben.modifier(id_benevol ,nom_benevol ,prenom_benevol ,tel_benevol ,adresse_benevol);


               if(test)

{
                    ui->tablebenevol->setModel(Ben.afficher());
                   QMessageBox::information(nullptr, QObject::tr("OK "),
                               QObject::tr("modification effectuée\n"
               "Click Cancel to exit."), QMessageBox::Cancel);
}
               else
                 {  QMessageBox::information(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("modification echouèe.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
}





void MainWindow::on_TRIER_clicked()
{
    //TO DO

}



void MainWindow::on_RECHERCHER_clicked()
{
    //TO DO

}

void MainWindow::on_IMPRIMER_clicked()
{
    //TO DO

}

void MainWindow::on_NOTIFIER_clicked()
{
    //TO DO

}

void MainWindow::on_MEMBRE_clicked()
{
    //TO DO

}

void MainWindow::on_SATISTIQUES_clicked()
{
    //TO DO

}
