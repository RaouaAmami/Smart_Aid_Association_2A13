#include "fares.h"
#include "ui_fares.h"
#include "mainwindow.h"
#include "arduino.h"
Fares::Fares(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fares)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    //this->ui->stackedWidget->setCurrentIndex(0);
    //this->ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(D.afficher());

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


    //ui->tableView->setModel(D.afficher());

}

Fares::~Fares()
{
    delete ui;
}


void Fares::on_logout_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}



void Fares::update_label()
{
    //QByteArray data;
    data=A.read_from_arduino();




    qDebug()<<data;
    if(data=="1"){
        ui->label_3->setText(" Detection de gaz "); // si les données reçues de arduino via la liaison série sont supérieures à 300


     }
    else if (data=="0")
    {ui->label_3->setText(" Air sain ");}



}




void Fares::on_pushButton_4_clicked()
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

void Fares::on_pushButton_3_clicked()
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

void Fares::on_tableView_activated(const QModelIndex &index)
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

void Fares::on_pushButton_5_clicked()
{
    ui->tableView->setModel(D.afficher());
}

void Fares::on_pushButton_clicked()
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
void Fares::on_pushButton_6_clicked()
{
    ui->tableView->setModel(D.tri());
}

void Fares::on_pushButton_7_clicked()
{
    ui->tableView->setModel(D.trii());
}

void Fares::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    QString nom=ui->lineEdit_4->text();
            // qDebug()<<nom;
             if(nom!=""){
            ui->tableView->setModel(D.rechercher(nom));
             }
             else
            {ui->tableView->setModel(D.afficher());}
}


void Fares::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/PC/Desktop/DossierPDF/Fares.pdf");

            QPainter painter(&pdf);

            int i = 4000;
            painter.setPen(Qt::red);
            painter.setFont(QFont("Arial", 30));
            painter.drawText(3000,1500,"LISTE DES DONS ");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 50));
            // painter.drawText(1100,2000,afficheDC);
            painter.drawRect(2700,200,7300,2600);
            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(300,3300,"Identifiant");
            painter.drawText(2300,3300,"NOM_DONATEUR");
            painter.drawText(4300,3300,"PRENOM_DONATEUR");
            painter.drawText(6300,3300,"TYPE_DON");
            painter.drawText(8000,3300,"DATE_DON");
            QSqlQuery query;
            query.prepare("select * from DONS");
            query.exec();
            while (query.next())
            {
                painter.drawText(300,i,query.value(0).toString());
                painter.drawText(2300,i,query.value(1).toString());
                painter.drawText(4300,i,query.value(2).toString());
                painter.drawText(6300,i,query.value(3).toString());
                painter.drawText(8000,i,query.value(4).toString());
                i = i +500;
            }

            int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/PC/Desktop/DossierPDF/Fares.pdf"));

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }
}
