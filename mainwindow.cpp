#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "evenement.cpp"
#include <QMessageBox> // bib bsh tatina les messages erreur w ila succe
#include<QFileDialog>




//pdfffff


#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
//map

#include <QCalendarWidget>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlListProperty>

#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEvent>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QQmlEngine>
#include <QQuickItem>
//include lang
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent)  //constructeur mta graphique lhajet li tji automatique fl affichage
    : QMainWindow(parent),

     ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    ui->line_id->setValidator( new QIntValidator(100, 999999, this)); //controle de saisie
    QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new
                QRegExpValidator(rx,this);

             ui->combotri->addItem("id");
              ui->combotri->addItem("libelle");
             ui->combotri->addItem("lieu");

             ui->combotri->addItem("type");
             ui->combotri->addItem("datee");

            ui->combotype->addItem("divertissement");
            ui->combotype->addItem("anniversaire");

        ui->line_libelle->setValidator(validator);
        ui->line_lieu->setValidator(validator);

    ui->event->setModel(e.afficher());
    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

  //  emit setCenter(25.000, 50.000);
   // emit addMarker(25.000, 50.000);

    //par defaut affichage

    //map
    connect(ui->boutonAller, SIGNAL(clicked(bool)), this, SLOT(aller()));

    QQuickItem *item = ui->quickWidget->rootObject();
    QObject *objectMouseArea = item->findChild<QObject *>("mouseArea");
    if(objectMouseArea != nullptr)
    {
        connect(objectMouseArea, SIGNAL(afficherPosition(QString,QString)), this, SLOT(afficherPosition(QString,QString)));
    }
    QObject *objectGeocodage = item->findChild<QObject *>("geocodage");
    if(objectGeocodage != nullptr)
    {
        connect(objectGeocodage, SIGNAL(afficherInformations(QString,QString)), this, SLOT(afficherInformations(QString,QString)));
    }

    //setWindowTitle("Map v2");
    //showMaximized();
    //Endmap
}
MainWindow::~MainWindow()  //destructeur yfregh memoire
{
    delete ui;
}


void MainWindow::on_pushButton_afficher_clicked()
{
     ui->event->setModel(e.afficher());
}

void MainWindow::on_pushButton_clicked()//houni tzid l verif
{
    int id_event=ui->line_id->text().toInt();
      QString libelle=ui->line_libelle->text();
      QString lieu=ui->line_lieu->text();
     QString type=ui->combotype->currentText();
    QDate datee=ui->dateEdit->date();

       evenement e(id_event,libelle,lieu,type,datee);

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
        bool test=e.supprimer(e.Get_id_event()); //get tjbed beha
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->event->setModel(e.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}


        msgBox.exec();
}

void MainWindow::on_event_activated(const QModelIndex & index)//taatih index w yrecuperi les donnes /////////////////////////////////////////////////////
{
        int id_event=ui->event->model()->data(index).toInt();
        QDate dateevent = ui->event->model()->data(index).toDate();                                                                         //recuperer les dates
        QCalendarWidget *calendar = new QCalendarWidget();//declaration
           calendar->setSelectedDate(dateevent);                                                                                     // chercher la date en parametre
            calendar->show();

        evenement e;



        e=e.SelectModif(id_event);

       ui->line_id->setText(QString(QString::number(e.Get_id_event())));
       ui->line_libelle->setText(QString(e.Get_libelle()));
       ui->line_lieu->setText(QString(e.Get_lieu()));
       ui->combotype->setCurrentText(e.Get_type());
       ui->dateEdit->setDate(QDate(e.get_datee()));




       int idPDF=ui->event->model()->data(index).toInt();
       QString s = QDateTime::currentDateTime().toString();
       s.replace(" ","_");//
       s.replace(":",".");
       qDebug() << s;


       e.SelectModif(idPDF);
      // QString filepath=QFileDialog::getExistingDirectory(this, "Get Any File");
      // if(filepath.isEmpty())
       {
           return;
       }

        //e.pdf(s+".pdf",filepath);//



       QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Fichier Pdf cree\n""click ok to exit"),QMessageBox::Ok);




       QString part1="https://nominatim.openstreetmap.org/search?q=";

       QString part2=ui->event->model()->data(index).toString();
              // ui->le_adresspart2->text();
       QString part3="&format=json&polygon=1&addressdetails=1&fbclid=IwAR2r_qtxdov_4zZdVKfy6Xx2UXmJd5rR1XddpqCogBeZ_7nv0srbxa9OOW8";
           QUrl ava_url(part1+part2+part3);
           QNetworkRequest ava_request(ava_url);

           QNetworkAccessManager *manager = new QNetworkAccessManager();
           QEventLoop loop;

           QObject::connect(manager,
                            SIGNAL(finished(QNetworkReply*)),
                            &loop,
                            SLOT(quit()));

           QNetworkReply* reply = manager->get(ava_request);
           loop.exec();

           QString response = (QString)reply->readAll();
           QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
           QJsonObject obj = doc.object();

    // get lat et lon from the array
           QString x=doc.array()[0].toObject()["lat"].toString();
           QString y=doc.array()[0].toObject()["lon"].toString();

            qDebug() <<x;
            qDebug() <<y;

            ui->editLatitude->setText(x);
            ui->editLongitude->setText(y);



}

