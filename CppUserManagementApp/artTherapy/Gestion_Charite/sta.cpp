#include "../Gestion_Charite/sta.h"
#include "ui_sta.h"

sta::sta(QChart *chart,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sta)
{
    ui->setupUi(this);
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *layout = new QVBoxLayout(ui->graph);
    layout->addWidget(chartView);
}



sta::~sta()
{
    delete ui;
}


void sta::on_retourner_clicked()
{
    close();
}
