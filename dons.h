#ifndef DONS_H
#define DONS_H
/*#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>*/
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>
#include"QDate"


class Dons
{
    QString ID_DON,NOM_DONATEUR,PRENOM_DONATEUR,TYPE_DON;
    QDate DATE_DON;
public:
    //Constructors
    Dons(){}
    Dons(QString,QString,QString,QString,QDate);
    //Getters
    QString getID_DON(){return ID_DON;}
    QString getNOM_DONATEUR(){return NOM_DONATEUR;}
    QString getPRENOM_DONATEUR(){return PRENOM_DONATEUR;}
    QString getTYPE_DON(){return TYPE_DON;}
    QDate getDATE_DON(){return DATE_DON;}
    //Setters
    void setID_DON(QString i){ID_DON=i;}
    void setNOM_DONATEUR(QString n){NOM_DONATEUR=n;}
    void setPRENOM_DONATEUR(QString p){PRENOM_DONATEUR=p;}
    void setTYPE_DON(QString t){TYPE_DON=t;}
    void setDATE_DON(QDate d){DATE_DON=d;}
    //Fonctionnalités de Base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString,QString,QString,QString,QDate);
    QSqlQueryModel * tri();
    QSqlQueryModel * trii();
    QSqlQueryModel * rechercher(QString);

};

#endif // DONS_H
