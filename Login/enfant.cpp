#include "enfant.h"

enfant::enfant()
{


}
bool enfant::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO ENFANTS (ID_E,NOME,PRENOME,DATE_NAISS,DATEINS,GENRE,PHOTO)" "values(:id,:nom,:prenom,:date_n,:date_ins,:genre,:photo)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_n",date_n);
    query.bindValue(":date_ins",date_ins);
    query.bindValue(":genre",genre);
    query.bindValue(":photo",photo);


    return query.exec();
}
QSqlQueryModel * enfant::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ENFANTS ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEINS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("GENRE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("PHOTO"));




    model->setQuery("SELECT ID_E,NOME,PRENOME,DATE_NAISS,DATEINS FROM ENFANTS");
    return model;

}
bool enfant::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from ENFANTS where ID_E = :id ");
    query.bindValue(":id",id);
    return query.exec();
}
bool enfant::modifier(QString id)
{

    QSqlQuery query;



    query.prepare("UPDATE ENFANTS SET NOME = :nom,PRENOME = :prenom ,DATE_NAISS = :date_n ,DATEINS = :date_ins,GENRE= :genre, PHOTO= :photo WHERE ID_E = :id ");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    query.bindValue(":date_n",date_n);
    query.bindValue(":date_ins",date_ins);
    query.bindValue(":genre",genre);
    query.bindValue(":photo",photo);

    return query.exec();




}
QSqlQueryModel * enfant::recherche(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM ENFANTS WHERE ID_E LIKE '%"+id+"%'");
    model->query().bindValue(":id",id);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEINS"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("GENRE"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("PHOTO"));




    return model;
}
QSqlQueryModel * enfant::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from ENFANTS ORDER BY ID_E DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_NAISS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEINS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("GENRE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("PHOTO"));


    return model;
}





