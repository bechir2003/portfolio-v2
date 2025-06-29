// statis.h
#ifndef STATIS_H
#define STATIS_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts>
namespace Ui {
class Statis;
}

class Statis : public QDialog
{
    Q_OBJECT

public:
    explicit Statis(QChart *chart, QWidget *parent = nullptr);
    ~Statis();

private:
    Ui::Statis *ui;
};

#endif // STATIS_H
