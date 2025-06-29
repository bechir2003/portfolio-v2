#include "../Gestion_Evenement/gestion_evenement.h"
#include "ui_gestion_evenement.h"
#include <QMessageBox>
#include <iostream>
#include <QStandardItemModel>
#include <QPainter>
#include <QFileDialog>
#include "evenement.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTableCell>
#include <QDebug>
#include <QDateTime>
#include <QBoxLayout>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QGraphicsView>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QTimer>
#include <QList>
#include <QtCharts/QBarCategoryAxis>
#include "statisss.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "calendriers.h"
gestion_evenement::gestion_evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_evenement)
{
    ui->setupUi(this);

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

    connect(ui->afficher, &QPushButton::clicked, this, [this](){
        detectAfficher(0);
    });

    //BEGIN menu
    connect(ui->Menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu
    //BEGIN filterTable
    connect(ui->search, &QLineEdit::textChanged, this, &gestion_evenement::filterTable);
    //END filterTable
    QStringList statutOptions = {"En cours","Planifie", "Termine", "Annule"};
            // Assurez-vous que le nom du QComboBox est correct (ici, comboBoxStatut)
            ui->comboBox->addItems(statutOptions);

            QIntValidator *capaciteValidator = new QIntValidator(0, 9999, this);
            ui->capacite->setValidator(capaciteValidator);

            // Connecter un slot pour vérifier si la capacité est valide lors du clic sur le bouton
            connect(ui->ajouter, &QPushButton::clicked, this, &gestion_evenement::verifierCapacite);
            QTimer *timer = new QTimer(this);
                             connect(timer, &QTimer::timeout, this, &gestion_evenement::gestionRappels);
                             timer->start(24 * 60 * 60 * 1000); // Déclencher toutes les 24 heures

                 gestionRappels();

            // ...
            ui->datedeb->setDate(QDate::currentDate());
               ui->datefin->setDate(QDate::currentDate()); QDateEdit *dateDebEdit = ui->datedeb;
            ui->nomevent->setPlaceholderText("Entrez le nom de l'événement");
            ui->description->setPlaceholderText("Entrez la description de l'événement");
            // Créer un validateur pour les champs d'entrée (accepte uniquement des alphabets et exige au moins un caractère)
            QRegExpValidator *validator = new QRegExpValidator(QRegExp("[a-zA-Z]+"), this);

            // Appliquer le validateur à tous les champs
            ui->nomevent->setValidator(validator);
            ui->description->setValidator(validator);

               QDateEdit *dateFinEdit = ui->datefin;

               connect(dateDebEdit, &QDateEdit::dateChanged, [ dateFinEdit](const QDate &date) {
                   dateFinEdit->setMinimumDate(date);
               });
               detectAfficher(0);


   /* connect(ui->lineEdit, &QLineEdit::textChanged, this, &event::on_lineEdit_textChanged);

    disconnect(ui->lineEdit, &QLineEdit::textChanged, this, &event::on_lineEdit_textChanged);*/
}

gestion_evenement::~gestion_evenement()
{
    delete ui;
}
//BEGIN LOGOUT
void gestion_evenement::on_logout_clicked(){
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
//END LOGOUT

void gestion_evenement::ShowMenu(){
    ui->Menu->raise();
}

void gestion_evenement::HideMenu(){
    ui->Menu->lower();
}

//BEGIN detectAfficher
void gestion_evenement::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m= Evenement::afficher();
    }
    else if(code==1){
        m->setQuery("select * from evenement order by nom;");
    }
    else if(code==2){
        m->setQuery("select * from evenement order by nom desc;");
    }
    else if(code==3){
        m->setQuery("select * from evenement order by lieu;");
    }
    else if(code==4){
        m->setQuery("select * from evenement order by lieu desc;");
    }
    else if(code==5){
        m->setQuery("select * from evenement order by statut;");
    }
    else if(code==6){
        m->setQuery("select * from evenement order by statut desc;");
    }
    afficher(m);
}
//END detectAfficher

void gestion_evenement::on_ajouter_clicked()//ajouter
{
            QString nomevent = ui->nomevent->text();
            QString lieu = ui->lieu->text();
            QString description = ui->description->text();
            QDate datedeb = ui->datedeb->date();
            QDate datefin = ui->datefin->date();
            QString statut = ui->comboBox->currentText();
            int capacite = ui->capacite->text().toInt();

            Evenement E(0, nomevent, lieu, datedeb, datefin, description, statut, capacite);
            if(nomevent.isEmpty() ||
               lieu.isEmpty() ||
               ui->capacite->text().isEmpty() ||
               description.isEmpty()
             ){
                QMessageBox::critical(nullptr, tr("System"), tr("verifier les champs!!"));
                return;
            }
            bool ajoutReussi = E.ajouter_E();

            if (ajoutReussi) {
                QMessageBox::information(nullptr, tr("Ajout réussi"), tr("évènement ajoutée avec succès !"));
                // Clear input fields
                ui->nomevent->clear();
                ui->lieu->clear();
                ui->datedeb->setDate(QDate::currentDate());
                ui->datefin->setDate(QDate::currentDate());
                ui->description->clear();
                ui->capacite->clear();

                // Afficher les données par défaut
                detectAfficher(0);
            } else {
                QMessageBox::critical(nullptr, tr("Erreur d'ajout"), tr("Échec de l'ajout de l'évènement."));
            }
}

