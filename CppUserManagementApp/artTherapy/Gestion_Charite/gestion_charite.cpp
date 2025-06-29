#include "gestion_charite.h"
#include "ui_gestion_charite.h"
#include "charite.h"
#include <QMessageBox>
#include <iostream>
#include <QStandardItemModel>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTableCell>
#include <QDebug>
#include <QRegExp >
#include <QRegExpValidator>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QGraphicsView>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "sta.h"
#include <QDate>
#include <QProcess>
#include <QCoreApplication>
#include <QDialog>

QT_CHARTS_USE_NAMESPACE


gestion_charite::gestion_charite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_charite)
{

    ui->setupUi(this);

    ui->tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tv->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tv->setSelectionBehavior(QAbstractItemView::SelectRows);

    //BEGIN menu
    connect(ui->Menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu

    connect(ui->refresh, &QPushButton::clicked, this, [=](){
        detectAfficher(0);
    });

    //BEGIN filterTable
    connect(ui->recherche, &QLineEdit::textChanged, this, &gestion_charite::filterTable);
    //END filterTable
    connect(ui->tableW, &QTableWidget::itemClicked, this, &gestion_charite::recuperer_num_charite);

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


    QStringList statutOptions = {"espece", "cheque"};

            // Assurez-vous que le nom du QComboBox est correct (ici, comboBoxStatut)
            ui->methode->addItems(statutOptions);
            QStringList statutOption = { "en cours", "termine"};

                    // Assurez-vous que le nom du QComboBox est correct (ici, comboBoxStatut)
                    ui->statut->addItems(statutOption);


                    ui->date->setDate(QDate::currentDate());
                              ui->date->setDate(QDate::currentDate()); QDateEdit *dateDebEdit = ui->date;

                           // Créer un validateur pour les champs d'entrée (accepte uniquement des alphabets et exige au moins un caractère)
                           QRegExpValidator *validator = new QRegExpValidator(QRegExp("[a-zA-Z]+"), this);

                           // Appliquer le validateur à tous les champs
                           ui->destination->setValidator(validator);
                           //ui->contact->setValidator(validator);

                              QDateEdit *date = ui->date;

                              connect(dateDebEdit, &QDateEdit::dateChanged, [ date](const QDate &dateDonation) {
                                  date->setMinimumDate(dateDonation);
                              });
                              QDoubleValidator *montantValidator = new QDoubleValidator(0.0, 1000000.0, 2, this);
                              ui->montant->setValidator(montantValidator);

                               detectAfficher(0);
    }


gestion_charite::~gestion_charite()
{
    delete ui;
}

void gestion_charite::ShowMenu(){
    ui->Menu->raise();
}

void gestion_charite::HideMenu(){
    ui->Menu->lower();
}

void gestion_charite::on_ajouter_clicked()//ajout de charite
{
    Charite c;
    c.somme_tot_charite();
    float solde = c.recuperer_solde_caisse();
    QString destination = ui->destination->text();
    float montant = ui->montant->text().toFloat();
    QDate dateDonation = ui->date->date();
    QString methodeDonation = ui->methode->currentText();
    QString contact = ui->contact->text();
    QString statut = ui->statut->currentText();

    Charite C(destination, montant, dateDonation, methodeDonation, contact, statut);

    if ( destination.isEmpty() || montant == 0 || methodeDonation.isEmpty() || contact.isEmpty() || statut.isEmpty()) {
    QMessageBox::critical(nullptr, tr("Erreur"), tr("Veuillez remplir tous les champs."));
    return;
        }
    if (montant>solde)
    {
        QMessageBox::critical(nullptr,tr("erreur"),tr("le solde de la caisse est insuffisant !"));
                return;
    }
    bool ajoutReussi = C.ajouter();

    send_sms();
    c.nouveau_solde_caisse();


    if (ajoutReussi) {
    QMessageBox::information(nullptr, tr("Ajout réussi"), tr("Charité ajoutée avec succès !"));
    // Clear input fields
    ui->destination->clear();
    ui->montant->clear();
    ui->date->setDate(QDate::currentDate());
    ui->contact->clear();

    detectAfficher(0);
    }
     else {
    QMessageBox::critical(nullptr, tr("Erreur d'ajout"), tr("Échec de l'ajout de la charité."));
    }
}


void gestion_charite::on_annuler_clicked()
{
    ui->destination->clear();
    ui->montant->clear();
    ui->date->setDate(QDate::currentDate());
    ui->contact->clear();
}

void gestion_charite::filterTable(const QString &text) {
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

void gestion_charite::afficher(QSqlQueryModel* model)
{

    ui->tableW->setRowCount(model->rowCount());
    ui->tableW->setColumnCount(model->columnCount()+2);
    QStringList headers;
    for(int i=0;i<model->columnCount();i++)
    {
        headers<<model->headerData(i,Qt::Horizontal).toString();
    }
    headers<<"SUPPRIMER"<<"MODIFIER";
    ui->tableW->setHorizontalHeaderLabels(headers);
    for(int row=0;row<model->rowCount();row++)
    {
        for(int column=0;column<model->columnCount();column++)
    {
        QTableWidgetItem *item=new QTableWidgetItem(model->data(model->index(row,column)).toString());
        ui->tableW->setItem(row,column,item);
    }
    QPushButton *deleteButton = new QPushButton("Supprimer", ui->tableW);
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
                                      "color: #ffff;"              // Couleur du texte en survol blanc
                                  "}"

            );
          ui->tableW->setCellWidget(row, model->columnCount(), deleteButton);
          connect(deleteButton, &QPushButton::clicked, this, &gestion_charite::supprimer);
          int num_charite = model->data(model->index(row, 0)).toInt();
          deleteButton->setObjectName(QString::number(num_charite));

          QPushButton *modifierButton = new QPushButton("Modifier", ui->tableW);
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
                                              "color: #ffff;"              // Couleur du texte en survol blanc
                                          "}"

                );
                ui->tableW->setCellWidget(row, model->columnCount()+1, modifierButton);
                connect(modifierButton, &QPushButton::clicked, this, &gestion_charite::Modifier);
                modifierButton->setObjectName(QString::number(num_charite));
            }

            QLayout *existingLayout = layout();
            if (existingLayout) {

                QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
                if (verticalLayout) {
                    verticalLayout->addWidget(ui->tableW);
                }
            }
    solde_caisse();
}

