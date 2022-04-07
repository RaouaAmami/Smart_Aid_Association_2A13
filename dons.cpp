#include "dons.h"
#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>

using namespace std;

Dons::Dons(QString ID_DON,QString NOM_DONATEUR,QString PRENOM_DONATEUR,QString TYPE_DON,QDate DATE_DON)
{
  this->ID_DON=ID_DON;
    this->NOM_DONATEUR=NOM_DONATEUR;
    this->PRENOM_DONATEUR=PRENOM_DONATEUR;
    this->TYPE_DON=TYPE_DON;
    this->DATE_DON=DATE_DON;
}

bool Dons::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into DONS (ID_DON,NOM_DONATEUR,PRENOM_DONATEUR,TYPE_DON,DATE_DON) VALUES (:ID_DON,:NOM_DONATEUR,:PRENOM_DONATEUR,:TYPE_DON,:DATE_DON)");

      query.bindValue(":ID_DON",ID_DON);
      query.bindValue(":NOM_DONATEUR",NOM_DONATEUR);
      query.bindValue(":PRENOM_DONATEUR",PRENOM_DONATEUR);
      query.bindValue(":TYPE_DON",TYPE_DON);
      query.bindValue(":DATE_DON",DATE_DON);
    return query.exec();
}

QSqlQueryModel * Dons::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from DONS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_DON"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_DONATEUR"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_DONATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_DON"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_DON"));

    return model;

}

bool Dons::supprimer(QString ID_DON)
{
    QSqlQuery query;

    query.prepare("Delete from DONS where ID_DON= :ID_DON");
    query.bindValue(":ID_DON",ID_DON);

    return query.exec();
}



bool Dons :: modifier(QString ID_DON,QString NOM_DONATEUR,QString PRENOM_DONATEUR,QString TYPE_DON,QDate DATE_DON)
{

    QSqlQuery qry;
        qry.prepare("UPDATE Dons set NOM_DONATEUR=(?),PRENOM_DONATEUR=(?),TYPE_DON=(?), DATE_DON=(?) where ID_DON=(?) ");  //   nahitha mel requête


        qry.addBindValue(NOM_DONATEUR);
        qry.addBindValue(PRENOM_DONATEUR);
        qry.addBindValue(TYPE_DON);
        qry.addBindValue(DATE_DON);
        qry.addBindValue(ID_DON);


   return  qry.exec();
}

QSqlQueryModel *Dons::tri()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  DONS ORDER BY ID_DON ");
    q->exec();
    model->setQuery(*q);
    return model;
}


QSqlQueryModel *Dons::trii()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  DONS ORDER BY TYPE_DON ");
    q->exec();
    model->setQuery(*q);
    return model;
}

QSqlQueryModel * Dons::rechercher(QString mot)
{
     QSqlQuery query;
     query.prepare("SELECT * FROM DONS where ((NOM_DONATEUR like :NOMC) or (PRENOM_DONATEUR like :NOMC) or (TYPE_DON like :NOMC) or "
        "(DATE_DON like :NOMC))");
     query.bindValue(":NOMC", mot);
     query.exec();

    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery(query);


    return model;
}
