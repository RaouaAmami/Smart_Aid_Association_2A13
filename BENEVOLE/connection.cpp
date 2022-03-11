#include "connection.h"
#include <QMessageBox>



Connection::Connection(){}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("ra");//inserer nom de l'utilisateur
db.setPassword("rania");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}

void Connection::closeConnection(){  db.close();}
