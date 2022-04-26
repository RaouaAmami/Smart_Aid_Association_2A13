#ifndef BENEVOL_H
#define BENEVOL_H


#include <QString>
#include <QSqlQueryModel>
#include <QTableView>








class benevol
{
    int id_benevol, tel_benevol;
    QString nom_benevol, prenom_benevol, adresse_benevol;
public:
    //Constructeurs
    benevol();
    benevol(int,QString,QString,int,QString);

    //Getters
    int getid_benevol(){return id_benevol;}
    QString getnom_benevol(){return nom_benevol;}
    QString getprenom_benevol(){return prenom_benevol;}
    int gettel_benevol(){return tel_benevol;}
    QString getadresse_benevol(){return adresse_benevol;}

    //Setters
    void setid_benevol(int i){ id_benevol = i;}
    void setnom_benevol(QString n){ nom_benevol = n;}
    void setprenom_benevol(QString p){ prenom_benevol = p;}
    void settel_benevol(int t){ tel_benevol = t;}
    void setadresse_benevol(QString a){ adresse_benevol = a;}

    //Fonctionalités de base relatives a l'entité benevol
    QSqlQueryModel * afficher();
    bool Ajouter();
    bool supprimer();
    benevol SelectModif();
    bool Modifier( );

    void  PDF();

       QSqlQueryModel * rechercher(QString);

       QSqlQueryModel * trier_id_benevol();
       QSqlQueryModel * trier_nom_benevol();
       QSqlQueryModel * trier_prenom_benevol();
       QSqlQueryModel * trier_tel_benevol();
       QSqlQueryModel * trier_adresse_benevol();



};
class participer
{
private:
    int id_benevol,id_event,count;
public:
       QSqlQueryModel * membermoi();
       int get_benevol(){return id_benevol;}
       int get_count(){return count;}
       void set_idben(int ben){this->id_benevol=ben;}
       void set_count(int coun){this->count=coun;}

};


#endif // BENEVOL_H
