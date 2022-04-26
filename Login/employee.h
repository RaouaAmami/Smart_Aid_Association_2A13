
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QTextBrowser>
#include <QPrinter>
#include <QDialog>
#include "QFileDialog"


class employee
{
    QString nom, prenom, role, mail;
    int ID_EMP, CIN;
public:
    employee(){}
    employee(int,QString,QString,int,QString,QString);

    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getRole(){return role;}
    QString getMail(){return mail;}
    int getID(){return ID_EMP;}
    int getCIN(){return CIN;}

    void setNom(QString n){nom=n;}

    void setPrenom(QString p){prenom=p;}
    void setRole(QString r){role=r;}
    void setMail(QString m){mail=m;}
    void setID(int ID_EMP){this->ID_EMP=ID_EMP;}

    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher ();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * afficherTri_id();
    QSqlQueryModel * afficherTri_nom();
    QSqlQueryModel * afficherTri_prenom();
    QSqlQueryModel * afficherTri_cin();
    void exporterpdff(QTextBrowser *text);
    QString login(QString us , QString pw);

};

#endif // EMPLOYEE_H
