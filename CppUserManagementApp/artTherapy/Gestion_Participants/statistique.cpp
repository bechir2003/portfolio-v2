#include "statistique.h"
#include "ui_statistique.h"
#include <QVBoxLayout>  // Ajoutez cette ligne
#include "participant.h"

Statistique::Statistique(QChart *chart,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
    // Créez un widget QChartView pour afficher le graphique
        QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Créez un layout vertical pour contenir le QChartView
        QVBoxLayout *layout = new QVBoxLayout(ui->graphicsView);
        layout->addWidget(chartView);
    }



Statistique::~Statistique()
{
    delete ui;
}

