#ifndef CHARITE_H
#define CHARITE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Charite
{
public:
    Charite();
    Charite(QString , float , QDate , QString , QString , QString );
    bool ajouter();
    static QSqlQueryModel* afficher();
    static bool supprimer(int num_charite);
    bool Modifier(Charite ,int);
    float somme_tot_charite();
    int recuperer_num_charite();
    float recuperer_solde_caisse();
    float dernier_montant();
    void nouveau_solde_caisse();

    QString get_destination();
        float get_montant();
        QDate get_dateDonation();
        QString get_methodeDonation();
        QString get_contact();
        QString get_statut();

        // Setters
        void set_destination(QString destination);
        void set_montant(float montant);
        void set_dateDonation(QDate dateDonation);
        void set_methodeDonation(QString methodeDonation);
        void set_contact(QString contact);
        void set_statut(QString statut);


private:
    QString destination;
    float montant;
    QDate dateDonation;
    QString methodeDonation, contact, statut;
};

#endif // CHARITE_H
