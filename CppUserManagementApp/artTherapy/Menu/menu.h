#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "Gestion_Charite/gestion_charite.h"
#include "Gestion_Evenement/gestion_evenement.h"
#include "Gestion_Oeuvre/gestion_oeuvre.h"
#include "Gestion_Participants/gestion_participant.h"
#include "Gestion_Personnel/gestion_personnel.h"
#include "His_Achat/gestion_achat.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;

private slots:
    void on_GP_clicked();
    void on_GC_clicked();
    void on_GPA_clicked();
    void on_GE_clicked();
    void on_GO_clicked();
    void on_GHA_clicked();
};

#endif // MENU_H
