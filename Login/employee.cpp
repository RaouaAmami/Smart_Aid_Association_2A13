#include "employee.h"
#include "connection.h"
#include "QSqlDatabase"
#include<QtDebug>
#include <QObject>

employee::employee(int ID_EMP,QString nom,QString prenom,int CIN,QString role,QString mail)
{
        this->ID_EMP=ID_EMP;
        this->nom=nom;
        this->prenom=prenom;
        this->CIN=CIN;
        this->role=role;
        this->mail=mail;

}

bool employee::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_EMP);
    query.prepare("INSERT INTO EMPLOYEES (ID_EMP,NOM,PRENOM,CIN,ROLE,MAIL)" "VALUES (:ID_EMP,:NOM,:PRENOM,:CIN,:ROLE,:MAIL)");

    query.bindValue(":ID_EMP",res);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":CIN",CIN);
    query.bindValue(":ROLE",role);
    query.bindValue(":MAIL",mail);

    return query.exec();
}

QSqlQueryModel * employee::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMP"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

bool employee::supprimer(int ID_EMP)
{
    QSqlQuery query;
    QString res=QString::number(ID_EMP);
    query.prepare("DELETE FROM EMPLOYEES WHERE ID_EMP=:ID_EMP");
    query.bindValue(":ID_EMP",res);
    return query.exec();
}
