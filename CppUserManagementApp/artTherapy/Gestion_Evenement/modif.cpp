#include "modif.h"
#include "Gestion_Evenement/evenement.h"
#include "ui_modif.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
modif::~modif()
{
    delete ui;
}
modif::modif(QWidget *parent, int ide) : QDialog(parent), ui(new Ui::modif), ide(ide) {
    ui->setupUi(this);

    QStringList statutOptions = {"En cours", "Planifie", "Termine", "Annule"};
    ui->comboBox->addItems(statutOptions);

    QIntValidator *capaciteValidator = new QIntValidator(0, 9999, this);
    ui->capacite->setValidator(capaciteValidator);

    connect(ui->modifier, &QPushButton::clicked, this, &modif::verifierCapacite);

    ui->datedeb->setDate(QDate::currentDate());
    ui->datefin->setDate(QDate::currentDate());

    ui->nomevent->setPlaceholderText("Entrez le nom de l'événement");
    ui->description->setPlaceholderText("Entrez la description de l'événement");

    QRegExpValidator *validator = new QRegExpValidator(QRegExp("[a-zA-Z]+"), this);
    ui->nomevent->setValidator(validator);
    ui->description->setValidator(validator);

    QDateEdit *dateFinEdit = ui->datefin;

    connect(ui->datedeb, &QDateEdit::dateChanged, [dateFinEdit](const QDate &date) {
        dateFinEdit->setMinimumDate(date);
    });

    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM EVEN WHERE IDE = :IDE");
    query.bindValue(":IDE", ide);

    if (query.exec()) {
        model->setQuery(query);
        if (model->rowCount() > 0) {
            int ide = model->data(model->index(0, 0)).toInt();
            QString nomevent = model->data(model->index(0, 1)).toString();
            QString lieu = model->data(model->index(0, 2)).toString();
            QDate datedeb = model->data(model->index(0, 3)).toDate();
            QDate datefin = model->data(model->index(0, 4)).toDate();
            QString description = model->data(model->index(0, 5)).toString();
            QString statut = model->data(model->index(0, 6)).toString();
            QString capacite = model->data(model->index(0, 7)).toString();


            ui->ide->setText(QString::number(ide));
            ui->nomevent->setText(nomevent);
            ui->lieu->setText(lieu);
            ui->datedeb->setDate(datedeb);
            ui->datefin->setDate(datefin);
            ui->description->setText(description);
            ui->comboBox->setCurrentText(statut);
            ui->capacite->setText(capacite);
        } else {
            qDebug() << "No event found with ide" << ide;
        }
    }
}



void modif::on_modifier_clicked()
{
    if (!validerChamps()) {
            return;
        }

        int ide = ui->ide->text().toInt();
        QString nomevent = ui->nomevent->text();
        QString lieu = ui->lieu->text();
        QDate datedeb = ui->datedeb->date();
        QDate datefin = ui->datefin->date();
        QString description = ui->description->text();
        QString statut = ui->comboBox->currentText();
        int capacite = ui->capacite->text().toInt();

        Evenement E(ide, nomevent, lieu, datedeb, datefin, description, statut, capacite);

        if (E.Modifier(E, ide)) {
            QMessageBox::information(this, "Succès", "Event modifié avec succès.");
            this->close();
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de modifier l'événement. Vérifiez les champs et réessayez.");
        }
    }

    bool modif::validerChamps() {
        if (ui->nomevent->text().isEmpty() || ui->lieu->text().isEmpty() || ui->description->text().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
            return false;
        }

        return true;
    }
void modif::verifierCapacite() {
    bool isValid;
    int capaciteValue = ui->capacite->text().toInt(&isValid);

    if (!isValid || capaciteValue <= 0) {
        QMessageBox::warning(this, "Erreur", "La capacité doit être un nombre entier positif.");
    }
}