void MainWindow::on_pushButton_modif_clicked()
{


        int id_event=ui->line_id->text().toInt();
        QString libelle=ui->line_libelle->text();
        QString lieu=ui->line_lieu->text();
        QString type=ui->combotype->currentText();
        QDate datee=ui->dateEdit->date();
        bool test=false;


        evenement e(id_event,libelle,lieu,type,datee);
        test=e.Modifer(id_event);

        if(test==true)
        {
          QMessageBox::information(nullptr,QObject::tr("ok"),
          QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
          ui->event->setModel(e.afficher()); //affichage automatique apres modification


        }
        else
        {

                QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);

        }
}






void MainWindow::on_line_recherche_textEdited(const QString &arg1)
{

         QString nom=ui->line_recherche->text();
        // qDebug()<<nom;
         if(nom!=""){
        ui->event->setModel(e.rechercher(nom));
         }
         else
        {ui->event->setModel(e.afficher());}


}




void MainWindow::on_combotri_activated(const QString &arg1)
{
    int value=ui->combotri->currentIndex();

        //qDebug()<<value;
        if (value==0)
        {
            ui->event->setModel(e.afficherTri_id());
        }
        if (value==1)
        {
        ui->event->setModel(e.afficherTri_libelle());
        }
        if (value==2)
        {
        ui->event->setModel(e.afficherTri_lieu());
        }
        if (value==3)
        {
        ui->event->setModel(e.afficherTri_type());
        }
        if (value==4)
        {
        ui->event->setModel(e.afficherTri_date());
        }
}




/*void MainWindow::on_button_pdf_clicked()
{

    evenement e;
    QString s = QDateTime::currentDateTime().toString();
    s.replace(" ","_");
    s.replace(":",".");
    qDebug() << s;



    QString filepath=QFileDialog::getExistingDirectory(this, "Get Any File");
    if(filepath.isEmpty())
    {
        return;
    }

     //e.pdf(s+".pdf",filepath);



    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("Fichier Pdf cree\n""click ok to exit"),QMessageBox::Ok);

}*/

void MainWindow::on_button_stat_clicked()
{
    third = new stat_categorie(this);                                                                                 // pour ouvrir la fenetre contenant stat
      third->choix_pie();
      third->show();
}


void MainWindow::on_chercher_clicked()
{  /*
    QString part1="https://nominatim.openstreetmap.org/search?q=";

    QString part2=ui->le_adresspart2->text();
    QString part3="&format=json&polygon=1&addressdetails=1&fbclid=IwAR2r_qtxdov_4zZdVKfy6Xx2UXmJd5rR1XddpqCogBeZ_7nv0srbxa9OOW8";
        QUrl ava_url(part1+part2+part3);
        QNetworkRequest ava_request(ava_url);

        QNetworkAccessManager *manager = new QNetworkAccessManager();
        QEventLoop loop;

        QObject::connect(manager,
                         SIGNAL(finished(QNetworkReply*)),
                         &loop,
                         SLOT(quit()));

        QNetworkReply* reply = manager->get(ava_request);
        loop.exec();

        QString response = (QString)reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
        QJsonObject obj = doc.object();

 // get lat et lon from the array
        QString x=doc.array()[0].toObject()["lat"].toString();
        QString y=doc.array()[0].toObject()["lon"].toString();

         qDebug() <<x;
         qDebug() <<y;

         ui->editLatitude->setText(x);
         ui->editLongitude->setText(y);

         */
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
        ui->quickWidget->show();
        auto obj = ui->quickWidget->rootObject();
        connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
        connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

    emit setCenter(ui->editLatitude->text().toFloat(), ui->editLongitude->text().toFloat());
    emit addMarker(ui->editLatitude->text().toFloat(), ui->editLongitude->text().toFloat());
}
void MainWindow::aller()
{
    QQuickItem *item = ui->quickWidget->rootObject();
    QObject *object = item->findChild<QObject *>("indicateurPosition");
    QVariant latitude = QVariant(43.8);

    //ui->editLatitude->text(); //<
    QVariant longitude = QVariant(4.8167);
   // ui->editLongitude->text(); //


    if(object != nullptr)
    {
        qDebug() << Q_FUNC_INFO << latitude << longitude;
        QMetaObject::invokeMethod(object, "aller", Q_ARG(QVariant, latitude), Q_ARG(QVariant, longitude));
    }
}

