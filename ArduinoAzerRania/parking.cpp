#include "parking.h"
#include <QDebug>

parking::parking()
{

}

bool parking::verifier(int ID_EMP)
{
    QSqlQuery query;
    QString res=QString::number(ID_EMP);
    query.prepare("SELECT * FROM EMPLOYEES WHERE ID_EMP=:ID_EMP;");
    query.bindValue(":ID_EMP",res);


    query.exec();
    query.next();
    QString a = query.value(0).toString();
    if(a.size()==0){
        return false;
    }
    else{
        return true;
    }




}
