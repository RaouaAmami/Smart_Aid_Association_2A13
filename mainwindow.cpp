#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dons.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setModel(D.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    QString ID_DON=ui->lineEdit->text();
    QString NOM_DONATEUR=ui->lineEdit_2->text();
    QString PRENOM_DONATEUR=ui->lineEdit_3->text();
    QString TYPE_DON=ui->comboBox->currentText();
    QDate DATE_DON=ui->dateEdit->date();

    Dons D(ID_DON,NOM_DONATEUR,PRENOM_DONATEUR,TYPE_DON,DATE_DON);

    bool test=D.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to Exit."), QMessageBox::Cancel);
ui->tableView->setModel(D.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to Exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString ID_DON=ui->lineEdit->text();
    bool test=D.supprimer(ID_DON);

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to Exit."), QMessageBox::Cancel);
ui->tableView->setModel(D.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "Click Cancel to Exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
        qry.prepare("select * from DONS where ID_DON='"+val+"' or NOM_DONATEUR='"+val+"' or PRENOM_DONATEUR='"+val+"' or TYPE_DON='"+val+"'");
        if (qry.exec())
        { while (qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
                ui->lineEdit_2->setText(qry.value(1).toString());
                ui->lineEdit_3->setText(qry.value(2).toString());
                ui->comboBox->setEditText(qry.value(3).toString());
                ui->dateEdit->setDate(qry.value(4).toDate());


            }
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(D.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    //{
            QString ID_DON = ui->lineEdit->text();
            QString NOM_DONATEUR= ui->lineEdit_2->text();
            QString PRENOM_DONATEUR= ui->lineEdit_3->text();
            QString TYPE_DON=ui->comboBox->currentText();
            QDate DATE_DON=ui->dateEdit->date();

        Dons D(ID_DON,NOM_DONATEUR,PRENOM_DONATEUR ,TYPE_DON ,DATE_DON);
          bool test=D.modifier(ID_DON,NOM_DONATEUR,PRENOM_DONATEUR,TYPE_DON ,DATE_DON);
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("modifier un Don"),
                          QObject::tr("Don modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(D.afficher());




        }
          else
              QMessageBox::critical(nullptr, QObject::tr("modifier un Don"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        //}
}
