#include "connection.h"
#include "QSqlDatabase"
#include "evenement.h"
#include<QtDebug>
#include <QPdfWriter> //include mta l pdf
#include "QtSql/QSqlRecord" //include teb3a l pdf
#include <QPainter> //pdf
#include <QPrinter> //pdf
#include <QTextDocument> //pdf

// include for map
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlListProperty>
#include "evenement.h"
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

//endmapinclude

 //QObject est la classe de base de tous les objets Qt
evenement::evenement()  //constructeur par defaut
{
    this->id_event=0;
    this->libelle=" ";
    this->lieu=" ";
    this->type=" " ;
    this->datee=   QDate::currentDate() ;
}


evenement::evenement(int id_event, QString libelle ,  QString lieu,QString type, QDate datee) //constructeur parametré
{
    this->id_event=id_event;
    this->libelle=libelle;
    this->lieu=lieu;
    this->type=type;
    this->datee=datee;



}
QSqlQueryModel * evenement::afficher() // fournir des données pour afficher
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS");//reset ll model
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_event"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee"));
    return model;
}


bool evenement::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_event);

    query.prepare("INSERT INTO EVENEMENTS(id_event, libelle, lieu,type,datee) "
                  "VALUES (:id_event, :libelle, :lieu,:type,:datee)");
    query.bindValue(":id_event", id_string);
    query.bindValue(":libelle", libelle);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":datee", datee);
    return query.exec();


}

bool evenement::supprimer(int id_event)
{
    QSqlQuery query;
    QString res=QString::number(id_event);
    query.prepare("Delete from evenements where id_event=:id_event");
    query.bindValue(":id_event",res);
    return query.exec();
}


evenement evenement ::SelectModif(int id_event)
{

    QSqlQuery query;
    QString res=QString::number(id_event);
    query.prepare("Select * from evenements where id_event=:id_event"); //prepare sert a lire les requettes
    query.bindValue(":id_event",res);
    query.exec(); //exec pour executer requette
    query.next();
    int id_eventval=query.value(0).toInt(); //recuperer les donnees de la bd
    QString libelleval=query.value(1).toString();
    QString lieuval=query.value(2).toString();
    QString typeval=query.value(3).toString();
    QDate dateeval=query.value(4).toDate();

    evenement e (id_eventval,libelleval,lieuval,typeval,dateeval); //instan

    return e;
}


bool evenement::Modifer(int id_event)
{
    QSqlQuery query;
    QString  id_event_string=QString::number( id_event);

    query.prepare("UPDATE EVENEMENTS SET libelle= :libelle, lieu= :lieu,type= :type,datee= :datee where id_event=:id_event");
    query.bindValue(":id_event", id_event_string); //n9olo kol haja equivalente l shnoa
    query.bindValue(":libelle", libelle);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":datee", datee);
    return query.exec(); //returnina l execution

}



QSqlQueryModel * evenement ::rechercher(QString mot)
{
     QSqlQuery query;
     query.prepare("SELECT * FROM EVENEMENTS where ((libelle like :NOMC) or (lieu like :NOMC) or (type like :NOMC) or "
        "(datee like :NOMC))");
     query.bindValue(":NOMC", mot);
     query.exec();

    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery(query);


    return model;
}


QSqlQueryModel * evenement::afficherTri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS order by id_event ASC");//asc c ascendant
    return model;
}


QSqlQueryModel * evenement::afficherTri_libelle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS order by libelle ASC");//asc c ascendant
    return model;
}






QSqlQueryModel * evenement::afficherTri_lieu()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS order by lieu ASC");//asc c ascendant
    return model;
}



QSqlQueryModel * evenement::afficherTri_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS order by type ASC");//asc c ascendant
    return model;
}

QSqlQueryModel * evenement::afficherTri_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS order by datee ASC");//asc c ascendant
    return model;
}




/*void evenement::pdf(QString filename,QString filepath)
{
  //  LE_ID_SUPP
    evenement e;


    QSqlQuery query;
    query.exec("SELECT * from EVENEMENTS ");


  //  const int rowCount = query.size();
    const int columnCount = query.record().count();



    QString strStream;
    QTextStream out(&strStream);
  QString s = QDate::currentDate().toString();
  QString t = QTime::currentTime().toString();
    out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("TITLE OF TABLE")
          <<  "</head>\n"
          "<body bgcolor=beige link=#5000A0>\n"
    "<div align=right>"

       +s+
    "</div>"
    "<div align=left>"
       +t+
    "</div>"
            "<h1 align=center>la liste des evenements </h1>"

          "<table align=center border=1 cellspacing=2 cellpadding=2>\n";

      // headers
     out << "<br />";
      out << "<thead  align=center><tr bgcolor=red";
      for (int column = 0; column < columnCount; column++)
        out << QString("<th>%1</th>").arg(query.record().fieldName(column));
      out << "</tr></thead>\n";

      while (query.next()) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
          QString data = query.value(column).toString();
          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

           out << "<br />";

          }
        out << "</tr>\n";

      }



     out <<  "</table>\n";
   //out<<"<img  src='pics/malek.png' width='100' height='100'/>"
         "</body>\n"
         "</html>\n";



    QTextDocument document;
    document.setHtml(strStream);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filepath+"/"+filename);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

}*/