void gestion_evenement::afficher(QSqlQueryModel * model)//afficher
{
        ui->tableWidget->setRowCount(model->rowCount());
        ui->tableWidget->setColumnCount(model->columnCount()+2);
        QStringList headers;
        for(int i=0;i<model->columnCount();i++)
        {
            headers<<model->headerData(i,Qt::Horizontal).toString();
        }
        headers<<"SUPPRIMER"<<"MODIFIER";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        for(int row=0;row<model->rowCount();row++)
        {
            for(int column=0;column<model->columnCount();column++)
            {
                QTableWidgetItem *item=new QTableWidgetItem(model->data(model->index(row,column)).toString());
                ui->tableWidget->setItem(row,column,item);
            }
            QPushButton *deleteButton = new QPushButton("Supprimer", ui->tableWidget);
                  deleteButton->setStyleSheet("QPushButton {"
                                              "padding: 5px;"             // Rembourrage de 5 pixels
                                              "font-size: 16px;"          // Taille de la police de caractères
                                              "text-align: center;"       // Alignement du texte au centre
                                              "text-decoration: none;"    // Aucune décoration de texte
                                              "border: 2px solid #43aff7;"// Bordure de 2 pixels solide avec couleur #43aff7
                                              "color: #43aff7;"           // Couleur du texte #43aff7
                                              "border-radius: 5px;"       // Bordure arrondie de 5 pixels
                                              "background-image: url(\"images/trash.svg\");" // Chemin de l'image
                                              "background-repeat: no-repeat;" // Pas de répétition d'arrière-plan
                                              "background-position: left center;" // Position de l'arrière-plan à gauche et centrée
                                              "padding-left: 30px;"      // Rembourrage à gauche de 30 pixels
                                          "}"

                                          "QPushButton:hover {"
                                              "background-color: #792382;" // Couleur de fond en survol #792382
                                          "}"

    );
                  ui->tableWidget->setCellWidget(row, model->columnCount(), deleteButton);
                  connect(deleteButton, &QPushButton::clicked, this, &gestion_evenement::supprimer);//pas kenza taleet event !!!
                  int ide = model->data(model->index(row, 0)).toInt();
                  deleteButton->setObjectName(QString::number(ide));

                  QPushButton *modifierButton = new QPushButton("Modifier", ui->tableWidget);
                        modifierButton->setStyleSheet("QPushButton {"
                                                      "padding: 5px;"             // Rembourrage de 5 pixels
                                                      "font-size: 16px;"          // Taille de la police de caractères
                                                      "text-align: center;"       // Alignement du texte au centre
                                                      "text-decoration: none;"    // Aucune décoration de texte
                                                      "border: 2px solid #43aff7;"// Bordure de 2 pixels solide avec couleur #43aff7
                                                      "color: #43aff7;"           // Couleur du texte #43aff7
                                                      "border-radius: 5px;"       // Bordure arrondie de 5 pixels
                                                      "background-image: url(\"C:/Users/Kinza/Documents/evenement/edit.svg\");" // Chemin de l'image
                                                      "background-repeat: no-repeat;" // Pas de répétition d'arrière-plan
                                                      "background-position: left center;" // Position de l'arrière-plan à gauche et centrée
                                                      "padding-left: 30px;"      // Rembourrage à gauche de 30 pixels
                                                  "}"

                                                  "QPushButton:hover {"
                                                      "background-color: #792382;" // Couleur de fond en survol #792382
                                                  "}"

    );
                        ui->tableWidget->setCellWidget(row, model->columnCount()+1, modifierButton);
                        connect(modifierButton, &QPushButton::clicked, this, &gestion_evenement::Modifier);
                        modifierButton->setObjectName(QString::number(ide));
                    }

                    QLayout *existingLayout = layout();
                    if (existingLayout) {

                        QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
                        if (verticalLayout) {
                            verticalLayout->addWidget(ui->tableWidget);
                        }
                    }
    }


bool gestion_evenement::validerChamps() {
    if (ui->nomevent->text().isEmpty() || ui->lieu->text().isEmpty() || ui->description->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return false;
    }

    return true;
}

