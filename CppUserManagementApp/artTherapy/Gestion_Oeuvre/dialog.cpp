#include "dialog.h"
#include "ui_dialog.h"
#include "oeuvre.h"
#include <QMessageBox>
#include  <iostream>
#include <QSqlQuery>
#include <QDebug>
Dialog::Dialog(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->id = id;
    init_evenement();
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM oeuvre WHERE id_o = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        model->setQuery(query);

        if (model->rowCount() > 0) { // Ensure there is at least one row in the result
            QString NomA = model->data(model->index(0, 1)).toString();
            QString etat = model->data(model->index(0, 4)).toString();
            Etat = etat;
            QString prix = model->data(model->index(0, 3)).toString();
            QString type = model->data(model->index(0, 2)).toString();
            QString event = get_NomEvent (model->data(model->index(0, 5)).toInt());

            if (etat == "Non,disponible") {
                ui->NV->setChecked(true);
            } else{
                ui->V->setChecked(true);
            }

            ui->nom->setText(NomA);
            ui->type->setCurrentText(type);
            ui->prix->setText(prix);
            ui->evenement->setCurrentText(event);

        } else {
            qDebug() << "No Oeuvre found with ID:" << id;
        }
    }

    QRegExpValidator *validatorNum = new QRegExpValidator(QRegExp("[0-9]*"));
    ui->prix->setValidator(validatorNum);

    QRegExpValidator *validatorLet = new QRegExpValidator(QRegExp("[A-Za-z]*"));
    ui->nom->setValidator(validatorLet);
}


Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_Modifier_clicked(){

    QString nomA = ui->nom->text();
    float prix = ui->prix->text().toFloat();
    QString type = ui->type->currentText();
    QString etat = "";
    if(ui->V->isChecked()) {
        etat = "disponible";
    } else {
        etat = "Non,disponible";
    }
    QVariant selectEevenementId = ui->evenement->currentData(Qt::UserRole);
    int selectEevenementIdValue = selectEevenementId.toInt();

    Oeuvre O(0,nomA,type,prix,etat,selectEevenementIdValue);
    if(type.isEmpty() || nomA.isEmpty() || prix<=0){
        QMessageBox::critical(nullptr, QObject::tr("erreur"),QObject::tr("il y a des champs invalide !!"));
        return;
    }
    int ok = 0;
    bool test = false;
    if( Etat == "Non,disponible" && O.getEtat() == "disponible") {
        QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                                 "Cette oeuvre est deja vendu\n"
                                                                                 "Êtes-vous sûr d'Annuler cette Achat?",
                                                                                 QMessageBox::Yes | QMessageBox::No);
        if (confirmation == QMessageBox::Yes) {
            ok = 1;
            test = O.Modifier_Oeuvre(O,id);
        }
    }
    else{
        test = O.Modifier_Oeuvre(O,id);
    }




    if(test) {
        QMessageBox::information(this, "Succès", "Oeuvre modifié avec succès.");
        if(ok == 1) {
            QSqlQuery query;
            query.prepare("Delete from his_Achat WHERE id_o = :id");
            query.bindValue(":id", id);
            query.exec();
        }
        this->close();

     }
     else if(ok != 1){
        QMessageBox::critical(this, "Erreur", "Impossible de modifier l'Oeuvre.");
     }

    ui->nom->clear();
    ui->type->clear();
    ui->prix->clear();
}


void Dialog::on_Annuler_clicked(){
    this->close();

}

void Dialog::init_evenement(){
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select ide,nom from evenement where datefin>sysdate;");
    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex index = model->index(i, 1);
        QString eventName = model->data(index).toString();
        QVariant eventId = model->data(model->index(i, 0), Qt::DisplayRole);
        ui->evenement->addItem(eventName, eventId);
    }

}
QString Dialog::get_NomEvent(int id){
    QSqlQuery query;

    query.prepare("select nom from evenement where ide = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if(query.next()){
            QString event = query.value(0).toString();
            return event;
        }
        return "";
    }
    return "";
}
