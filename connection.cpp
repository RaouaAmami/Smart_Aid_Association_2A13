#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_Desktop_2A13");
db.setUserName("Feres");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}


/*#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
   bool test=false;
   db.setDatabaseName("Projet_Desktop_2A13");
   db.setUserName("Feres");
   db.setPassword("0000");
   if (db.open()) test=true;

   return test;
}

void Connection::closeConnection(){db.close();}*/
