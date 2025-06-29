#ifndef GESTION_OEUVRE_H
#define GESTION_OEUVRE_H

#include <QDialog>
#include "mainwindow.h"
#include <QSqlQueryModel>


namespace Ui {
class gestion_oeuvre;
}

class gestion_oeuvre : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_oeuvre(QWidget *parent = nullptr);
    ~gestion_oeuvre();
    void detectAfficher(int code);
    void afficher(QSqlQueryModel* m);
    void ShowMenu();
    void HideMenu();
private slots:
    void on_ajouter_clicked();
    void on_Annuler_clicked();
    void DeleteOeuvre();
    void filterTable(const QString &text);
    void ModifierOeuvre();
    void init_evenement();
    void on_logout_clicked();
    void on_downloadPDF_clicked();
    void GenererCodeQR();
    void on_tableW_doubleClicked(const QModelIndex &index);
    void on_historique_clicked();
    void addToHistory(const QString action, const QString Name) ;
    void statistic();
    void updateStatistic();
    void statisticON();
    void statisticOFF();

private:
    Ui::gestion_oeuvre *ui;

};

#endif // GESTION_OEUVRE_H
