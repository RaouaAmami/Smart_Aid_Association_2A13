#include "parking.h"
#include <QDebug>

parking::parking()
{

}

bool parking::verifier(QString PW)
{
    QSqlQuery query;
    QString res= PW;
    query.prepare("SELECT * FROM BENEVOLS WHERE ID_BENEVOL=:ID_EMP;");
    query.bindValue(":ID_EMP",PW);
    qDebug() << query.last();

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
