#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
     ui->lineEdit_2->setValidator(validator);
      ui->lineEdit_3->setValidator(validator);

    ui->tableView->setModel(tmpenfant.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpenfant.recherche(arg1));
}

void MainWindow::on_pushButton_clicked()
{  QString id,nom,prenom,genre;
    QDate date_n,date_ins;



    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty() )
    {
        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                             QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else{
        id=ui->lineEdit->text();
        nom=ui->lineEdit_2->text();
        prenom=ui->lineEdit_3->text();
        date_n=ui->dateEdit->date();
      date_ins=ui->dateEdit_2->date() ;


           if (ui->comboBox->currentIndex()==0)
               genre="garcon";
        else {
            genre="fille";
        }


        enfant e(id,nom,prenom,genre,date_n,date_ins ) ;
        bool test=e.ajouter();

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un   enfant"),
                                     QObject::tr("  enfant ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpenfant.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un  enfant"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }


}

void MainWindow::on_pushButton_4_clicked()
{

    QString id,nom,prenom,genre;
    QDate   date_n,date_ins;

    id=ui->lineEdit->text();
    nom=ui->lineEdit_2->text();
    prenom=ui->lineEdit_3->text();
    date_n=ui->dateEdit->date();
    date_ins=ui->dateEdit_2->date() ;

    if (ui->comboBox->currentIndex()==0)

        genre="garcon";
    else {
        genre="fille";
    }



    enfant e( id, nom , prenom , genre, date_n, date_ins );
    bool test= e.modifier(id);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un   enfant"),
                                 QObject::tr("  enfant Modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpenfant.afficher());//refresh
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un enfant"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString id=ui->lineEdit->text();
    enfant e;
    bool test=e.supprimer(id);
    ui->tableView->setModel(tmpenfant.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer enfant"),
                                 QObject::tr("enfant supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("enfant un categorie"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
