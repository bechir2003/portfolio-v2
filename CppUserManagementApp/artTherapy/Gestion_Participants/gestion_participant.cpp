#include "gestion_participant.h"
#include "ui_gestion_participant.h"
#include "statistique.h"
#include <QApplication>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>
#include <QKeyEvent>
#include <QTableWidget>
#include <QTextDocumentWriter>
#include <QTextStream>
#include <QTextTable>
#include <QTextTableCellFormat>
#include <QStandardItemModel>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTableCell>
#include <QSqlError>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QGraphicsView>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
gestion_participant::gestion_participant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_participant)
{

    ui->setupUi(this);

    connect(ui->scan_CIN, &QPushButton::clicked, this, &gestion_participant::scan_CIN);
    QValidator *cinValidator = new QIntValidator(10000000, 99999999, this);

    ui->CIN->setValidator(cinValidator);
    QRegExp rx1("[0-9]{8}");
    QRegExpValidator *validator = new QRegExpValidator(rx1, this);
    ui->num_tel->setValidator(validator);
    QRegExp rx2("[a-zA-Z]+");
    QValidator *nameValidator = new QRegExpValidator(rx2, this);
    ui->nom->setValidator(nameValidator);

    //BEGIN menu
    connect(ui->Menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu

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

    ui->prenom->setValidator(nameValidator);
    QRegExp rx3("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    QValidator *emailValidator = new QRegExpValidator(rx3, this);
    ui->email->setValidator(emailValidator);
    detectAfficher(0);
}

void gestion_participant::ShowMenu(){
    ui->Menu->raise();
}

void gestion_participant::HideMenu(){
    ui->Menu->lower();
}

gestion_participant::~gestion_participant()
{
    delete ui;
}
//BEGIN LOGOUT
void gestion_participant::on_logout_clicked(){
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
//END LOGOUT

void gestion_participant::supprimer()
{
    QPushButton *senderButton= qobject_cast<QPushButton*>(sender());
        if(!senderButton)
            return;
    int CIN=senderButton->objectName().toInt();
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                     "Êtes-vous sûr de vouloir supprimer ce participant ?",
                                                                     QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::Yes) {
        Participant p;
        bool success = p.supprimer(CIN);
        if (success) {
            QMessageBox::information(this, "Succès", "partcipant supprimé avec succès.");
            detectAfficher(0);
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de supprimer le participant.");
        }
    }
}
int gestion_participant::SearchRow(int id) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 0)->text().toInt() == id) { // Assuming id is stored in the second column (index 1)
            return row;
        }
    }
    return -1; // Return -1 if the row with the given id is not found
}

//BEGIN detectAfficher
void gestion_participant::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m= Participant::afficher();
    }
    else if(code==1){
        m->setQuery("select * from Participant order by sexe;");
    }
    else if(code==2){
        m->setQuery("select * from Participant order by sexe desc;");
    }
    else if(code==3){
        m->setQuery("select * from Participant order by datenaiss;");
    }
    else if(code==4){
        m->setQuery("select * from Participant order by datenaiss desc;");
    }
    else if(code==5){
        m->setQuery("select * from Participant order by prenom;");
    }
    else if(code==6){
        m->setQuery("select * from Participant order by prenom desc;");
    }
    afficher(m);
}
//END detectAfficher

