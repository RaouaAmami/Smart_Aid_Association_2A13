#ifndef ENFANTS_H
#define ENFANTS_H

#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>



class enfant
{
private:
    QString id,nom,prenom,genre,photo;
    QDate   date_n,date_ins;

public:
    enfant();
    enfant(QString id,QString nom ,QString prenom ,QString genre,QDate date_n,QDate date_ins,QString photo ){
        this->id = id ;
        this->nom = nom;
        this->prenom=prenom;
        this->genre=genre;
        this->date_n=date_n;
        this->date_ins=date_ins;
        this->photo=photo;




    }
    void setid(QString id){this->id=id;}
    QString getid(){return this->id;}
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    QString getprenom(){return this->prenom;}
    void setgenre(QString genre){this->genre=genre;}
    QString getgenre(){return this->genre;}

    void setdate_n(QDate date_n){this->date_n=date_n;}
    QDate getdate_n(){return this->date_n;}
    void setdate_ins(QDate date_ins){this->date_ins=date_ins;}
    QDate getdate_ins(){return this->date_ins;}

    bool ajouter();
    bool modifier(QString id);
    bool supprimer(QString id);

    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString id);
      QSqlQueryModel * tri();
};

#endif
