#ifndef DIALOG_H
#define DIALOG_H
#include "oeuvre.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr,int id = 0);
    ~Dialog();
    void init_evenement();
    static QString get_NomEvent(int);

private slots:
    void on_Modifier_clicked();
    void on_Annuler_clicked();
private:
    Ui::Dialog *ui;
    QString Etat;
    int id;
    Oeuvre O;
};

#endif // DIALOG_H