void gestion_participant::ModifierP()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;

    int id = senderButton->objectName().toInt();
    int row = SearchRow(id);
    if (row != -1) {
        QString newNom = ui->tableWidget->item(row, 1)->text();
                QString newPrenom = ui->tableWidget->item(row, 2)->text();
                QString newAdresse = ui->tableWidget->item(row, 4)->text();
                QString newEmail = ui->tableWidget->item(row, 7)->text();
                QString newNumTel = ui->tableWidget->item(row, 5)->text();

                // Vérification du format du nom
                QRegExp nomRx("^[a-zA-Z]+$"); // Expression régulière pour les lettres uniquement
                if (!nomRx.exactMatch(newNom)) {
                    QMessageBox::warning(this, "Erreur", "Le nom doit contenir uniquement des lettres.");
                    return;
                }

                // Vérification du format du prénom
                if (!nomRx.exactMatch(newPrenom)) {
                    QMessageBox::warning(this, "Erreur", "Le prénom doit contenir uniquement des lettres.");
                    return;
                }

                // Vérification du format de l'e-mail
                QRegExp emailRx("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
                if (!emailRx.exactMatch(newEmail)) {
                    QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide.");
                    return;
                }

                // Vérification du format du numéro de téléphone
                QRegExp rx("\\d{8}");
                if (!rx.exactMatch(newNumTel)) {
                    QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit être composé de 8 chiffres.");
                    return;
                }
        QAbstractItemModel *model = ui->tableWidget->model();
        if (!model) {
            qDebug() << "Erreur: Le modèle n'est pas de type QSqlQueryModel.";
            return;
        }

        if (row < 0 || row >= model->rowCount()) {
            qDebug() << "Erreur: L'indice de ligne est en dehors des limites.";
            return;
        }

        int CIN = model->data(model->index(row, 0)).toInt(); // Supposant que CIN est dans la première colonne
        QString nom = model->data(model->index(row, 1)).toString(); // Supposant que le nom est dans la deuxième colonne
        QString prenom = model->data(model->index(row, 2)).toString(); // Supposant que le prénom est dans la troisième colonne
        QDate date_naiss = model->data(model->index(row, 3)).toDate(); // Supposant que la date de naissance est dans la quatrième colonne
        QString adresse = model->data(model->index(row, 4)).toString(); // Supposant que l'adresse est dans la cinquième colonne
        int num_tel = model->data(model->index(row, 5)).toInt(); // Supposant que le numéro de téléphone est dans la sixième colonne
        QString sexe = model->data(model->index(row, 6)).toString(); // Supposant que le sexe est dans la septième colonne
        QString email = model->data(model->index(row, 7)).toString(); // Supposant que l'email est dans la huitième colonne

        Participant P(CIN, nom, prenom, date_naiss, adresse, num_tel, sexe, email);
        P.ModifierParticipant(P, CIN);
    }
}
void gestion_participant::on_ajouter_clicked()
{
    QString nom = ui->nom->text();
    QString CINString = ui->CIN->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    QString sexe = "";
    if(ui->homme->isChecked()) {
        sexe = "homme";
    } else if(ui->femme->isChecked()) {
        sexe = "femme";
    }
    QString num_tel_string = ui->num_tel->text();
    QString adresse = ui->adresse->text();
    QDate date_naiss = ui->date_naiss->date();
    QString emailString = ui->email->text();

    // Vérification du format de l'e-mail
    QRegExp emailRx("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    if (!emailRx.exactMatch(emailString)) {
        QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide.");
        return;
    }
    // Vérification du format du CIN
    QRegExp rx("\\d{8}"); // Expression régulière pour 8 chiffres
    if (!rx.exactMatch(CINString)) {
        QMessageBox::warning(this, "Erreur", "Le CIN doit être composé de 8 chiffres.");
        return;
    }
    int CIN = CINString.toInt();

    // Vérification du format du numéro de téléphone
    if (!rx.exactMatch(num_tel_string)) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit être composé de 8 chiffres.");
        return;
    }
    int num_tel = num_tel_string.toInt();

    // Vérification du format du nom
    QRegExp nomRx("^[a-zA-Z]+$"); // Expression régulière pour les lettres uniquement
    if (!nomRx.exactMatch(nom)) {
        QMessageBox::warning(this, "Erreur", "Le nom doit contenir uniquement des lettres.");
        return;
    }
    // Vérification du choix du sexe
        QString sexe2;
        if (ui->homme->isChecked()) {
            sexe2 = "homme";
        } else if (ui->femme->isChecked()) {
            sexe2 = "femme";
        } else {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner le sexe.");
            return;
        }
        if (date_naiss > QDate::currentDate()) {
                QMessageBox::warning(this, "Erreur", "La date de naissance ne peut pas être postérieure à la date d'aujourd'hui.");
                return;
            }

    Participant p(CIN, nom, prenom, date_naiss, adresse, num_tel, sexe, email);

    bool test = p.ajouter_P();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("Système"), QObject::tr("Participant ajouté avec succès.\n"));
        // Nettoyer les champs après l'ajout
        ui->nom->clear();
        ui->CIN->clear();
        ui->prenom->clear();
        ui->email->clear();
        ui->homme->setChecked(false);
        ui->femme->setChecked(false);
        ui->num_tel->clear();
        ui->adresse->clear();
        ui->date_naiss->setDate(QDate::currentDate());
        detectAfficher(0); // Rafraîchir l'affichage
    }
    else {
        QMessageBox::information(nullptr, QObject::tr("Système"), QObject::tr("Erreur lors de l'ajout.\n"));
    }
}



