#ifndef GESTION_EVENEMENT_H
#define GESTION_EVENEMENT_H

#include <QDialog>
#include "mainwindow.h"
#include "Gestion_Evenement/evenement.h"
#include "QTableWidget"
namespace Ui {
class gestion_evenement;
}

class gestion_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_evenement(QWidget *parent = nullptr);
    ~gestion_evenement();
    void supprimer();
    void Modifier();
    void genererStatistique();
    bool validerChamps();
    void verifierCapacite();
    void filterTable(const QString &text);
    int SearchRow(int id);
    void gestionRappels();
   QList<Evenement> obtenirEvenementsAVenir();
    void afficherNotification(const Evenement &evenement);
    void ShowMenu();
    void HideMenu();
    void afficher(QSqlQueryModel*);
    void detectAfficher(int);

private:
    Ui::gestion_evenement *ui;


private slots:
    void on_logout_clicked();
    void on_ajouter_clicked();
    void on_annuler_clicked();
    void on_telecharger_clicked();
    void on_stat_clicked();
    void on_pushButton_15_clicked();
};

#endif // GESTION_EVENEMENT_H