void gestion_charite::supprimer()
{
    QPushButton *senderButton= qobject_cast<QPushButton*>(sender());
    if(!senderButton)
        return;
    int num_charite=senderButton->objectName().toInt();
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                             "Êtes-vous sûr de vouloir supprimer ce participant ?",
                                                             QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::Yes) {
    Charite p;
    bool success = p.supprimer(num_charite);
    if (success) {
        QMessageBox::information(this, "Succès", "charite supprimé avec succès.");
        detectAfficher(0);
    }
    else
        {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer la charite.");
        }
    }
}

int gestion_charite::SearchRow(int id)
{
    for (int row = 0; row < ui->tableW->rowCount(); ++row)
    {
        if (ui->tableW->item(row, 0)->text().toInt() == id)
        {
            return row;
        }
    }
    return -1;
}


void gestion_charite::Modifier()
{

QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
  if (!senderButton)
      return;

  int id = senderButton->objectName().toInt();
  int row = SearchRow(id);
  if (row != -1) {
      QAbstractItemModel *model = ui->tableW->model();
      if (!model)
      {
          qDebug() << "Erreur: Le modèle n'est pas de type QSqlQueryModel.";
          return;
      }

      if (row < 0 || row >= model->rowCount())
      {
          qDebug() << "Erreur: L'indice de ligne est en dehors des limites.";
          return;
      }

      QString destination= model->data(model->index(row, 1)).toString();
      float montant = model->data(model->index(row, 2)).toFloat();
       QDate dateDonation = model->data(model->index(row, 3)).toDate();
      QString methodeDonation = model->data(model->index(row, 4)).toString();
      QString contact= model->data(model->index(row, 5)).toString();
      QString statut = model->data(model->index(row, 6)).toString();

      Charite P( destination, montant, dateDonation, methodeDonation, contact, statut);
      bool test = P.Modifier(P, id);
      if(test){
          detectAfficher(0);
      }
  }
}