void MainWindow::afficherPosition(QString latitude, QString longitude)
{
    qDebug() << Q_FUNC_INFO << latitude << longitude;
    ui->positionLatitude_2->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->positionLongitude_2->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
    ui->editLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->editLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
}

void MainWindow::afficherInformations(QString adresse, QString coordonnee)
{
    qDebug() << Q_FUNC_INFO << adresse << coordonnee;
    ui->labelInformations_2->setText("Informations : " + adresse);
}


void MainWindow::on_pbgotomap_clicked()
{

   // ui->tabWidget->setCurrentIndex(7);

    //QString loc=ui->le_lieumap->text();
    //ui->le_adresspart2->setText(loc);
}


/*void MainWindow::on_calendarWidget_activated(const QDate &date)
{

}*/

void MainWindow::on_pushButton_stat_clicked()
{
    third = new stat_categorie(this); // pour ouvrir la fenetre contenant stat
      third->choix_pie();
      third->show();
}



void MainWindow::on_pushButton_3_clicked()
{
    evenement e;
    e.Set_id_event(ui->line_id->text().toInt());
        bool test=e.supprimer(e.Get_id_event()); //get tjbed beha
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->event->setModel(e.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}


        msgBox.exec();
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/21692/Desktop/test_pdf/malek.pdf");

            QPainter painter(&pdf);

            int i = 4000;
            painter.setPen(Qt::red);
            painter.setFont(QFont("Arial", 30));
            painter.drawText(3000,1500,"LISTE DES EVENEMENTS ");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 50));
            // painter.drawText(1100,2000,afficheDC);
            painter.drawRect(2700,200,7300,2600);
            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(300,3300,"Identifiant");
            painter.drawText(2300,3300,"libelle");
            painter.drawText(4300,3300,"lieu");
            painter.drawText(6300,3300,"type");
            painter.drawText(8000,3300,"datee");
            QSqlQuery query;
            query.prepare("select * from EVENEMENTS");
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
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21692/Desktop/test_pdf/malek.pdf"));

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }
}




void MainWindow::on_pushButton_2_pressed()
{
    //int id_event=ui->event->model()->data(index).toInt();
   // QDate dateevent = ui->event->model()->data(index).toDate();
    QCalendarWidget *calendar = new QCalendarWidget();//declaration
   QDate date = QDate::currentDate();
       calendar->setSelectedDate(date);



            QSqlQuery query;
            query.prepare("select * from EVENEMENTS  ");
            QStringList datee;
            QStringList list;

            QTextCharFormat format = calendar->weekdayTextFormat(Qt::Wednesday);
            if(query.exec())
            {
                while(query.next())
                {
                    datee << query.value(4).toString();
                }
            }

             for (int i = 0; i < datee.size(); ++i)
             {
             list = datee.at(i).split(QRegularExpression("[-]"), QString::SkipEmptyParts); //9assamna date ala 3
             int day=list.at(0).toInt();
             int month = list.at(1).toInt();
             int year = list.at(2).toInt();
                 QDate d(year,month,day);
                 cout << d.toString().toLocal8Bit().constData() << endl;
                 format.setForeground(QBrush(Qt::yellow, Qt::SolidPattern));
                 calendar->setDateTextFormat(d, format);
             }
calendar->show();

}
