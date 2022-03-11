
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QSqlQuery>
#include<QSqlQueryModel>


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
    QSqlQueryModel * afficher ();
    bool supprimer(int);
};

#endif // EMPLOYEE_H
