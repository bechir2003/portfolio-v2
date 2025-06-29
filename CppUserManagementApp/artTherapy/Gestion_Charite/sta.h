#ifndef STA_H
#define STA_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>

namespace Ui {
class sta;
}

class sta : public QDialog
{
    Q_OBJECT

public:
    explicit sta(QChart *chart,QWidget *parent = nullptr);
    ~sta();



private:
    Ui::sta *ui;

private slots:
    void on_retourner_clicked();
};

#endif // STA_H
