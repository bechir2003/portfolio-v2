#ifndef CONNEXION_BD_H
#define CONNEXION_BD_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion_bd
{
public:
    connexion_bd();
    bool createconnect();
};

#endif // CONNEXION_BD_H



