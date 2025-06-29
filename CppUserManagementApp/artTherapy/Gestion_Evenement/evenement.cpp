#include "evenement.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>



Evenement::Evenement()
{
   ide=0; nomevent=""; lieu=""; datedeb =QDate();datefin =QDate() ; description=""; statut=""; capacite=0;
}


Evenement::Evenement(int ide, QString nomevent, QString lieu, QDate datedeb, QDate datefin, QString description, QString statut,int capacite)
    : ide(ide), nomevent(nomevent), lieu(lieu), datedeb(datedeb), datefin(datefin), description(description), statut(statut), capacite(capacite) {}

int Evenement::getIde()  {
        return ide;
    }
QString Evenement::getNomevent()const  {
        return nomevent;
    }

    QString Evenement::getLieu()const  {
        return lieu;
    }

    QDate Evenement::getDatedeb()const {
        return datedeb;
    }

    QDate Evenement::getDatefin()const {
        return datefin;
    }

    QString Evenement::getDescription() const {
        return description;
    }

    QString Evenement::getStatut()const  {
        return statut;
    }

    int Evenement::getCapacite()  const {
        return this->capacite;
    }

    void Evenement::setIde(int ide){
        this->ide=ide;
    }
void Evenement::setNomevent( QString nomevent) {
        this->nomevent = nomevent;
    }

    void Evenement::setLieu( QString lieu) {
        this->lieu = lieu;
    }

    void Evenement::setDatedeb( QDate datedeb) {
        this->datedeb = datedeb;
    }

    void Evenement::setDatefin( QDate datefin) {
        this->datefin = datefin;
    }

    void Evenement::setDescription( QString description) {
        this->description = description;
    }

    void Evenement::setStatut( QString statut) {
        this->statut = statut;
    }

   void Evenement::setCapacite(int capacite)
   {
       this->capacite = capacite;
   }



bool Evenement::ajouter_E(){
    QSqlQuery query;
       query.prepare("INSERT INTO evenement ( ide, NOM, LIEU, DATEDEB, DATEFIN, DESCRIPTION, STATUT, CAPACITE) "
                     "VALUES  (NULL, :NOMEVENT , :LIEU, :DATEDEB, :DATEFIN, :DESCRIPTION, :STATUT, :CAPACITE)");

        query.bindValue(":NOMEVENT", nomevent);
        query.bindValue(":LIEU", lieu);
        query.bindValue(":DATEDEB",datedeb);
        query.bindValue(":DATEFIN", datefin);
        query.bindValue(":DESCRIPTION", description);
        query.bindValue(":STATUT",statut);
        query.bindValue(":CAPACITE",capacite);
        if (query.exec())
            {
                qDebug() << "event ajoutée avec succès";
                return true;
            }
            else
            {
                qDebug() << "Erreur lors de l'ajout de l'évènement :" << query.lastError().text();
                return false;
            }
}


QSqlQueryModel* Evenement::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
       model->setQuery("SELECT * FROM evenement");
       return model;
}

bool Evenement::supprimer(int ide)
{
    QSqlQuery sql;
    sql.prepare("DELETE FROM evenement WHERE IDE=:IDE");
    sql.bindValue(":IDE",ide);
    return  sql.exec();
}

bool Evenement::Modifier(Evenement E, int ide) {
    QSqlQuery query;
    query.prepare("UPDATE evenement SET NOM=:nomevent, LIEU=:lieu, DATEDEB=:datedeb, DATEFIN=:datefin,DESCRIPTION=:description, STATUT=:statut, CAPACITE=:capacite WHERE IDE=:ide");
    query.bindValue(":nomevent", E.getNomevent());
    query.bindValue(":lieu", E.getLieu());
    query.bindValue(":datedeb", E.getDatedeb());
    query.bindValue(":datefin", E.getDatefin());
    query.bindValue(":description", E.getDescription());
    query.bindValue(":statut", E.getStatut());
    query.bindValue(":capacite", E.getCapacite());
    query.bindValue(":ide", ide);

    return query.exec();
}

QList<Evenement> Evenement::getListeEvenements()
{
    QList<Evenement> listeEvenements;
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM EVENEMENT");
    for (int i = 0; i < model->rowCount(); i++) {
        int ide = model->data(model->index(i, 0)).toInt();
        QString nomevent = model->data(model->index(i, 1)).toString();
        QString lieu = model->data(model->index(i, 2)).toString();
        QDate datedeb = model->data(model->index(i, 3)).toDate();
        QDate datefin = model->data(model->index(i, 4)).toDate();
        QString description = model->data(model->index(i, 5)).toString();
        QString statut = model->data(model->index(i, 6)).toString();
        int capacite = model->data(model->index(i, 7)).toInt();
        listeEvenements.append(Evenement( ide,nomevent, lieu, datedeb, datefin, description, statut, capacite));
    }
    return listeEvenements;
}

QList<Evenement> Evenement::getEvenementsPourDate(const QDate &date)
{
    QList<Evenement> listeEvenements;
    QSqlQuery query;
    query.prepare("SELECT * FROM EVENEMENT WHERE DATEDEB <= :date AND DATEFIN >= :date");
    query.bindValue(":date", date);

    if (query.exec()) {
        while (query.next()) {
            int ide = query.value(0).toInt();
            QString nomevent = query.value(1).toString();
            QString lieu = query.value(2).toString();
            QDate datedeb = query.value(3).toDate();
            QDate datefin = query.value(4).toDate();
            QString description = query.value(5).toString();
            QString statut = query.value(6).toString();
            int capacite = query.value(7).toInt();

            Evenement evenement(ide,nomevent, lieu, datedeb, datefin, description, statut, capacite);
            listeEvenements.append(evenement);
        }
    } else {
        qDebug() << "Erreur lors de la récupération des événements pour la date spécifiée :" << query.lastError().text();
    }

    return listeEvenements;
}



