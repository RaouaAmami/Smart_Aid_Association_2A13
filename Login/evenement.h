#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString> //bib chaines
#include <QSqlQuery>  //lire les requettes sql
#include <QSqlQueryModel> //est une interface de haut niveau pour exécuter des instructions SQL
#include <QDate>

class evenement
{
    QString libelle,lieu,type;
    int id_event;
    QDate datee;


public:
    evenement(); //constructeur
    evenement(int,QString,QString,QString,QDate);

    int Get_id_event(){return id_event;}
    QString Get_libelle(){return libelle;}
    QString Get_lieu(){return lieu;}
    QString Get_type(){return type;}
    QDate get_datee(){return datee ; }


    void Set_id_event(int id_event){this->id_event=id_event;}
    void Set_libelle(QString libelle){this->libelle=libelle;}
    void Set_lieu(QString lieu){this->lieu=lieu;}
    void Set_type(QString type){this->type=type;}
    void Set_datee(QDate datee){this->datee=datee;}


    bool ajouter();                //ajouter
    QSqlQueryModel * afficher();  //pour afficher dans linterface qt
    bool supprimer(int);          // fama int khtr bsh nfass5o bl id ahna wl id hoa int
    evenement SelectModif(int);
    bool Modifer(int );


           //modifier


QSqlQueryModel * rechercher(QString);

QSqlQueryModel * afficherTri_libelle();
QSqlQueryModel * afficherTri_id();
QSqlQueryModel * afficherTri_lieu();
QSqlQueryModel * afficherTri_type();
QSqlQueryModel * afficherTri_date();


  void pdf(QString,QString);

};
#endif // EVENNEMENT_H
