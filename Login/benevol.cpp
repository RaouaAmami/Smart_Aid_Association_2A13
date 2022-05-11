#include "benevol.h"
#include "connection.h"
#include "QSqlDatabase"
#include<QtDebug>
#include <QSqlQuery>
#include <QPdfWriter>
//#include <QPrinter>
//#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QPainter>

#include <QProgressBar>
#include <QSlider>


benevol ::benevol()
{
    id_benevol=0;
    nom_benevol=" ";
    prenom_benevol=" ";
    tel_benevol=0;
    adresse_benevol=" ";


}
benevol ::benevol(int id_benevol, QString nom_benevol, QString prenom_benevol, int tel_benevol, QString adresse_benevol )
{
    this->id_benevol=id_benevol;
    this->nom_benevol=nom_benevol;
    this->prenom_benevol=prenom_benevol;
    this->tel_benevol=tel_benevol;
    this->adresse_benevol=adresse_benevol;
}
QSqlQueryModel * benevol::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BENEVOLS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_benevol"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_benevol"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom_benevol"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel_benevol"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse_benevol"));

    return model;
}
bool benevol::Ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_benevol);
    //prepare() prend la requete en paramétre pour la préparer a l'éxecution .
    query.prepare("INSERT INTO BENEVOLS (id_benevol,nom_benevol,prenom_benevol,tel_benevol,adresse_benevol) values (:id_benevol,:nom_benevol,:prenom_benevol,:tel_benevol,:adresse_benevol)");
    //Création des variables liées
    query.bindValue(":id_benevol" ,res); //binvalue Associe une valeur à un paramètre
    query.bindValue(":nom_benevol" ,nom_benevol);
    query.bindValue(":prenom_benevol" ,prenom_benevol);
    query.bindValue(":tel_benevol" ,tel_benevol);
    query.bindValue(":adresse_benevol" ,adresse_benevol);

    return query.exec();//exec() envoie la requete pour l'éxécuter
}

bool benevol::supprimer(QString id_benevol)
{
        QSqlQuery query;
        QString res= id_benevol;
        query.prepare("DELETE FROM benevols where ID_BENEVOL=:id_benevol");
        query.bindValue(":id_benevol",res);

        return query.exec();
}





benevol benevol ::SelectModif()
{

    QSqlQuery query;
    QString res=QString::number(id_benevol);
    query.prepare("Select * from BENEVOLS  where id_benevol=:id_benevol ");
    query.bindValue(":id_benevol",res);
    query.exec(); //exec pour executer requette
    query.next();


    int id_benevolval=query.value(0).toInt(); //recuperer les donnees de la bd
    QString nom_benevolval=query.value(1).toString();
    QString prenom_benevolval=query.value(2).toString();
    int tel_benevolval=query.value(3).toInt();
    QString adresse_benevolval=query.value(4).toString();
    benevol Ben (id_benevolval,nom_benevolval,prenom_benevolval,tel_benevolval,adresse_benevolval);
    return Ben;
}

bool benevol::Modifier()
{
    QSqlQuery query;
        query.prepare("UPDATE BENEVOLS SET id_benevol= :id_benevol,nom_benevol= :nom_benevol,prenom_benevol=:prenom_benevol,"
                      "tel_benevol= :tel_benevol,"
                      "adresse_benevol=:adresse_benevol WHERE id_benevol = :id_benevol");
        query.bindValue(":id_benevol", id_benevol);
        query.bindValue(":nom_benevol",nom_benevol );
        query.bindValue(":prenom_benevol", prenom_benevol);
        query.bindValue(":tel_benevol", tel_benevol);
        query.bindValue(":adresse_benevol", adresse_benevol);

        return    query.exec();
}
void  benevol::PDF(){


                     QPdfWriter pdf("C:\\import.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"GESTION BENEVOL");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"ID_BENEVOL");
                         painter.drawText(1300,3300,"NOM_BENEVOL");
                         painter.drawText(2200,3300,"PRENOM_BENEVOL");
                         painter.drawText(3200,3300,"TEL_BENEVOL");
                         painter.drawText(5300,3300,"ADRESSE_BENEVOL");

                         QSqlQuery query;
                        // query.prepare("select * from BENEVOLS where cin='"+val+"'");
                         query.prepare("select * from BENEVOLS");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(3).toString());
                             painter.drawText(5300,i,query.value(4).toString());


                            i = i + 500;
                         }}



QSqlQueryModel * benevol::rechercher(QString mot)
{
    QSqlQueryModel * model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM BENEVOLS where id_benevol="+mot);
    return model;
}

QSqlQueryModel * benevol::trier_id_benevol()
{
    QSqlQuery *qry=new QSqlQuery();
       QSqlQueryModel *model=new QSqlQueryModel();
       qry->prepare("select * from BENEVOLS order by ID_BENEVOL ASC");
       qry->exec();
       model->setQuery(*qry);
       return model;
}
QSqlQueryModel * benevol::trier_nom_benevol()
{
    QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from BENEVOLS order by NOM_BENEVOL ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
}
QSqlQueryModel * benevol::trier_prenom_benevol()
{
    QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from BENEVOLS order by PRENOM_BENEVOL ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
}
QSqlQueryModel * benevol::trier_tel_benevol()
{
    QSqlQuery *qry=new QSqlQuery();
       QSqlQueryModel *model=new QSqlQueryModel();
       qry->prepare("select * from BENEVOLS order by TEL_BENEVOL ASC");
       qry->exec();
       model->setQuery(*qry);
       return model;
}
QSqlQueryModel * benevol::trier_adresse_benevol()
{
    QSqlQuery *qry=new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from BENEVOLS order by ADRESSE_BENEVOL ASC");
        qry->exec();
        model->setQuery(*qry);
        return model;
}

  QSqlQueryModel * participer::membermoi()
  {
      QSqlQueryModel * model=new QSqlQueryModel();
           model->setQuery("select count(id_benevol),id_benevol from participer group by id_benevol order by count(id_benevol) desc");
                 set_count(model->data(model->index(0, 0)).toInt());
                    set_idben(model->data(model->index(0, 1)).toInt());
           return model ;

  }












