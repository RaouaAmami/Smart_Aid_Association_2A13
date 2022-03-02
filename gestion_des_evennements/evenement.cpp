#include "connection.h"
#include "QSqlDatabase"
#include "evenement.h"
#include<QtDebug>
#include <QObject>
evenement::evenement()
{

}


evenement::evenement(int id_event, QString libelle ,  QString lieu,QString type, int datee)
{
    this->id_event=id_event;
    this->libelle=libelle;
    this->lieu=lieu;
    this->type=type;
    this->datee=datee;



}
QSqlQueryModel * evenement::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENEMENTS");
         //qDebug()<<"connection";
        // QString g=QString::number()
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
   QString date=QString::number(datee);
    query.prepare("INSERT INTO EVENEMENTS(id_event, libelle, lieu,type,datee) "
                  "VALUES (:id_event, :libelle, :lieu,:type,:datee)");
    query.bindValue(":id_event", id_string);
    query.bindValue(":libelle", libelle);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":datee", date);
    return query.exec();
   // return test;

}

bool evenement::supprimer(int id_event)
{
    QSqlQuery query;
    QString res=QString::number(id_event);
    query.prepare("Delete from evenements where id_event=:id_event");
    query.bindValue(":id_event",res);
    return query.exec();
}
