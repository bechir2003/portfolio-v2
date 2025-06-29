#ifndef STATISSS_H
#define STATISSS_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>
namespace Ui {
class Statisss;
}

class Statisss : public QDialog
{
    Q_OBJECT

public:
    explicit Statisss(QChart *chart,QWidget *parent = nullptr);
    ~Statisss();

private slots:
    void on_batons_2_clicked();

    void on_cercle_2_clicked();

    void on_retourner_2_clicked();

private:
    Ui::Statisss *ui;
    QtCharts::QChartView *chartView;

};

#endif // STATISSS_H