void gestion_evenement::verifierCapacite() {
    bool isValid;
    int capaciteValue = ui->capacite->text().toInt(&isValid);

    if ( !isValid || capaciteValue < 0) {
       // QMessageBox::warning(this, "Erreur", "La capacité doit être un nombre entier positif.");
        return;
    }

    // Si la capacité est valide, vous pouvez procéder à l'ajout ou à toute autre action
    on_ajouter_clicked();
}
void gestion_evenement::on_annuler_clicked()//annuler
{
    ui->nomevent->clear();
    ui->lieu->clear();
    ui->datedeb->setDate(QDate::currentDate());
    ui->datefin->setDate(QDate::currentDate());
    ui->description->clear();
    ui->comboBox->clear();
    ui->capacite->clear();
}


void gestion_evenement::supprimer()
{
    QPushButton *senderButton= qobject_cast<QPushButton*>(sender());
    if(!senderButton)
        return;
int ide=senderButton->objectName().toInt();
QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                 "Êtes-vous sûr de vouloir supprimer cet évènement ?",
                                                                 QMessageBox::Yes | QMessageBox::No);
if (confirmation == QMessageBox::Yes) {
    Evenement E;
    bool success = E.supprimer(ide);
    if (success) {
        QMessageBox::information(this, "Succès", "évènement supprimé avec succès.");
        ui->afficher->click();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'évènement.");
    }
}
}
int gestion_evenement::SearchRow(int id) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 0)->text().toInt() == id) { // Assuming id is stored in the second column (index 1)
            return row;
        }
    }
    return -1;
}

void gestion_evenement::Modifier()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;

    int id = senderButton->objectName().toInt();
    int row = SearchRow(id);
    if (row != -1) {
        QAbstractItemModel *model = ui->tableWidget->model();
        if (!model) {
            qDebug() << "Erreur: Le modÃ¨le n'est pas de type QSqlQueryModel.";
            return;
        }

        if (row < 0 || row >= model->rowCount()) {
            qDebug() << "Erreur: L'indice de ligne est en dehors des limites.";
            return;
        }

        int ide = model->data(model->index(row, 0)).toInt();
        QString nomevent = model->data(model->index(row, 1)).toString();
        QString lieu = model->data(model->index(row, 2)).toString();
        QDate datedeb = model->data(model->index(row, 3)).toDate();
        QDate datefin = model->data(model->index(row, 4)).toDate();
        QString description = model->data(model->index(row, 5)).toString();
        QString statut = model->data(model->index(row, 6)).toString();
        int capacite = model->data(model->index(row, 7)).toInt();
        Evenement F( ide, nomevent, lieu, datedeb, datefin, description, statut , capacite);
        F.Modifier(F, ide);
    }
}

//BEGIN filterTable
void gestion_evenement::filterTable(const QString &text) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden(row, !match);
    }
}
//END filterTable

void gestion_evenement::on_telecharger_clicked()
{

    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");

            if (filename.isEmpty()) {
                return;  // Annuler si aucun fichier n'est sélectionné
            }

            // Créer un modèle de document texte pour stocker les données du tableau
            QTextDocument doc;

            // Créer un curseur pour manipuler le document texte
            QTextCursor cursor(&doc);

            // Insérer l'image dans le document avec une largeur fixe de 100 pixels
            QImage image("C:/Users/Kinza/Downloads/423062592_412565247809359_4122753196054595283_n.png");
            if (!image.isNull()) {
                cursor.insertImage(image.scaledToWidth(100));
                cursor.insertBlock();
            }

            // Insérer le titre avant le tableau
            QTextBlockFormat titleFormat;
            titleFormat.setAlignment(Qt::AlignHCenter);
            cursor.insertBlock(titleFormat); // Insérer un bloc vide pour le titre

            // Configurer la police du titre
            QTextCharFormat titleCharFormat;
            titleCharFormat.setFontPointSize(16); // Ajustez la taille de la police selon vos besoins
            cursor.setCharFormat(titleCharFormat);
            cursor.insertText("Tableau des évènements"); // Insérer le texte du titre

            // Réinitialiser la configuration de la police
            cursor.setCharFormat(QTextCharFormat());
            cursor.insertBlock(); // Insérer une ligne vide après le titre

            // Récupérer le modèle associé à votre QTableView
            QAbstractItemModel *model = ui->tableWidget->model();

            // Définir le format de texte pour le tableau (bordures et alignement)
            QTextTableFormat tableFormat;
            tableFormat.setBorder(1); // Épaisseur de la bordure
            tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
            tableFormat.setAlignment(Qt::AlignHCenter);
            QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount() - 2, tableFormat);

            // Remplir le tableau avec les données du modèle
            for (int row = 0; row < model->rowCount(); ++row) {
                for (int col = 0; col < model->columnCount() - 2; ++col) {
                    // Obtenir l'élément de données à la position (row, col)
                    QVariant data = model->data(model->index(row, col));

                    // Insérer les données dans les cellules du tableau
                    QTextTableCell cell = table->cellAt(row + 1, col);
                    QTextCursor cellCursor = cell.firstCursorPosition();
                    cellCursor.insertText(data.toString());
                }
            }

            // Définir les en-têtes de colonne
            for (int col = 0; col < model->columnCount() - 2; ++col) {
                // Obtenir l'élément de données de l'en-tête de colonne
                QVariant headerData = model->headerData(col, Qt::Horizontal);

                // Insérer les en-têtes dans la première ligne du tableau
                QTextTableCell cell = table->cellAt(0, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(headerData.toString());
            }

            // Configurer l'imprimante pour exporter le document texte au format PDF
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(filename);

            // Imprimer le document texte sur l'imprimante
            doc.print(&printer);

            // Afficher un message de confirmation
            QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
}

