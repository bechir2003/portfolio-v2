#ifndef OEUVRE_H
#define OEUVRE_H
#include <iostream>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Oeuvre
{
public:
    Oeuvre();
    Oeuvre(int,QString,QString,float,QString,int);
    static QSqlQueryModel*  afficher_Oeuvre();
    bool Ajouter_Oeuvre();
    bool Modifier_Oeuvre(Oeuvre O,int id);
    bool Effacer_Oeuvre(int id);

    QString getNomArtiste(){return Nom_artiste;};
    QString getEtat(){return etat;};
    QString getType(){return type;};
    float getPrix(){return prix;};
    int getEvent(){return id_e;};

    void getNomArtiste(QString Nom_artiste){this->Nom_artiste=Nom_artiste;};
    void getEtat(QString etat){this->etat=etat;};
    void getType(QString type){this->type=type;};
    void getPrix(float prix){this->prix=prix;};


private:
    QString Nom_artiste,etat,type;
    int Id_o,id_e;
    float prix;
};

#endif // OEUVRE_H
