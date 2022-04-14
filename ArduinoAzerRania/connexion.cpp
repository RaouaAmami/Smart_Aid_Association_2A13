#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Azer");//inserer nom de l'utilisateur
db.setPassword("Azer");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}