void gestion_participant::afficher(QSqlQueryModel *model)
{
    ui->rechercher->clear();
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
        QPushButton *deleteButton = new QPushButton(" ", ui->tableWidget);
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
              connect(deleteButton, &QPushButton::clicked, this, &gestion_participant::supprimer);
              int CIN = model->data(model->index(row, 0)).toInt();
              deleteButton->setObjectName(QString::number(CIN));

              QPushButton *modifierButton = new QPushButton(" ", ui->tableWidget);
                    modifierButton->setStyleSheet("QPushButton {"
                                                  "padding: 5px;"             // Rembourrage de 5 pixels
                                                  "font-size: 16px;"          // Taille de la police de caractères
                                                  "text-align: center;"       // Alignement du texte au centre
                                                  "text-decoration: none;"    // Aucune décoration de texte
                                                  "border: 2px solid #43aff7;"// Bordure de 2 pixels solide avec couleur #43aff7
                                                  "color: #43aff7;"           // Couleur du texte #43aff7
                                                  "border-radius: 5px;"       // Bordure arrondie de 5 pixels
                                                  "background-image: url(\"images/edit.svg\");" // Chemin de l'image
                                                  "background-repeat: no-repeat;" // Pas de répétition d'arrière-plan
                                                  "background-position: left center;" // Position de l'arrière-plan à gauche et centrée
                                                  "padding-left: 30px;"      // Rembourrage à gauche de 30 pixels
                                              "}"

                                              "QPushButton:hover {"
                                                  "background-color: #792382;" // Couleur de fond en survol #792382
                                              "}"
);
                    ui->tableWidget->setCellWidget(row, model->columnCount()+1, modifierButton);
                    connect(modifierButton, &QPushButton::clicked, this, &gestion_participant::ModifierP);
                    modifierButton->setObjectName(QString::number(CIN));
                }

                QLayout *existingLayout = layout();
                if (existingLayout) {

                    QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
                    if (verticalLayout) {
                        verticalLayout->addWidget(ui->tableWidget);
                    }
                }

}

void gestion_participant::on_annuler_clicked()
{
    ui->CIN->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->adresse->clear();
    ui->email->clear();
    ui->num_tel->clear();
    ui->date_naiss->setDate(QDate::currentDate());
}


void gestion_participant::on_telecharger_clicked()
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
        QImage image("C:/Users/user/Documents/PROJET C++/logo kbirrr.png");
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
        cursor.insertText("Tableau des participants"); // Insérer le texte du titre

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


void gestion_participant::on_rechercher_textChanged(const QString &text)
{
    QString searchText = "%" + text + "%"; // Ajoutez les "%" avant et après le texte de recherche

        // Construire la requête SQL en fonction du texte de recherche
        QString queryText = "SELECT * FROM PARTICIPANT WHERE NOM LIKE :searchText OR NUM_TEL LIKE :searchText OR PRENOM LIKE :searchText OR CIN LIKE :searchText";

        // Préparation de la requête SQL avec des liaisons de paramètres
        QSqlQuery query;
        query.prepare(queryText);
        query.bindValue(":searchText", searchText);

        // Exécution de la requête SQL
        if (query.exec()) {
            int row = 0;
            ui->tableWidget->clearContents(); // Effacer le contenu actuel du QTableWidget

            while (query.next()) {
                int CIN = query.value(0).toInt();
                QString nom = query.value(1).toString();
                QString prenom = query.value(2).toString();
                QString date_naiss = query.value(3).toString();
                QString adresse = query.value(4).toString();
                int num_tel = query.value(5).toInt();
                QString sexe = query.value(6).toString();
                QString email = query.value(7).toString();


                // Ajouter une nouvelle ligne
                ui->tableWidget->setRowCount(row + 1);

                // Ajouter les éléments individuels
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(CIN)));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(prenom));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(date_naiss));
                ui->tableWidget->setItem(row, 4, new QTableWidgetItem(adresse));
                ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(num_tel)));
                ui->tableWidget->setItem(row, 6, new QTableWidgetItem(sexe));
                ui->tableWidget->setItem(row, 7, new QTableWidgetItem(email));


                QPushButton *btnSupprimer = new QPushButton("Supprimer");
                QPushButton *btnModifier = new QPushButton("Modifier");

                // Appliquer le style au bouton Supprimer
                btnSupprimer->setStyleSheet("QPushButton {"
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
                                        "}");
                connect(btnSupprimer, &QPushButton::clicked, this, &gestion_participant::supprimer);
               btnModifier->setStyleSheet("QPushButton {"
                                          "padding: 5px;"             // Rembourrage de 5 pixels
                                          "font-size: 16px;"          // Taille de la police de caractères
                                          "text-align: center;"       // Alignement du texte au centre
                                          "text-decoration: none;"    // Aucune décoration de texte
                                          "border: 2px solid #43aff7;"// Bordure de 2 pixels solide avec couleur #43aff7
                                          "color: #43aff7;"           // Couleur du texte #43aff7
                                          "border-radius: 5px;"       // Bordure arrondie de 5 pixels
                                          "background-image: url(\"images/edit.svg\");" // Chemin de l'image
                                          "background-repeat: no-repeat;" // Pas de répétition d'arrière-plan
                                          "background-position: left center;" // Position de l'arrière-plan à gauche et centrée
                                          "padding-left: 30px;"      // Rembourrage à gauche de 30 pixels
                                      "}"

                                      "QPushButton:hover {"
                                          "background-color: #792382;" // Couleur de fond en survol #792382
                                      "}");
               connect(btnModifier, &QPushButton::clicked, this, &gestion_participant::ModifierP);


                // Placer les boutons dans le QTableWidget
                ui->tableWidget->setCellWidget(row, 8, btnSupprimer);
                ui->tableWidget->setCellWidget(row, 9, btnModifier);


                ++row;
            }
        } else {
            // Gestion des erreurs si la requête échoue
            qDebug() << "Erreur SQL:" << query.lastError().text();
        }

}



