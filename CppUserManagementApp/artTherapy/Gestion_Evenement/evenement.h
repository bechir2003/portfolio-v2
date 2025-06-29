#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Evenement
{

public:
    Evenement();
    Evenement(int,QString,QString,QDate,QDate,QString,QString,int);
    bool ajouter_E();
    static QSqlQueryModel* afficher();
    static bool supprimer(int ide);
    bool Modifier(Evenement K,int ide);
    int getIde() ;
    void setIde(int ide);
    QString getNomevent()const ;
    QString getLieu()const  ;
    QDate getDatedeb() const;
    QDate getDatefin() const;
    QString getDescription()const  ;
    QString getStatut()const  ;
    int getCapacite() const ;
        void setNomevent( QString nomevent);
        void setLieu( QString lieu);
        void setDatedeb( QDate datedeb);
        void setDatefin( QDate datefin);
        void setDescription( QString description);
        void setStatut( QString statut);
        void setCapacite(int capacite);
static QList<Evenement> getListeEvenements();
QList<Evenement> getEvenementsPourDate(const QDate &date);

private:
    int ide;
    QString nomevent;
    QString lieu;
    QDate datedeb;
    QDate datefin;
    QString description;
    QString statut;
    int capacite;
};

#endif // EVENEMENT_H
