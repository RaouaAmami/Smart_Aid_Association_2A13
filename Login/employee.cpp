#include "employee.h"
#include "connection.h"
#include "QSqlDatabase"
#include<QtDebug>
#include <QObject>
#include <QMessageBox>

employee::employee(int ID_EMP,QString nom,QString prenom,int CIN,QString role,QString mail)
{
        this->ID_EMP=ID_EMP;
        this->nom=nom;
        this->prenom=prenom;
        this->CIN=CIN;
        this->role=role;
        this->mail=mail;

}

bool employee::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_EMP);
    query.prepare("INSERT INTO EMPLOYEES (ID_EMP,NOM,PRENOM,CIN,ROLE,MAIL)" "VALUES (:ID_EMP,:NOM,:PRENOM,:CIN,:ROLE,:MAIL)");

    query.bindValue(":ID_EMP",res);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":CIN",CIN);
    query.bindValue(":ROLE",role);
    query.bindValue(":MAIL",mail);

    return query.exec();
}

QSqlQueryModel * employee::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMP"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

bool employee::supprimer(int ID_EMP)
{
    QSqlQuery query;
    QString res=QString::number(ID_EMP);
    query.prepare("DELETE FROM EMPLOYEES WHERE ID_EMP=:ID_EMP");
    query.bindValue(":ID_EMP",res);
    return query.exec();
}

bool employee::modifier()
{
    QSqlQuery query;
    QString res = QString::number(ID_EMP);
    query.prepare("UPDATE EMPLOYEES SET NOM=:NOM,PRENOM=:PRENOM,CIN=:CIN,ROLE=:ROLE,MAIL=:MAIL where ID_EMP=:ID_EMP");

    query.bindValue(":ID_EMP",res);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":CIN",CIN);
    query.bindValue(":ROLE",role);
    query.bindValue(":MAIL",mail);

    return query.exec();
}

QSqlQueryModel * employee::rechercher(QString mot)
{
     QSqlQuery query;
     query.prepare("SELECT * FROM EMPLOYEES where ((ID_EMP like :NOMC) or (NOM like :NOMC) or (PRENOM like :NOMC) or "
        "(CIN like :NOMC))");
     query.bindValue(":NOMC", mot);
     query.exec();

    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery(query);


    return model;
}


QSqlQueryModel * employee::afficherTri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES order by ID_EMP ASC");//asc c ascendant
    return model;
}



QSqlQueryModel * employee::afficherTri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES order by NOM ASC");//asc c ascendant
    return model;
}


QSqlQueryModel * employee::afficherTri_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES order by PRENOM ASC");//asc c ascendant
    return model;
}



QSqlQueryModel * employee::afficherTri_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYEES order by CIN ASC");//asc c ascendant
    return model;
}

void employee::exporterpdff(QTextBrowser *text)
{
  // QString tt;
    QSqlQuery qry;
    std::list<QString> tt;
    qry.exec("SELECT * FROM EMPLOYEES");
    while(qry.next())
    {
        tt.push_back("ID_EMP: "+qry.value(1).toString()+"\n"+"NOM: "+qry.value(1).toString()+"\n"+"PRENOM: "+qry.value(2).toString()+"\n"+"CIN: "+qry.value(3).toString()+"\n"+"MAIL: "+qry.value(4).toString()+"\n"+"ROLE: "+qry.value(5).toString());

    }

    for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
    {
    text->setText(*it);
    }

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    text->print(&printer);
}
QString employee::login(QString us, QString pw)
{
   /* QSqlQuery query;
    query.prepare("SELECT * FROM LOGIN where USERNAME=:USERNAME and PASSWORD=:PASSWORD");
    query.bindValue(":USERNAME", us);
    query.bindValue(":PASSWORD", pw);
    query.exec();*/


            bool exists = false;

            QSqlQuery query;
            QString page ;
            query.prepare("SELECT PAGE FROM LOGIN WHERE USERNAME = (:un) AND PASSWORD = (:pw)");
            query.bindValue(":un", us);
            query.bindValue(":pw", pw);

            if (query.exec())
            {
                if (query.next())
                {
                    exists = true;
                    page=query.value(0).toString();

                }
            }

            return page;





}