//BEGIN detectAfficher
void gestion_charite::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m= Charite::afficher();
    }
    else if(code==1){
        m->setQuery("select * from charites order by montant;");
    }
    else if(code==2){
        m->setQuery("select * from charites order by montant desc;");
    }
    else if(code==3){
        m->setQuery("select * from charites order by DATE_D;");
    }
    else if(code==4){
        m->setQuery("select * from charites order by DATE_D desc;");
    }
    else if(code==5){
        m->setQuery("select * from charites order by DESTINATION;");
    }
    else if(code==6){
        m->setQuery("select * from charites order by DESTINATION desc;");
    }
    afficher(m);
}
//END detectAfficher


void gestion_charite::on_methode_activated()
{
    QString methodeDonation= ui->methode->currentText();
}

void gestion_charite::on_statut_activated()
{
    QString statut= ui->statut->currentText();
}

void gestion_charite::on_telecharger_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;
        QTextCursor cursor(&doc);
        cursor.insertBlock(); // Insérer une ligne vide après le titre
        QImage image("C:/Users/maher/Downloads/423062592_412565247809359_4122753196054595283_n.png");
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
        cursor.insertText("Tableau des charités"); // Insérer le texte du titre
        // Réinitialiser la configuration de la police
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock(); // Insérer une ligne vide après le titre
        QAbstractItemModel *model = ui->tableW->model();
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1); // Épaisseur de la bordure
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);
        QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount()-2, tableFormat);
        // Remplir le tableau avec les données du modèle
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount()-2; ++col) {
                // Obtenir l'élément de données à la position (row, col)
                QVariant data = model->data(model->index(row, col));
                // Insérer les données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(data.toString());
            }
        }
        // Définir les en-têtes de colonne
        for (int col = 0; col < model->columnCount()-2; ++col) {
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
}

void gestion_charite::on_stat_clicked()
{

genererStatistique();
}
void gestion_charite::genererStatistique() {
// Supposons que Charite est votre classe pour accéder aux données de Charite
Charite charite;

// Utilisez une QMap pour stocker les montants par destination
QMap<QString, qreal> montantsParDestination;

// Effectuez une nouvelle requête pour récupérer les données mises à jour
QScopedPointer<QSqlQueryModel> model(charite.afficher());
if (!model) {
    qDebug() << "Erreur : Impossible d'afficher les données de la classe Charite.";
    return;
}

// Parcourez les données pour remplir la QMap
for (int row = 0; row < model->rowCount(); ++row) {
    QString destination = model->data(model->index(row, 1)).toString();
    qreal montant = model->data(model->index(row, 2)).toFloat();

    // Ajoutez le montant à la QMap pour cette destination
    montantsParDestination[destination] += montant;

}

// Créez un graphique à secteurs
QPieSeries *pieSeries = new QPieSeries();

QStringList colors = {"#1f77b4", "#ff7f0e", "#2ca02c", "#d62728", "#9467bd", "#8c564b"};

   // Parcourez les données pour remplir la QMap
   int colorIndex = 0;
// Ajoutez chaque destination et son montant à la série de secteurs
for (const QString &destination : montantsParDestination.keys()) {
    QPieSlice *slice = pieSeries->append(destination, montantsParDestination[destination]);
    slice->setLabel(QString("%1 : %2").arg(destination).arg(montantsParDestination[destination]));

    slice->setColor(QColor(colors[colorIndex]));

            // Passez à la couleur suivante (répétez les couleurs si nécessaire)
            colorIndex = (colorIndex + 1) % colors.size();
}

// Affichez les étiquettes avec les valeurs du montant
pieSeries->setLabelsVisible(true);

// Créez un graphique et ajoutez la série de secteurs
QChart *chart = new QChart();
chart->addSeries(pieSeries);

// Ajoutez un titre au graphique
chart->setTitle("Statistiques des montants par destination");

// Ajustez la taille du graphique
chart->setMinimumSize(800, 600); // Ajustez selon vos besoins

// Ajustez la taille de la police dans le graphique
QFont font = chart->titleFont();
font.setPixelSize(14); // Ajustez selon vos besoins
chart->setTitleFont(font);

// Créez une instance de statistique en passant le graphique
sta *statisDialog = new sta(chart, this);
statisDialog->show(); // Affichez le dialogue de statistiques
}



