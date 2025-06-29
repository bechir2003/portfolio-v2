#include "gestion_oeuvre.h"
#include "oeuvre.h"
#include "dialog.h"
#include "ui_gestion_oeuvre.h"

gestion_oeuvre::gestion_oeuvre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_oeuvre)
{
    ui->setupUi(this);

    //BEGIN filterTable
    connect(ui->search, &QLineEdit::textChanged, this, &gestion_oeuvre::filterTable);
    //END filterTable

    //BEGIN ONLY DIGITS
    QRegExpValidator *validatorNum = new QRegExpValidator(QRegExp("[0-9]*"));
    ui->prix->setValidator(validatorNum);
    //END ONLY DIGITS

    //BEGIN ONLY LETTERS
    QRegExpValidator *validatorLet = new QRegExpValidator(QRegExp("[A-Za-z]*"));
    ui->nom->setValidator(validatorLet);
    //END ONLY LETTERS

    //BEGIN menu
    connect(ui->Menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu

    detectAfficher(0);
    init_evenement();
    //BEGIN trier
    connect(ui->triCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int newIndex) {
        ui->triCombo->setCurrentIndex(0);
        if(newIndex == 1){
            if(ui->asc->isChecked()){
                detectAfficher(1);
            }
            else if(ui->desc->isChecked()){
                detectAfficher(2);
            }
        }
        else if(newIndex == 2){
            if(ui->asc->isChecked()){
                detectAfficher(3);
            }
            else if(ui->desc->isChecked()){
                detectAfficher(4);
            }
        }
        else if(newIndex == 3){
            if(ui->asc->isChecked()){
                detectAfficher(5);
            }
            else if(ui->desc->isChecked()){
                detectAfficher(6);
            }
        }


    });
    //END trier

    //BEGIN statON
    connect(ui->stat, &QPushButton::clicked, this, &gestion_oeuvre::statisticON);
    //END statON

    //BEGIN statOFF
    connect(ui->statOFF, &QPushButton::clicked, this, &gestion_oeuvre::statisticOFF);
    //END statOFF

    //BEGIN QrCode
    connect(ui->qrcode, &QPushButton::clicked, this, &gestion_oeuvre::GenererCodeQR);
    //END QrCode refresh

    // BEGIN refresh
    connect(ui->refresh, &QPushButton::clicked, this, [&](){
        detectAfficher(0);
    });
    // END refresh

    // BEGIN closeH
    connect(ui->CloseH, &QPushButton::clicked, this, [&](){
        ui->CloseH->lower();
        ui->textEdit->lower();
    });
    // END closeH

}

