#include "connection.h"
#include <QMessageBox>



Connection::Connection(){}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("ra");
db.setPassword("rania");

if (db.open()) test=true;

    return  test;
}

void Connection::closeConnection(){  db.close();}