void gestion_evenement::genererStatistique()
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
    statisDialog->show();
}

void gestion_evenement::on_stat_clicked()
{
    genererStatistique();
}
void gestion_evenement::gestionRappels() {
    QDate currentDate = QDate::currentDate();
    Evenement K;

    QList<Evenement> listeEvenements = K.getEvenementsPourDate(currentDate);

    if (listeEvenements.isEmpty()) {
        QMessageBox::information(this, "Rappels", "Aucun événement pour la date actuelle.");
        return;
    }

    // Construire le message pour le QMessageBox
    QString messageBoxMessage = "Événements pour la date actuelle :\n\n";
    for (const Evenement &evenement : listeEvenements) {
        QDate dateDebut = evenement.getDatedeb();
        QDate dateFin = evenement.getDatefin();
        int duree = dateDebut.daysTo(dateFin) + 1;

        messageBoxMessage += QString("Nom de l'événement : %1\n")
                       .arg(evenement.getNomevent());
        messageBoxMessage += QString("Date de début : %1\n")
                       .arg(dateDebut.toString("dd/MM/yyyy"));
        messageBoxMessage += QString("Lieu : %1\n")
                       .arg(evenement.getLieu());
        messageBoxMessage += QString("Durée : %1 jours\n")
                       .arg(duree);
        messageBoxMessage += QString("Date de fin : %1\n\n")
                       .arg(dateFin.toString("dd/MM/yyyy"));
    }



    // Afficher les événements dans un QMessageBox
    QMessageBox::information(this, "Rappels", messageBoxMessage);
}



// Fonction pour obtenir la liste des événements à venir
QList<Evenement> gestion_evenement::obtenirEvenementsAVenir() {
    QList<Evenement> evenementsAVenir;

        // Récupérer la date actuelle
        QDate dateActuelle = QDate::currentDate();

        // Se connecter à la base de données pour récupérer les événements prévus dans le futur
        // Supposons que vous ayez une méthode statique dans la classe Kenza pour récupérer les événements futurs
        QList<Evenement> tousEvenements = Evenement::getListeEvenements();

        // Filtrer les événements prévus dans le futur
        for (const Evenement &evenement : tousEvenements) {
            if (evenement.getDatedeb() > dateActuelle) {
                // L'événement est prévu dans le futur
                evenementsAVenir.append(evenement);
            }
        }

        return evenementsAVenir;
}

// Fonction pour afficher une notification pour un événement
void gestion_evenement::afficherNotification(const Evenement &evenement) {

    QLabel *rappelLabel = new QLabel();

       // Récupérer le nom de l'événement à partir de l'objet evenement
       QString nomEvent = evenement.getNomevent();

       // Créer une QTextStream pour formater le texte
       QTextStream stream;
       stream.setString(&nomEvent);

       // Ajouter du HTML pour mettre le nom de l'événement en gras
       stream << QStringLiteral("<b>") << nomEvent << QStringLiteral("</b>");

       // Créer le texte du rappel
       QString rappel = QStringLiteral("<p>L'événement ") + stream.string() + QStringLiteral(" aura lieu le ") + evenement.getDatedeb().toString("dd/MM/yyyy") + QStringLiteral(" dans ") + evenement.getLieu() + QStringLiteral(" et va durer ") + QString::number(evenement.getDatedeb().daysTo(evenement.getDatefin())) + QStringLiteral(" jours et va finir le ") + evenement.getDatefin().toString("dd/MM/yyyy") + QStringLiteral("</p>");

       // Définir le texte du QLabel
       rappelLabel->setText(rappel);

}

void gestion_evenement::on_pushButton_15_clicked()
{
    calendriers *calendrierPage = new calendriers(this);

       // Récupérer la liste des événements
       QList<Evenement> listeEvenements = Evenement::getListeEvenements();

       // Passer la liste des événements à la fenêtre du calendrier
       calendrierPage->setListeEvenements(listeEvenements);

       // Afficher le calendrier
       calendrierPage->show();
}
