#include "charite.h"
#include "gestion_charite.h"
#include "ui_gestion_charite.h"
#include <QMessageBox>
#include <iostream>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

Charite::Charite()
{
      destination=""; montant=0; dateDonation =QDate::currentDate(); methodeDonation=""; contact=""; statut="";
}

Charite::Charite( QString destination, float montant, QDate dateDonation, QString methodeDonation, QString contact, QString statut)
    : destination(destination), montant(montant), dateDonation(dateDonation), methodeDonation(methodeDonation), contact(contact), statut(statut){}

// Getters
QString Charite::get_destination() { return destination; }
float Charite::get_montant() { return montant; }
QDate Charite::get_dateDonation() { return dateDonation; }
QString Charite::get_methodeDonation() { return methodeDonation; }
QString Charite::get_contact() { return contact; }
QString Charite::get_statut() { return statut; }

// Setters
void Charite::set_destination(QString destination) { this->destination = destination; }
void Charite::set_montant(float montant) { this->montant = montant; }
void Charite::set_dateDonation(QDate dateDonation) { this->dateDonation = dateDonation; }
void Charite::set_methodeDonation(QString methodeDonation) { this->methodeDonation = methodeDonation; }
void Charite::set_contact(QString contact) { this->contact = contact; }
void Charite::set_statut(QString statut) { this->statut = statut; }




bool Charite::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CHARITES ( DESTINATION, MONTANT, DATE_D, METHODE, CONTACT, STATUT) "
                  "VALUES (:DESTINATION, :MONTANT, :DATE_D, :METHODE, :CONTACT, :STATUT)");
    query.bindValue(":DESTINATION", destination);
    query.bindValue(":MONTANT", QVariant(static_cast<double>(montant)));
    query.bindValue(":DATE_D", dateDonation);
    query.bindValue(":METHODE", methodeDonation);
    query.bindValue(":CONTACT", contact);
    query.bindValue(":STATUT", statut);

    if (query.exec())
    {
        qDebug() << "Charité ajoutée avec succès";
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de l'ajout de la charité :" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Charite::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CHARITES");
    return model;
}

bool Charite::supprimer(int num_charite)
{
    QSqlQuery sql;
    sql.prepare("DELETE FROM CHARITES WHERE NUM_CHARITE=:NUM_CHARITE");
    sql.bindValue(":NUM_CHARITE",num_charite);
    return  sql.exec();
}

bool Charite::Modifier(Charite C, int num_charite) {
    QSqlQuery query;
    query.prepare("UPDATE CHARITES SET DESTINATION=:destination, MONTANT=:montant, DATE_D=:dateDonation, METHODE=:methodeDonation, CONTACT=:contact, STATUT=:statut WHERE NUM_CHARITE=:num_charite");
    query.bindValue(":destination", C.get_destination());
    query.bindValue(":montant", QVariant(static_cast<double>(C.get_montant()))); // Conversion en float
    query.bindValue(":dateDonation", C.get_dateDonation());
    query.bindValue(":methodeDonation", C.get_methodeDonation());
    query.bindValue(":contact", C.get_contact());
    query.bindValue(":statut", C.get_statut());
    query.bindValue(":num_charite", num_charite);

    return query.exec();
}


float Charite::somme_tot_charite()
{
    QSqlQuery query;
    query.exec("SELECT SUM(MONTANT) AS MONTANT_TOTAL FROM CHARITES");
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0.0;
}

int Charite::recuperer_num_charite()
{
    int num = 0;
    QSqlQuery query("SELECT NUM_CHARITE FROM CHARITES");
    // Récupération des données
    if (query.next()) {
        num = query.value(0).toInt();
    }
    return num;
}


/*float Charite::recuperer_solde_caisse()
{
    float solde = 0;
       QSqlQuery query;
       if (query.exec("SELECT SOLDE_C AS solde_caisse "
                      "FROM CAISSE  ")) {
           if (query.next()) {
               solde = query.value("solde_caisse").toFloat();
           } else {
               qDebug() << "Aucun résultat trouvé.";
           }
       } else {
           qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
       }

       return solde;
}*/

float Charite::recuperer_solde_caisse()
{
    float SommeAchat = 0;
    float SommeDesti = 0;
       QSqlQuery query;
       if (query.exec("SELECT sum(prix) "
                      "FROM His_achat  ")) {
           if (query.next()) {
               SommeAchat = query.value(0).toFloat();
               qDebug() << SommeAchat;
           } else {
               qDebug() << "Aucun résultat trouvé.";
           }
       } else {
           qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
       }

       QSqlQuery query1;
       if (query1.exec("SELECT sum(montant) "
                      "FROM charites  ")) {
           if (query1.next()) {
               SommeDesti = query1.value(0).toFloat();
               qDebug() << SommeDesti;
           } else {
               qDebug() << "Aucun résultat trouvé.";
           }
       } else {
           qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
       }

       return SommeAchat - SommeDesti ;
}

float Charite::dernier_montant()
{
    QSqlQuery query;
    query.exec("SELECT montant AS MONTANT_TOTAL FROM CHARITES WHERE NUM_CHARITE = (SELECT MAX(NUM_CHARITE) FROM CHARITES)");
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0.0;
}

void Charite::nouveau_solde_caisse()
{
    QSqlQuery query;
       query.prepare("UPDATE CAISSE SET SOLDE_C = SOLDE_C - :latest_amount");
       query.bindValue(":latest_amount", QVariant::fromValue(static_cast<double>(dernier_montant())));
       if (query.exec()) {
           qDebug() << "Solde mis à jour";
       } else {
           qDebug() << "Erreur lors de la mise à jour du solde";
           qDebug() << query.lastError().text();
       }
}
