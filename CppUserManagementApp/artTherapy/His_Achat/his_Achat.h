#ifndef HIS_ACHAT_H
#define HIS_ACHAT_H
#include <QDateTime>
#include <QSqlQueryModel>
#include <QSqlQuery>


class His_Achat
{

    int id_o,id_e,id_p;
    float prix;
    QDateTime date_achat;

public:
    His_Achat();
    His_Achat(int,int,int,QDateTime,float);
    static QSqlQueryModel*  afficher_His_Achat();
    bool ajouter_achat();
    bool existance_p(int,int);

};

#endif // HIS_ACHAT_H
