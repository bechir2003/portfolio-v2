#include "participation.h"
#include "gestion_participant.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QSqlError>


Participation::Participation()
{
    id_e=0; id_p=0;
}
Participation::Participation(int id_e,int id_p)
{
    this->id_e=id_e;
    this->id_p=id_p;
}
int Participation::get_id_e(){return id_e;}

int Participation::get_id_p(){return id_p;}

void Participation::set_id_e(int id_e){this->id_e=id_e;}

void  Participation::set_id_p(int id_p){this->id_p=id_p;}

QSqlQueryModel* Participation::afficher()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM PARTICIPATION ");

     return model;
}
bool Participation::supprimer(int id_p)
{
    QSqlQuery sql;

    sql.prepare("DELETE FROM PARTICIPATION WHERE  ID_PARTICIPATION = :ID_P");
    sql.bindValue(":ID_P", id_p);

    return  sql.exec();
}
bool Participation::ajouter_Participation(){
    QSqlQuery query;

    query.prepare("INSERT INTO Participation VALUES (:id_p,:id_e,null)");
    query.bindValue(":id_p",id_p);
    query.bindValue(":id_e",id_e);

    return query.exec();
}

bool Participation::existance_p(int id_e,int id_p){
    QSqlQuery query;

    query.prepare("select * from Participation where id_p=:id_p and id_e=:id_e;");
    query.bindValue(":id_p",id_p);
    query.bindValue(":id_e",id_e);

    query.exec();
    return  query.next();
}
