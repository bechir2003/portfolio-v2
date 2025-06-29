#include "connexion_bd.h"

connexion_bd::connexion_bd()
{

}

bool connexion_bd::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("nnoobb");
    db.setPassword("b");

    if (db.open())
        test=true;

    return  test;
}
