#ifndef GESTION_PARTICIPANT_H
#define GESTION_PARTICIPANT_H

#include <QDialog>
#include "mainwindow.h"
#include "participant.h"
#include "participation.h"
namespace Ui {
class gestion_participant;
}

class gestion_participant : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_participant(QWidget *parent = nullptr);
    ~gestion_participant();
    void supprimer();
    void ShowMenu();
    void HideMenu();
    void afficher(QSqlQueryModel*);
    void detectAfficher(int);

private slots:
    void on_logout_clicked();
    void ModifierP() ;
    int SearchRow(int id) ;
    void on_ajouter_clicked();
    void sendConfirmationEmail(int,int);
    void on_annuler_clicked();
    void on_telecharger_clicked();
    void on_rechercher_textChanged(const QString &text);
    void on_statistique_clicked();
    void scan_CIN();
    void on_rafraichir_ajouter_p_clicked();

private:
    Ui::gestion_participant *ui;
    Participant p;
    Participation P2;
    int id_e,id_p;
    int CIN;
};

#endif // GESTION_PARTICIPANT_H
