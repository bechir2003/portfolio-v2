#ifndef MODIF_H
#define MODIF_H

#include <QDialog>

namespace Ui {
class modif;
}

class modif : public QDialog
{
    Q_OBJECT

public:
    explicit modif(QWidget *parent = nullptr,int ide=0);
    ~modif();

private:
    Ui::modif *ui;
    int ide;

private slots:
    void on_modifier_clicked();
    void verifierCapacite();
    bool validerChamps();
};

#endif // MODIF_H
