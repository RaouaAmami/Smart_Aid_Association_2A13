#ifndef BENEVOL_H
#define BENEVOL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class benevol
{
    QString nom_benevol, prenom_benevol, adresse_benevol;
    int id_benevol, tel_benevol;
public:
    //Constructeurs
    benevol();
    benevol(int,QString,QString,int,QString);

    //Getters
    QString getnom_benevol(){return nom_benevol;}
    QString getprenom_benevol(){return prenom_benevol;}
    QString getadresse_benevol(){return adresse_benevol;}
    int getid_benevol(){return id_benevol;}
    int gettel_benevol(){return tel_benevol;}

    //Setters
    void setnom_benevol(QString n){ nom_benevol = n;}
    void setprenom_benevol(QString p){ prenom_benevol = p;}
    void setadresse_benevol(QString a){ adresse_benevol = a;}
    void setid_benevol(int i){ id_benevol = i;}
    void settel_benevol(int t){ tel_benevol = t;}

    //Fonctionalités de base relatives a l'entité benevol
    bool Ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int , QString , QString , int , QString );





};

#endif // BENEVOL_H