gestion_oeuvre::~gestion_oeuvre()
{
    delete ui;
}
//BEGIN LOGOUT
void gestion_oeuvre::on_logout_clicked(){
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
//END LOGOUT


void gestion_oeuvre::on_Annuler_clicked(){
    ui->nom->setText("");
    ui->prix->setText("");
    ui->type->setCurrentIndex(0);
}

void gestion_oeuvre::ShowMenu(){
    ui->Menu->raise();
}

void gestion_oeuvre::HideMenu(){
    ui->Menu->lower();
}

void gestion_oeuvre::on_ajouter_clicked()
{
    QString nomA = ui->nom->text();
    QString type = ui->type->currentText();
    float prix=ui->prix->text().toFloat();

    QVariant selectEevenementId = ui->evenement->currentData(Qt::UserRole);
    int selectEevenementIdValue = selectEevenementId.toInt();

    Oeuvre O(0,nomA,type,prix,"",selectEevenementIdValue);

    if(nomA.isEmpty() ){
        ui->nom->setStyleSheet("border: 2px solid red");
        QMessageBox::critical(nullptr, QObject::tr("erreur"),QObject::tr("nom invalide !!"));
        return;
    }
    else{
        ui->nom->setStyleSheet("QLineEdit {"
                               "    padding: 5px;"
                               "    border: 2px solid #43aff7;"
                               "    border-radius: 5px;"
                               "    font-size: 14px;"
                               "    color: #333;"
                               "}"
                               ""
                               "QLineEdit:focus {"
                               "    border-color: #2ecc71;"
                               "}");
    }
    if(type.isEmpty() ){
        ui->type->setStyleSheet("border: 2px solid red");
        QMessageBox::critical(nullptr, QObject::tr("erreur"),QObject::tr("type invalide !!"));
        return;
    }
    else{
        ui->type->setStyleSheet("padding: 5px; border: 2px solid #43aff7; border-radius: 5px; font-size: 14px; color: #333;");

    }

    if(prix<=0 ){
        ui->prix->setStyleSheet("border: 2px solid red");
        QMessageBox::critical(nullptr, QObject::tr("erreur"),QObject::tr("prix invalide !!"));
        return;
    }
    else{
        ui->prix->setStyleSheet("QLineEdit {"
                                    "    padding: 5px;"
                                    "    border: 2px solid #43aff7;"
                                    "    border-radius: 5px;"
                                    "    font-size: 14px;"
                                    "    color: #333;"
                                    "}"
                                    ""
                                    "QLineEdit:focus {"
                                    "    border-color: #2ecc71;"
                                    "}");
    }

    if(ui->evenement->currentText().isEmpty() ){
        ui->evenement->setStyleSheet("border: 2px solid red");
        QMessageBox::critical(nullptr, QObject::tr("erreur"),QObject::tr("evenement invalide !!"));
        return;
    }
    else{
        ui->evenement->setStyleSheet("padding: 5px; border: 2px solid #43aff7; border-radius: 5px; font-size: 14px; color: #333;");

    }

    bool test = O.Ajouter_Oeuvre();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("oeuvre ajoute avec succes.\n"));
        detectAfficher(0);
     }
     else {
        QMessageBox::critical(nullptr, QObject::tr("system"),QObject::tr("Erreur.\n"));
     }

    ui->nom->clear();
    ui->prix->clear();
    QString NOM_ARTISTE = ui->nom->text();
    addToHistory("Suppression",NOM_ARTISTE);

}
void gestion_oeuvre::afficher(QSqlQueryModel* m){
    ui->tableW->setRowCount(m->rowCount());
    ui->tableW->setColumnCount(m->columnCount()+2);
    QStringList headers;
    for (int col = 0; col < m->columnCount(); ++col) {
        if(col==5){
            headers << "Evenement";
        }
        else{
            headers << m->headerData(col, Qt::Horizontal).toString();
        }

    }
    headers << "Action1" << "Action2";
    ui->tableW->setHorizontalHeaderLabels(headers);
    for (int row = 0; row < m->rowCount(); ++row) {
        for (int col = 0; col < m->columnCount(); ++col) {
            if(col==5){
                QTableWidgetItem *item = new QTableWidgetItem(Dialog::get_NomEvent(m->data(m->index(row, col)).toInt()));
                ui->tableW->setItem(row, col, item);

            }
            else{
                QTableWidgetItem *item = new QTableWidgetItem(m->data(m->index(row, col)).toString());
                ui->tableW->setItem(row, col, item);
            }

        }

        QPushButton *deleteButton = new QPushButton("supprimer", ui->tableW);
        deleteButton->setStyleSheet("QPushButton {\
                                        padding: 5px;\
                                        font-size: 16px;\
                                        text-align: center;\
                                        text-decoration: none;\
                                        border: 2px solid #792382;\
                                        color: #792382;\
                                        border-radius: 5px;\
                                    }\
                                    QPushButton:hover {\
                                        background-color: #43aff7;\
                                    }");
        ui->tableW->setCellWidget(row, m->columnCount(), deleteButton);
        connect(deleteButton, &QPushButton::clicked, this, &gestion_oeuvre::DeleteOeuvre);
        int id_O = m->data(m->index(row, 0)).toInt();
        deleteButton->setObjectName(QString::number(id_O));

        QPushButton *editButton = new QPushButton("modifier", ui->tableW);
        // Modifier button
        editButton->setStyleSheet("QPushButton {\
                                        padding: 5px;\
                                        font-size: 16px;\
                                        text-align: center;\
                                        text-decoration: none;\
                                        border: 2px solid #792382;\
                                        color: #792382;\
                                        border-radius: 5px;\
                                    }\
                                    QPushButton:hover {\
                                        background-color: #43aff7;\
                                    }");


        ui->tableW->setCellWidget(row, m->columnCount()+1 , editButton);
        connect(editButton, &QPushButton::clicked, this, &gestion_oeuvre::ModifierOeuvre);
        editButton->setObjectName(QString::number(id_O));
    }

    QLayout *existingLayout = layout();
    if (existingLayout) {

        QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
        if (verticalLayout) {
            verticalLayout->addWidget(ui->tableW);
        }
    }

}


void gestion_oeuvre::DeleteOeuvre()
{
    QString NOM_ARTISTE = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->currentIndex().row(),2)).toString();
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;
    int id_O = senderButton->objectName().toInt();
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                     "Êtes-vous sûr de vouloir supprimer cet oeuvre ?",
                                                                     QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::Yes) {
        Oeuvre e;
        bool success = e.Effacer_Oeuvre(id_O);
        if (success) {
            detectAfficher(0);
            QMessageBox::information(this, "Succès", "oeuvre supprimé avec succès.");
        } else {
            QMessageBox::information(this, "Erreur", "Impossible de supprimer l'oeuvre.");
        }
    }
}



