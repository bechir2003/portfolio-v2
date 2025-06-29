#ifndef PARTICIPATION_H
#define PARTICIPATION_H
#include <QSqlQueryModel>

class Participation
{
public:
    Participation();
    Participation(int, int);
    bool ajouter_Participation();
    bool existance_p(int,int);
    static QSqlQueryModel* afficher();
    static bool supprimer(int);
    int  get_id_e();
    int  get_id_p();
    void set_id_e(int);
    void set_id_p(int);
private:
    int id_p,id_e;
};

#endif // PARTICIPATION_H