void gestion_charite::on_voice_clicked()
{
    int rowID=0;
    QString activationScript = "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\Python312\\myenv312\\Scripts\\activate";

    QString pythonInterpreter = "python";

    QString pythonScript = "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\Python312\\speechRecognition.py";

    QString command = QString("cmd /c \"%1 && %2 %3\"").arg(activationScript).arg(pythonInterpreter).arg(pythonScript);

    QProcess process;

    process.start(command);

    process.waitForFinished();
    QString contenu = process.readAllStandardOutput();
    qDebug() << contenu;
    // Lire le contenu du fichier reconnaissance.txt

        if (contenu.contains("add")) {

            on_ajouter_clicked();

        }else if(contenu.contains("delete")) {
            rowID = recuperer_num_charite();
            c.supprimer(rowID);
            detectAfficher(0);
        }
        else if (contenu.contains("edit")) {
            int id = recuperer_num_charite();
            int row = SearchRow(id);
            if (row != -1) {
                QAbstractItemModel *model = ui->tableW->model();
                if (!model) {
                    qDebug() << "Erreur: Le modèle n'est pas de type QSqlQueryModel.";
                    return;
                }

                if (row < 0 || row >= model->rowCount()) {
                    qDebug() << "Erreur: L'indice de ligne est en dehors des limites.";
                    return;
                }

                QString destination= model->data(model->index(row, 1)).toString();
                float montant = model->data(model->index(row, 2)).toFloat();
                 QDate dateDonation = model->data(model->index(row, 3)).toDate();
                QString methodeDonation = model->data(model->index(row, 4)).toString();
                QString contact= model->data(model->index(row, 5)).toString();
                QString statut = model->data(model->index(row, 6)).toString();

                Charite P( destination, montant, dateDonation, methodeDonation, contact, statut);
                P.Modifier(P, id);
        }
        }

}


void gestion_charite::send_sms()
{
    QString contact = ui->contact->text();
    float montant = ui->montant->text().toFloat();
    QString montantt = QString::number(montant);
    QString destination = ui->destination->text();
    QString pythonScriptPath = "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\sms.py";
    QStringList arguments;
   arguments << contact << montantt << destination;
    // Créer un objet QProcess pour exécuter le script Python
    QProcess process;
    process.start("python", QStringList() << pythonScriptPath << arguments);

    process.waitForFinished(-1);

    // Récupérer la sortie standard du processus (éventuellement)
    QByteArray output = process.readAllStandardOutput();

    // Récupérer la sortie d'erreur du processus en cas d'échec (éventuellement)
    QByteArray error = process.readAllStandardError();

    // Vérifier si le processus s'est terminé correctement
    if (process.exitCode() == 0)
    {
        QMessageBox::information(this, "Succès", " SMS envoyé avec succés .");
    }
    else
    {
        QMessageBox::warning(this, "Erreur", " sms n'etait pas envoyé ! : " + error);
    }

}

int gestion_charite::recuperer_num_charite()
{
    Charite c;
    int rowID = c.recuperer_num_charite(); // recuperation de l'id;
    qDebug() << "ID de la ligne cliquée :" << rowID;
    return rowID;
}




void gestion_charite::solde_caisse()
{
    Charite ch;
        float solde = ch.recuperer_solde_caisse();
        float somme = ch.somme_tot_charite();
        QStandardItemModel* model = new QStandardItemModel(1, 1, this);
        model->setHorizontalHeaderLabels(QStringList() << "Solde caisse" << "somme total des charité");
        model->setItem(0, 0, new QStandardItem(QString::number(solde)));
        model->setItem(0, 1, new QStandardItem(QString::number(somme)));
        ui->tv->setModel(model);
}


void gestion_charite::on_logout_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