void gestion_oeuvre::filterTable(const QString &text) {
    for (int row = 0; row < ui->tableW->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->tableW->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableW->item(row, col);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tableW->setRowHidden(row, !match);
    }
}
void gestion_oeuvre::ModifierOeuvre() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;

    int id_o = senderButton->objectName().toInt();

    Dialog D(this,id_o);
    D.setModal(true);
    D.exec();
}

void gestion_oeuvre::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        Oeuvre o;
        m=o.afficher_Oeuvre();
    }
    else if(code==1){
        m->setQuery("SELECT * FROM oeuvre order by prix;");
    }
    else if(code==2){
        m->setQuery("SELECT * FROM oeuvre order by prix desc;");
    }
    else if(code==3){
        m->setQuery("SELECT * FROM oeuvre order by Nom_artiste;");
    }
    else if(code==4){
        m->setQuery("SELECT * FROM oeuvre order by Nom_artiste desc;");
    }
    else if(code==5){
        m->setQuery("SELECT * FROM oeuvre order by etat;");
    }
    else if(code==6){
        m->setQuery("SELECT * FROM oeuvre order by etat desc;");
    }
    afficher(m);
}



void gestion_oeuvre::on_downloadPDF_clicked() {

    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    QPainter painter(&pdfWriter);

    painter.drawText(1, 100, "Oeuvres Details: ");

    int numRows = ui->tableW->rowCount();
    int numCols = ui->tableW->columnCount();
    int y = 200;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QTableWidgetItem *item = ui->tableW->item(row, col);
            if (item) {
                QString text = item->text();
                if(col==4){
                    painter.drawText( 700+col * 1000, y*(row+3), text);
                }else if(col==5){
                    painter.drawText( 700+col * 1000, y*(row+3), text);
                }else{
                    painter.drawText( col * 1000, y*(row+3), text);
                }
            }
        }
    }
    painter.end();
    QMessageBox::information(this, "PDF Downloaded", "PDF has been downloaded successfully.");
}

//BEGIN GenererCodeQR
void gestion_oeuvre::GenererCodeQR() {
    // Vérifier si une ligne est sélectionnée dans le tableau
    if (ui->tableW->selectionModel()->currentIndex().isValid()) {
        // Récupérer les données de la ligne sélectionnée
        QString id = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 0)).toString();
        QString NomArtiste = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 1)).toString();
        QString Type = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 2)).toString();
        QString Prix = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 3)).toString();

        // Construire le contenu du code QR avec les données récupérées
        QString qrContent = QString("NomArtiste: %1\nType: %2\nPrix: %3").arg(NomArtiste, Type, Prix);

        // Générer le code QR avec le contenu
        const QrCode qr = QrCode::encodeText(qrContent.toStdString().c_str(), QrCode::Ecc::LOW);

        // Demander à l'utilisateur de spécifier le chemin et le nom du fichier
        QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le code QR"), QDir::homePath() + "/" + id + ".svg", tr("Fichiers SVG (*.svg)"));
        if (!fileName.isEmpty()) {
            std::ofstream myfile;
            myfile.open(fileName.toStdString().c_str());
            myfile << qr.toSvgString(1);
            myfile.close();
            QMessageBox::information(this, tr("Succès"), tr("Le code QR a été enregistré avec succès."));
        }
    } else {
        // Afficher un avertissement si aucune ligne n'est sélectionnée dans le tableau
        QMessageBox::warning(this, tr("Avertissement"), tr("Veuillez sélectionner une ligne dans le tableau."));
    }
}

//END GenererCodeQR

void gestion_oeuvre::on_tableW_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tableW->model();

           QString NOM_ARTISTE = model->data(model->index(index.row(), 1)).toString();
           QString TYPE = model->data(model->index(index.row(), 2)).toString();
           int PRIX = model->data(model->index(index.row(), 3)).toInt();
           QString ETAT = model->data(model->index(index.row(), 4)).toString();

/*if (ETAT=="Vendu")
{
     ui->V->setText( ETAT);
}
else
{
     ui->NV->setText( ETAT);
}*/
           ui->nom->setText(NOM_ARTISTE);
           ui->type->setCurrentText(TYPE);
           ui->prix->setText(QString::number(PRIX));



}

void gestion_oeuvre::addToHistory(const QString action, const QString Name) {
    QString queryString = "INSERT INTO HISTORY (action, name, datee) VALUES (:action, :name, :date)";
       QSqlQuery query;
       query.prepare(queryString);
       query.bindValue(":action", action);
       query.bindValue(":name", Name);
       query.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));
cout <<"ac,skjf"<<endl;

}

void gestion_oeuvre::on_historique_clicked()
{
    ui->textEdit->raise();
    ui->CloseH->raise();
    QFile file("Gestion_Oeuvre/historic.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        ui->textEdit->setPlainText(content);
        file.close();
    }
}



