#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QDialog>

namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QChart *chart, QWidget *parent = nullptr);
    ~Statistique();

private slots:


private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
