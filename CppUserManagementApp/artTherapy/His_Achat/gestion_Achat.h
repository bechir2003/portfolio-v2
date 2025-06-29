#ifndef GESTION_ACHAT_H
#define GESTION_ACHAT_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QtSql>
#include "Gestion_Participants/participation.h"
#include "Arduino/arduino2.h"
namespace Ui {
class gestion_Achat;
}

class gestion_Achat : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_Achat(QWidget *parent = nullptr);
    ~gestion_Achat();
    void logout();
    void afficher_His_Achat(QSqlQueryModel* m);
    void init_His_Achat();
    void ajouter_His_Achat();
    void filterTable(const QString &text);
    void filterTable2(const QString &text);
    void detectAfficher(int);
    void downloadPDF();
    void downloadPDF2();
    void init_participation();
    void Afficher2(QSqlQueryModel*);
    void Annuler();
    void Annuler2();
    void sendConfirmationEmail(int,int);
    void supprimer();
    int getNombreParticipants(int);
    void detectAfficher2(int);
    void ShowMenu();
    void HideMenu();

private slots :
    void on_ajouter_participation_clicked();
    void arduino();
    bool verifyCode(const QString &code);
private:
    Ui::gestion_Achat *ui;
    QByteArray data;
    Arduino2 A;
    QTimer *timer;
    QString nomEvenement;
    QString nomParticipant;
};

#endif // GESTION_ACHAT_H