void gestion_oeuvre::init_evenement(){
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select ide,nom from evenement where datefin>sysdate;");
    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex index = model->index(i, 1);
        QString eventName = model->data(index).toString();
        QVariant eventId = model->data(model->index(i, 0), Qt::DisplayRole);
        ui->evenement->addItem(eventName, eventId);
    }

}

//BEGIN statistic
void gestion_oeuvre::statistic() {

    QSqlQueryModel* model = Oeuvre::afficher_Oeuvre();

    if (!model) {
        qDebug() << "Error: Failed to retrieve employee data.";
        return;
    }

    int rowCount = model->rowCount();

    int item1 = 0, item2 = 0, item3 = 0;
    for (int i = 0; i < rowCount; ++i) {
        if (model->data(model->index(i, 2)).toString() == "Peinture a l'huile") {
            item1++;
        } else if (model->data(model->index(i, 2)).toString() == "Peinture a l'eau") {
            item2++;
        }
        else if (model->data(model->index(i, 2)).toString() == "Photographe") {
            item3++;
        }
    }

    float Pitem1 = (item1 * 100.0) / rowCount;
    float Pitem2 = (item2 * 100.0) / rowCount;
    float Pitem3 = (item3 * 100.0) / rowCount;

    // Create a bar series
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    QtCharts::QBarSet *roleSet = new QtCharts::QBarSet("Type");
    *roleSet << Pitem1 << Pitem2 << Pitem3 ;
    series->append(roleSet);

    // Create a chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Oeuvre Statistics");

    // Create a category axis and set labels
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append("Peinture à l'huile");
    axis->append("Peinture à l'eau");
    axis->append("Photographe");

    chart->setAxisX(axis, series);

    // Create a value axis and set the range
    QtCharts::QValueAxis *valueAxis = new QtCharts::QValueAxis();
    valueAxis->setRange(0, 100);
    chart->setAxisY(valueAxis, series);
    ui->widget->raise();
    ui->statOFF->raise();

    // Add legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Display the chart
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setFixedSize(1600, 600);

    QVBoxLayout *layout = new QVBoxLayout(ui->widget);
    layout->addWidget(chartView);
    ui->widget->setLayout(layout);

    // Clean up
    delete model;
    updateStatistic();
}
//END statistic

//BEGIN statisticON
void gestion_oeuvre::statisticON() {
    ui->widget->show(); // Show the statistics widget
    ui->statOFF->show(); // Show the button to turn off statistics
    statistic(); // Refresh the statistics data
}
//END statisticON

//BEGIN statisticOFF
void gestion_oeuvre::statisticOFF() {
    ui->widget->hide();
    ui->statOFF->hide();
}
//END statisticOFF

//BEGIN updateStatistic
void gestion_oeuvre::updateStatistic() {
    // Clear the layout
    QWidget* widget = ui->widget;
    if (widget) {
        QLayout* layout = widget->layout();
        if (layout) {
            QLayoutItem* item;
            while ((item = layout->takeAt(0)) != nullptr) {
                if (QWidget* itemWidget = item->widget()) {
                    delete itemWidget;
                } else {
                    delete item;
                }
            }
        }
    }

    // Create a new chart widget and add it to the layout

    QSqlQueryModel* model = Oeuvre::afficher_Oeuvre();

    if (!model) {
        qDebug() << "Error: Failed to retrieve employee data.";
        return;
    }

    int rowCount = model->rowCount();

    int item1 = 0, item2 = 0, item3 = 0;
    for (int i = 0; i < rowCount; ++i) {
        if (model->data(model->index(i, 2)).toString() == "Peinture a l'huile") {
            item1++;
        } else if (model->data(model->index(i, 2)).toString() == "Peinture a l'eau") {
            item2++;
        }
        else if (model->data(model->index(i, 2)).toString() == "Photographe") {
            item3++;
        }
    }

    float Pitem1 = (item1 * 100.0) / rowCount;
    float Pitem2 = (item2 * 100.0) / rowCount;
    float Pitem3 = (item3 * 100.0) / rowCount;

    // Create a bar series
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    QtCharts::QBarSet *roleSet = new QtCharts::QBarSet("Type");
    *roleSet << Pitem1 << Pitem2 << Pitem3 ;
    series->append(roleSet);

    // Create a chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Oeuvres ");

    // Create a category axis and set labels
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append("Peinture à l'huile");
    axis->append("Peinture à l'eau");
    axis->append("Photographe");

    chart->setAxisX(axis, series);

    // Create a value axis and set the range
    QtCharts::QValueAxis *valueAxis = new QtCharts::QValueAxis();
    valueAxis->setRange(0, 100);
    chart->setAxisY(valueAxis, series);
    ui->widget->raise();
    ui->statOFF->raise();

    // Add legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Display the chart
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setFixedSize(1600, 600);
    ui->widget->layout()->addWidget(chartView);


}
//END updateStatistic
