#ifndef GESTION_CHARITE_H
#define GESTION_CHARITE_H

#include <QDialog>
#include "Gestion_Charite/charite.h"
#include "Connexion_Bd/connexion_bd.h"
#include "Gestion_Charite/sta.h"
#include "mainwindow.h"


namespace Ui {
class gestion_charite;
}

class gestion_charite : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_charite(QWidget *parent = nullptr);
    ~gestion_charite();
    void supprimer();
    void ShowMenu();
    void HideMenu();
    void genererStatistique();
    int SearchRow(int id);
    void on_voice_clicked();
    void send_sms();
    int recuperer_num_charite();
    void solde_caisse();
    void afficher(QSqlQueryModel*);
    void detectAfficher(int);
    void filterTable(const QString &text);

private slots:
    void on_ajouter_clicked();//ajout d'une charite
    void on_annuler_clicked();//annulation
    void Modifier();//modifer
    void on_methode_activated();//pour initialiser  les choix de methode
    void on_statut_activated();//pour initialiser  les choix des statuts
    void on_telecharger_clicked();//telecharger PDF
    void on_stat_clicked();//stats
    void on_logout_clicked();



private:
    Ui::gestion_charite *ui;
    Charite c;
    int num_charite;
    sta *stat;
};

#endif // GESTION_CHARITE_H
