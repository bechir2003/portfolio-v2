#include "participant.h"
#include "gestion_participant.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>


Participant::Participant()
{
  nom="";prenom="";email="";adresse="";sexe="";date_naiss=QDate::currentDate();CIN=0;num_tel=00000000;

}
Participant::Participant(int CIN,QString nom,QString prenom,QDate date_naiss, QString adresse,int num_tel,QString sexe,QString email)
{

    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->adresse=adresse;
    this->date_naiss=date_naiss;
    this->sexe=sexe;
    this->num_tel=num_tel;

}

QString Participant::get_nom(){return nom;}
QString Participant::get_prenom(){return prenom;}
QString Participant::get_email(){return email;}
QString Participant::get_adresse(){return adresse;}
QString Participant::get_sexe(){return sexe;}

int Participant::get_CIN(){return CIN;}

int Participant::get_numTel(){return num_tel;}

QDate Participant::get_date(){return date_naiss;}

void Participant::set_nom(QString nom){this->nom=nom;}

void Participant::set_prenom(QString prenom){this->prenom=prenom;}

void Participant::set_email(QString email){this->email=email;}

void Participant::set_adresse(QString adresse){this->adresse=adresse;}

void Participant::set_sexe(QString sexe){this->sexe=sexe;}

void Participant::set_CIN(int CIN){this->CIN=CIN;}

void  Participant::set_numTel(int num_tel){this->num_tel=num_tel;}

void Participant::set_date(QDate date_naiss) {this->date_naiss=date_naiss;
}
QSqlQueryModel* Participant::afficher()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM PARTICIPANT ");

     return model;
}
bool Participant::supprimer(int CIN)
{
    QSqlQuery sql;
    sql.prepare("DELETE FROM PARTICIPANT WHERE CIN=:CIN");
    sql.bindValue(":CIN",CIN);
    return  sql.exec();
}
bool Participant::ajouter_P() {
    QSqlQuery query;
    query.prepare("INSERT INTO PARTICIPANT (CIN, NOM, PRENOM, DATE_NAISS, ADRESSE, NUM_TEL, SEXE, EMAIL) "
                      "VALUES (:CIN, :nom, :prenom, :date_naiss, :adresse, :num_tel, :sexe, :email)");
    query.bindValue(":CIN", CIN);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naiss", date_naiss);
     query.bindValue(":adresse", adresse);
     query.bindValue(":num_tel", num_tel);
     query.bindValue(":sexe", sexe);
    query.bindValue(":email", email);

    return query.exec();

}
bool Participant::ModifierParticipant(Participant P,int CIN) {
    QSqlQuery query;
    query.prepare("UPDATE PARTICIPANT SET nom=:nom, prenom=:prenom, date_naiss=:date_naiss, adresse=:adresse, num_tel=:num_tel, sexe=:sexe, email=:email WHERE CIN=:CIN");
    query.bindValue(":nom",P.get_nom());
    query.bindValue(":prenom", P.get_prenom());
    query.bindValue(":date_naiss", P.get_date());
    query.bindValue(":adresse",P.get_adresse());
    query.bindValue(":num_tel", P.get_numTel());
    query.bindValue(":sexe", P.get_sexe());
    query.bindValue(":email", P.get_email());
    query.bindValue(":CIN", CIN);

    return query.exec();
}
