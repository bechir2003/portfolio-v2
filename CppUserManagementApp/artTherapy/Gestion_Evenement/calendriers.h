#ifndef CALENDRIERS_H
#define CALENDRIERS_H

#include <QDialog>
#include <QWidget>
#include <QCalendarWidget>
#include <QTableWidget>
#include "gestion_evenement.h"
#include "evenement.h"
namespace Ui {
class calendriers;
}

class calendriers : public QDialog
{
    Q_OBJECT

public:
    explicit calendriers(QWidget *parent = nullptr);
    ~calendriers();
    void chargerEvenements();
    void setListeEvenements(const QList<Evenement> &liste);


private slots:
    void on_calendarWidget_selectionChanged();

private:
    Ui::calendriers *ui;
    QCalendarWidget *calendarWidget;
       QTableWidget *tableWidget;
       QList<Evenement> listeEvenements;
        QDate lastSelectedDate;
};

#endif // CALENDRIERS_H
