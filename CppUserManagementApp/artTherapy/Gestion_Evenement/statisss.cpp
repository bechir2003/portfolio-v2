#include "statisss.h"
#include "ui_statisss.h"
#include <QVBoxLayout>  // Ajoutez cette ligne
#include <QPdfWriter>
#include <QPainter>
#include "evenement.h"
Statisss::Statisss(QChart *chart,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statisss)
{
    ui->setupUi(this);
    chartView = new QtCharts::QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Créez un layout vertical pour contenir le QChartView
        QVBoxLayout *layout = new QVBoxLayout(ui->graphicsView);
        layout->addWidget(chartView);
}

Statisss::~Statisss()
{
    delete ui;
}

void Statisss::on_batons_2_clicked()
{
    Evenement k;
    QVector<QString> lieuxEvenements; // Vecteur pour stocker les lieux des événements
    QVector<int> nombreEvenements;    // Vecteur pour stocker le nombre d'événements par lieu

    // Récupérer les données à partir de la base de données en regroupant par lieu
    QSqlQuery query;
    if (!query.exec("SELECT LIEU, COUNT(*) AS NombreEvenements FROM EVENEMENT GROUP BY LIEU")) {
        qDebug() << "Erreur lors de la récupération des données de statistiques.";
        return;
    }

    // Parcourir les résultats de la requête
    while (query.next()) {
        // Récupérer le lieu et le nombre d'événements
        QString lieu = query.value("LIEU").toString();
        int nombre = query.value("NombreEvenements").toInt();

        // Ajouter le lieu et le nombre d'événements aux vecteurs respectifs
        lieuxEvenements.append(lieu);
        nombreEvenements.append(nombre);
    }

    // Créer le graphique à partir des données récupérées
    QBarSeries *barSeries = new QBarSeries();

    for (int i = 0; i < lieuxEvenements.size(); ++i) {
        QBarSet *barSet = new QBarSet(lieuxEvenements.at(i));
        *barSet << nombreEvenements.at(i);
        barSeries->append(barSet);
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Statistiques par Lieu");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("");
    chart->createDefaultAxes();
    chart->setAxisX(axisX, barSeries);

    chart->setMinimumSize(800, 600);

    QFont font = chart->titleFont();
    font.setPixelSize(20);
    chart->setTitleFont(font);
    axisX->setLabelsFont(font);

    // Afficher le graphique dans une fenêtre ou un dialogue
    Statisss *statisDialog = new Statisss(chart, this);
    this->close();
    statisDialog->show();
}


void Statisss::on_cercle_2_clicked()
{
    Evenement k;
    QVector<QString> lieuxEvenements; // Vecteur pour stocker les lieux des événements
        QVector<int> nombreEvenements;    // Vecteur pour stocker le nombre d'événements par lieu

        // Récupérer les données à partir de la base de données en regroupant par lieu
        QSqlQuery query;
        if (!query.exec("SELECT LIEU, COUNT(*) AS NombreEvenements FROM EVENEMENT GROUP BY LIEU")) {
            qDebug() << "Erreur lors de la récupération des données de statistiques.";
            return;
        }

        // Parcourir les résultats de la requête
        while (query.next()) {
            // Récupérer le lieu et le nombre d'événements
            QString lieu = query.value("LIEU").toString();
            int nombre = query.value("NombreEvenements").toInt();

            // Ajouter le lieu et le nombre d'événements aux vecteurs respectifs
            lieuxEvenements.append(lieu);
            nombreEvenements.append(nombre);
        }

        // Créer le diagramme circulaire à partir des données récupérées
        QPieSeries *pieSeries = new QPieSeries();

        QStringList couleurs = {"#FF69B4", "#00FF00", "#FFA500","#1f77b4", "#ff7f0e", "#2ca02c", "#d62728", "#9467bd", "#8c564b"};

        for (int i = 0; i < lieuxEvenements.size(); ++i) {
            QPieSlice *slice = pieSeries->append(lieuxEvenements.at(i), nombreEvenements.at(i));
            slice->setLabelVisible(); // Rendre le label visible
            slice->setLabel(QString("%1\n%2").arg(lieuxEvenements.at(i)).arg(nombreEvenements.at(i))); // Définir le texte du label

            // Assurez-vous que l'index ne dépasse pas la taille de la liste des couleurs
            int colorIndex = i % couleurs.size();
            slice->setBrush(QBrush(QColor(couleurs.at(colorIndex))));
        }

        // Créer et configurer le diagramme circulaire
        QChart *chart = new QChart();
        chart->addSeries(pieSeries);
        chart->setTitle("Statistiques par Lieu");

        chart->setMinimumSize(800, 600);

        QFont font = chart->titleFont();
        font.setPixelSize(20);
        chart->setTitleFont(font);

        // Afficher le diagramme circulaire dans une fenêtre ou un dialogue
        Statisss *statisDialog = new Statisss(chart, this);
        this->close();
        statisDialog->show();

}


void Statisss::on_retourner_2_clicked()
{
    close();

}


