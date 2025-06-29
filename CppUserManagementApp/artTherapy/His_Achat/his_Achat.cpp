#include "His_Achat/his_achat.h"

His_Achat::His_Achat()
{
    id_e=0;
    id_o=0;
    id_p=0;
    prix=0;
}

His_Achat::His_Achat(int id_e,int id_o,int id_p,QDateTime date_achat,float prix){
    this->id_e=id_e;
    this->id_o=id_o;
    this->id_p=id_p;
    this->prix=prix;
    this->date_achat=date_achat;
}

//BEGIN afficher_Employees
QSqlQueryModel* His_Achat::afficher_His_Achat() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("select e.nom as evenement,id_o as reference_Oeuvre,p.nom as participant,TO_CHAR(date_achat, 'YYYY-MM-DD' ) as date_achat,prix from his_achat h,participant p,evenement e where e.ide=h.id_e and p.cin=h.id_p;");
    return model;
}
//END afficher_Employees

bool His_Achat::ajouter_achat(){   

    /*QSqlQuery query2;

    query2.prepare("UPDATE  caisse set SOLDE_C = :SOLDE + SOLDE_C");
    query2.bindValue(":SOLDE",QVariant(static_cast<double>(prix)));

    query2.exec();
    */

    QSqlQuery query1;

    query1.prepare("UPDATE  oeuvre set etat = :etat where ID_o = :id");
    query1.bindValue(":etat","Non,disponible");
    query1.bindValue(":id",id_o);

    query1.exec();

    QSqlQuery query;

    query.prepare("INSERT INTO his_achat VALUES (:id_o,:id_p,:id_e,:dateachat,NULL,:prix)");

    query.bindValue(":id_o",id_o);
    query.bindValue(":id_p",id_p);
    query.bindValue(":id_e",id_e);
    query.bindValue(":prix",QVariant(static_cast<double>(prix)));
    query.bindValue(":dateachat",QVariant::fromValue<QDateTime>(date_achat));

    return query.exec();
}

bool His_Achat::existance_p(int id_o,int id_p){
    QSqlQuery query;

    query.prepare( "select * from his_achat where id_o=:id_o and id_p=:id_p");

    query.bindValue(":id_o",id_o);
    query.bindValue(":id_p",id_p);

    query.exec();

    return query.next();
}

