// statis.cpp
#include "statis.h"
#include "ui_statis.h"
#include <QVBoxLayout>  // Ajoutez cette ligne

Statis::Statis(QChart *chart, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statis)
{
    ui->setupUi(this);

    // Créez un widget QChartView pour afficher le graphique
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créez un layout vertical pour contenir le QChartView
    QVBoxLayout *layout = new QVBoxLayout(ui->graphicsView);
    layout->addWidget(chartView);
}

Statis::~Statis()
{
    delete ui;
}
