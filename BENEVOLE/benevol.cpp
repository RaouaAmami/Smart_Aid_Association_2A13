#include "benevol.h"


benevol::benevol()
{
    id_benevol=0;
    nom_benevol="";
    prenom_benevol="";
    tel_benevol=0;
    adresse_benevol="";


}
benevol::benevol(int id_benevol, QString nom_benevol, QString prenom_benevol, int tel_benevol, QString adresse_benevol )
{
    this->id_benevol=id_benevol;
    this->nom_benevol=nom_benevol;
    this->prenom_benevol=prenom_benevol;
    this->tel_benevol=tel_benevol;
    this->adresse_benevol=adresse_benevol;
}

bool benevol::Ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_benevol);
    //prepare() prend la requete en paramétre pour la préparer a l'éxecution .
    query.prepare("INSERT INTO benevols (id_benevol,nom_benevol,prenom_benevol,tel_benevol,adresse_benevol) values (:id_benevol,:nom_benevol,:prenom_benevol,:tel_benevol,:adresse_benevol)");
    //Création des variables liées
    query.bindValue(":id_benevol" ,res);
    query.bindValue(":nom_benevol" ,nom_benevol);
    query.bindValue(":prenom_benevol" ,prenom_benevol);
    query.bindValue(":tel_benevol" ,tel_benevol);
    query.bindValue(":adresse_benevol" ,adresse_benevol);

    return query.exec();//exec() envoie la requete pour l'éxécuter
}
QSqlQueryModel * benevol::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM benevols");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_benevol"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_benevol"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom_benevol"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("tel_benevol"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("adresse_benevol"));

    return model;
}
bool benevol::supprimer(int id_benevol)
{
        QSqlQuery query;
        QString res=QString::number(id_benevol);
        query.prepare("delete from benevols where ID_BENEVOL=id_benevol");
        query.bindValue(":id_benevol",res);

        return query.exec();
}

bool benevol::modifier(int, QString, QString, int, QString)
{
    QSqlQuery query;
        query.prepare( "UPDATE benevols SET id_benevol,nom_benevol,prenom_benevol,tel_benevol,adresse_benevol " );

        query.bindValue(":id_benevol" ,"res");
        query.bindValue(":nom_benevol" ,"nom_benevol");
        query.bindValue(":prenom_benevol" ,"prenom_benevol");
        query.bindValue(":tel_benevol" ,"tel_benevol");
        query.bindValue(":adresse_benevol" ,"adresse_benevol");

        return    query.exec();
}
