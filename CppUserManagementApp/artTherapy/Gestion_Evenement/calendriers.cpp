#include "calendriers.h"
#include "ui_calendriers.h"
#include <QVBoxLayout>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTextCharFormat>
#include "gestion_evenement.h"
#include "evenement.h"
calendriers::calendriers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendriers)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
        calendarWidget = new QCalendarWidget(this);
        tableWidget = new QTableWidget(this);
        tableWidget->setColumnCount(1);
        QStringList headers;
        headers << "Nom de l'événement";
        tableWidget->setHorizontalHeaderLabels(headers);
        layout->addWidget(calendarWidget);
        layout->addWidget(tableWidget);

        connect(calendarWidget, &QCalendarWidget::selectionChanged, this, &calendriers::on_calendarWidget_selectionChanged);
lastSelectedDate = QDate::currentDate();
        chargerEvenements();
}

calendriers::~calendriers()
{
    delete ui;
}

void calendriers::on_calendarWidget_selectionChanged()
{
    tableWidget->clearContents();
      tableWidget->setRowCount(0);

      // Obtenez la date sélectionnée dans le calendrier
      QDate dateSelectionnee = calendarWidget->selectedDate();

      // Vérifiez si la date sélectionnée a changé depuis la dernière fois
      if (dateSelectionnee != lastSelectedDate) {
          // Mettre à jour la variable de classe pour la dernière date sélectionnée
          lastSelectedDate = dateSelectionnee;

          // Créer un objet Kenza pour accéder à la fonction getEvenementsPourDate
          Evenement kenza;

          // Obtenez les événements pour la date sélectionnée depuis la base de données
          QList<Evenement> listeEvenements = kenza.getEvenementsPourDate(dateSelectionnee);

          // Affichez les événements dans le QTableWidget
          int row = 0;
          for (const Evenement &evenement : listeEvenements) {
              tableWidget->insertRow(row);
              tableWidget->setItem(row, 0, new QTableWidgetItem(evenement.getNomevent()));
              row++;
          }
      }
}
void calendriers::setListeEvenements(const QList<Evenement> &liste)
{
    this->listeEvenements = liste;
}
void calendriers::chargerEvenements()
{
    // Supprimez tous les événements existants du calendrier
    QDate date = calendarWidget->selectedDate();
    calendarWidget->setDateTextFormat(date, {});

    // Appliquer le style CSS au widget QCalendarWidget
    QString style = "QCalendarWidget {"
                    "    background-color: #792382; /* Couleur de fond */"
                    "    border: 2px solid #792382; /* Bordure */"
                    "    color: white; /* Couleur du texte */"
                    "}"
                    "QCalendarWidget QHeaderView {"
                    "    background-color: #792382; /* Couleur de fond de l'en-tête */"
                    "    color: #792382; /* Couleur du texte de l'en-tête */"
                    "    border: none; /* Supprimer la bordure */"
                    "}"
                    "QCalendarWidget QAbstractItemView {"
                    "    selection-background-color: #ff69b4; /* Couleur de fond de la sélection */"
                    "    color: #792382; /* Couleur du texte des jours */"
                    "}"
                    "QCalendarWidget QPushButton {"
                    "    background-color: #43aff7; /* Couleur de fond */"
                    "    border: 1px solid #43aff7; /* Bordure */"
                    "    color: white; /* Couleur du texte */"
                    "    padding: 5px; /* Espacement intérieur */"
                    "}"
                    "QCalendarWidget QPushButton:hover {"
                    "    background-color: #43aff7; /* Couleur de fond */"
                    "    border: 1px solid #43aff7; /* Bordure */"
                    "    color: white; /* Couleur du texte */"
                    "}"
                    "QCalendarWidget QPushButton:pressed {"
                    "    background-color: #43aff7; /* Couleur de fond */"
                    "    border: 1px solid #43aff7; /* Bordure */"
                    "    color: #43aff7; /* Couleur du texte */"
                    "}"
                    "QCalendarWidget QAbstractItemView:enabled:selected {"
                    "    background-color: #ff69b4; /* Couleur de fond de la date sélectionnée */"
                    "    color: #792382; /* Couleur du texte de la date sélectionnée */"
                    "}";

    calendarWidget->setStyleSheet(style);

    // Récupérez les événements depuis la base de données
    QList<Evenement> listeEvenements = Evenement::getListeEvenements();

    // Parcourez la liste des événements et ajoutez-les au calendrier
    for (const Evenement &evenement : listeEvenements) {
        QDate dateDebut = evenement.getDatedeb();
        QDate dateFin = evenement.getDatefin();

        // Marquez les jours du début au fin de l'événement dans le calendrier
        for (QDate date = dateDebut; date <= dateFin; date = date.addDays(1)) {
            QTextCharFormat format = calendarWidget->dateTextFormat(date);
            format.setBackground(QColor("#ff69b4"));
            calendarWidget->setDateTextFormat(date, format);
        }
    }
}