void gestion_participant::on_statistique_clicked() {
    Participant p;
    QVector<QString> sexe;
    QSqlQueryModel* model = p.afficher();
    if (!model) {
        qDebug() << "Erreur : Impossible d'afficher les participants.";
        return;
    }

    // Collect unique sexes
    for (int row = 0; row < model->rowCount(); ++row) {
        QString sex = model->data(model->index(row, 6)).toString();
        if (!sexe.contains(sex)) {
            sexe.append(sex);
        }
    }

    QBarSeries *barSeries = new QBarSeries();

    // Create a bar set for each unique sex
    for (int i = 0; i < sexe.size(); ++i) {
        QBarSet *barSet = new QBarSet(sexe.at(i));

        // Count occurrences of this sex in the dataset
        int count = 0;
        for (int row = 0; row < model->rowCount(); ++row) {
            QString sex = model->data(model->index(row, 6)).toString();
            if (sex == sexe.at(i)) {
                count++;
            }
        }

        *barSet << count; // Add count as the value for this bar set
        barSeries->append(barSet);
    }

    QChart *chart = new QChart();
    chart->addSeries(barSeries);

    // Set title for the chart
    chart->setTitle("Les Statistiques selon le sexe ");

    // Create horizontal axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("");
    chart->createDefaultAxes();
    chart->setAxisX(axisX, barSeries);

    // Set chart size
    chart->setMinimumSize(800, 600);

    // Set font size
    QFont font = chart->titleFont();
    font.setPixelSize(20);
    chart->setTitleFont(font);
    axisX->setLabelsFont(font);

    // Create an instance of Statistique and show it
    Statistique *statisDialog = new Statistique(chart, this);
    statisDialog->show();
}


void gestion_participant::sendConfirmationEmail(int id_p,int id_e)
{
    QSqlQuery query;
    QString participantEmail = "";
    QString prenom = "";

    query.prepare("SELECT email,prenom from participant where cin=:id");
    query.bindValue(":id",id_p);
    query.exec();
    if(query.next()){
        participantEmail = query.value(0).toString();
        prenom = query.value(1).toString();
    }


    QSqlQuery query1;

    query1.prepare("SELECT nom,LIEU,DESCRIPTION, DATEDEB,DATEFIN FROM evenement where ide=:id_e");
    query1.bindValue(":id_e", id_e);

    if (query1.exec()) {
        if (query1.next()) {

            QString nom_evenement = query1.value(0).toString();
            QString lieu = query1.value(1).toString();
            QString description = query1.value(2).toString();
            QString date_deb = query1.value(3).toString();
            QString date_fin = query1.value(4).toString();

            QStringList arguments;
            arguments << "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\mail_participant.py" << participantEmail << prenom<< nom_evenement << lieu << description << date_deb << date_fin ;
            QProcess::startDetached("python", arguments);

            QMessageBox::information(this, "E-mail envoyé", "L'e-mail de confirmation a été envoyé avec succès.");
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Adresse e-mail introuvable dans la base de données.\n"));
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'exécution de la requête SQL.\n"));
    }
}

void gestion_participant::scan_CIN()
{
    QProcess process;
        // Set the command to execute the Python script directly
        QString pythonCommand = "python"; // Command to execute Python interpreter
        QStringList scriptArgs;

        scriptArgs << "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\cinScan.py";

        // Start the process with the specified command and arguments
        process.start(pythonCommand, scriptArgs);

        // Wait for the process to finish
        process.waitForFinished(-1);
        QString result = process.readAllStandardOutput();
        ui->CIN->setText(result);
}


void gestion_participant::on_rafraichir_ajouter_p_clicked()
{
    detectAfficher(0);
    ui->nom->clear();
    ui->CIN->clear();
    ui->prenom->clear();
    ui->email->clear();
    ui->homme->setChecked(false);
    ui->femme->setChecked(false);
    ui->num_tel->clear();
    ui->adresse->clear();
    ui->date_naiss->setDate(QDate::currentDate());
    ui->afficher->click();
}
