#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_Desktop_2A13");
db.setUserName("Feres");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateurs

if (db.open())
test=true;





    return  test;
}



