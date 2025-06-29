#include "gestion_achat.h"
#include "mainwindow.h"
#include "His_Achat/his_Achat.h"
#include "ui_gestion_Achat.h"

gestion_Achat::gestion_Achat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_Achat)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(A.read_from_arduino()));
    timer->setInterval(5000);
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(arduino()));
    //BEGIN menu
    connect(ui->Menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu

    //BEGIN logout
    connect(ui->logout, &QPushButton::clicked, this, &gestion_Achat::logout);
    //END logout

    //BEGIN Annuler
    connect(ui->Annuler, &QPushButton::clicked, this, &gestion_Achat::Annuler);
    //END Annuler

    //BEGIN Annuler2
    connect(ui->Annuler_2, &QPushButton::clicked, this, &gestion_Achat::Annuler2);
    //END Annuler2

    connect(ui->ajouter, &QPushButton::clicked, this, &gestion_Achat::ajouter_His_Achat);

    connect(ui->refresh, &QPushButton::clicked, this, [=](){
        detectAfficher2(0);
    });

    connect(ui->refresh_2, &QPushButton::clicked, this, [=](){
        detectAfficher(0);
    });

    //BEGIN affichage par defaut
    detectAfficher(0);
    init_His_Achat();
    //END affichage par defaut

    //BEGIN filterTable
    connect(ui->search, &QLineEdit::textChanged, this, &gestion_Achat::filterTable);
    //END filterTable

    //BEGIN filterTable
    connect(ui->search_1, &QLineEdit::textChanged, this, &gestion_Achat::filterTable2);
    //END filterTable

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

    });
    //END trier

    //BEGIN trier
    connect(ui->triCombo_1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int newIndex) {
        ui->triCombo_1->setCurrentIndex(0);
        if(newIndex == 1){
            if(ui->asc_2->isChecked()){
                detectAfficher2(1);
            }
            else if(ui->desc_2->isChecked()){
                detectAfficher2(2);
            }
        }
        else if(newIndex == 2){
            if(ui->asc_2->isChecked()){
                detectAfficher2(3);
            }
            else if(ui->desc_2->isChecked()){
                detectAfficher2(4);
            }
        }

    });
    //END trier

    //BEGIN DownloadPDF
    connect(ui->downloadPDF, &QPushButton::clicked, this, &gestion_Achat::downloadPDF);
    //END DownloadPDF

    //BEGIN DownloadPDF
    connect(ui->downloadPDF_2, &QPushButton::clicked, this, &gestion_Achat::downloadPDF2);
    //END DownloadPDF

    detectAfficher2(0);
    init_participation();
}

gestion_Achat::~gestion_Achat()
{
    delete ui;
}
//BEGIN LOGOUT
void gestion_Achat::logout(){
    MainWindow* w = new MainWindow();
    w->show();
    A.close_arduino();
    this->close();
    delete this;
}
//END LOGOUT

void gestion_Achat::ShowMenu(){
    ui->Menu->raise();
}

void gestion_Achat::HideMenu(){
    ui->Menu->lower();
}

//BEGIN afficher_His_Achat
void gestion_Achat::afficher_His_Achat(QSqlQueryModel* m){

    ui->tableW->setRowCount(m->rowCount());
    ui->tableW->setColumnCount(m->columnCount());
    QStringList headers;
    for (int col = 0; col < m->columnCount(); ++col) {
        headers << m->headerData(col, Qt::Horizontal).toString();
    }
    ui->tableW->setHorizontalHeaderLabels(headers);
    for (int row = 0; row < m->rowCount(); ++row) {
        for (int col = 0; col < m->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(m->data(m->index(row, col)).toString());
            ui->tableW->setItem(row, col, item);
        }
    }

    QLayout *existingLayout = layout();
    if (existingLayout) {

        QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
        if (verticalLayout) {
            verticalLayout->addWidget(ui->tableW);
        }
    }
}
//END afficher_His_Achat


void gestion_Achat::init_His_Achat(){
    QSqlQueryModel* model1 = new QSqlQueryModel();
    QSqlQueryModel* model2 = new QSqlQueryModel();
    QSqlQueryModel* model3 = new QSqlQueryModel();
    model1->setQuery("select ide,nom from evenement where datefin>sysdate;");
    ui->Evenement->addItem("", 0);
    for (int i = 0; i < model1->rowCount(); ++i) {
        QModelIndex index = model1->index(i, 1);
        QString eventName = model1->data(index).toString();
        QVariant eventId = model1->data(model1->index(i, 0), Qt::DisplayRole);
        ui->Evenement->addItem(eventName, eventId);
    }

    model2->setQuery("select id_o from oeuvre where etat = 'disponible';");
    ui->Oeuvre->setModel(model2);
    ui->Oeuvre->setModelColumn(model2->record().indexOf("id_o"));

    model3->setQuery("select cin,nom from participant;");
    ui->Participant->addItem("", 0);
    for (int i = 0; i < model3->rowCount(); ++i) {
        QModelIndex index = model3->index(i, 1);
        QString participantName = model3->data(index).toString();
        QVariant participantId = model3->data(model3->index(i, 0), Qt::DisplayRole);
        ui->Participant->addItem(participantName, participantId);
    }
}

void gestion_Achat::ajouter_His_Achat(){
    QSqlQuery query;

    QVariant selectedParticipantId = ui->Participant->currentData(Qt::UserRole);
    int selectedParticipantIdValue = selectedParticipantId.toInt();

    QVariant selectEevenementId = ui->Evenement->currentData(Qt::UserRole);
    int selectEevenementIdValue = selectEevenementId.toInt();

    int id_o = ui->Oeuvre->currentText().toInt();

    QDateTime date_achat = QDateTime::currentDateTime();

    query.prepare("SELECT prix FROM Oeuvre WHERE id_o = :id;");
    query.bindValue(":id", id_o);
    query.exec();

    float prix = 0.0; // Default price in case query fails
    if(query.next()) {
        prix = query.value(0).toFloat();
    } else {
        qDebug() << "Failed to retrieve price for Oeuvre with id:" << id_o;
    }

    His_Achat H(selectEevenementIdValue, id_o, selectedParticipantIdValue, date_achat, prix);
    if(!H.existance_p(id_o,selectedParticipantIdValue)){
        if(H.ajouter_achat()){
            QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Achat ajoute avec succes.\n"));

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("system"),QObject::tr("Erreur.\n"));
        }
     }
    else {
        QMessageBox::critical(nullptr, QObject::tr("system"),QObject::tr("Existttt.\n"));
    }

    detectAfficher(0);
    ui->Evenement->clear();
    ui->Participant->clear();
    init_His_Achat();
}

//BEGIN filterTable
void gestion_Achat::filterTable(const QString &text) {
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
//END filterTable

//BEGIN filterTable2
void gestion_Achat::filterTable2(const QString &text) {
    for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tableWidget_2->setRowHidden(row, !match);
    }
}
//END filterTable2


//BEGIN detectAfficher
void gestion_Achat::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m= His_Achat::afficher_His_Achat();
    }
    else if(code==1){
        m->setQuery("select e.nom as evenement,id_o as reference_Oeuvre,p.nom as participant,TO_CHAR(date_achat, 'YYYY-MM-DD' ) as date_achat,prix from his_achat h,participant p,evenement e where e.ide=h.id_e and p.cin=h.id_p order by date_achat;");
    }
    else if(code==2){
        m->setQuery("select e.nom as evenement,id_o as reference_Oeuvre,p.nom as participant,TO_CHAR(date_achat, 'YYYY-MM-DD' ) as date_achat,prix from his_achat h,participant p,evenement e where e.ide=h.id_e and p.cin=h.id_p order by date_achat desc;");
    }
    else if(code==3){
        m->setQuery("select e.nom as evenement,id_o as reference_Oeuvre,p.nom as participant,TO_CHAR(date_achat, 'YYYY-MM-DD' ) as date_achat,prix from his_achat h,participant p,evenement e where e.ide=h.id_e and p.cin=h.id_p order by h.prix;");
    }
    else if(code==4){
        m->setQuery("select e.nom as evenement,id_o as reference_Oeuvre,p.nom as participant,TO_CHAR(date_achat, 'YYYY-MM-DD' ) as date_achat,prix from his_achat h,participant p,evenement e where e.ide=h.id_e and p.cin=h.id_p order by h.prix desc;");
    }
    afficher_His_Achat(m);
}
//END detectAfficher

//BEGIN detectAfficher2
void gestion_Achat::detectAfficher2(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m= Participation::afficher();
    }
    else if(code==1){
        m->setQuery("select * from participation order by id_p;");
    }
    else if(code==2){
        m->setQuery("select * from participation order by id_p desc;");
    }
    else if(code==3){
        m->setQuery("select * from participation order by id_e;");
    }
    else if(code==4){
        m->setQuery("select * from participation order by id_e desc;");
    }
    Afficher2(m);
}
//END detectAfficher2

//BEGIN downloadPDF
void gestion_Achat::downloadPDF() {

    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    QPainter painter(&pdfWriter);

    painter.drawText(1, 100, "Historique d'Achats: ");

    int numRows = ui->tableW->rowCount();
    int numCols = ui->tableW->columnCount();
    int y = 200;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QTableWidgetItem *item = ui->tableW->item(row, col);
            if (item) {
                QString text = item->text();

                painter.drawText( col * 1000, y*(row+3), text);


            }
        }
    }
    painter.end();
    QMessageBox::information(this, "PDF Downloaded", "PDF has been downloaded successfully.");
}
//END downloadPDF

//BEGIN downloadPDF2
void gestion_Achat::downloadPDF2() {

    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    QPainter painter(&pdfWriter);

    painter.drawText(1, 100, "Participation : ");

    int numRows = ui->tableWidget_2->rowCount();
    int numCols = ui->tableWidget_2->columnCount();
    int y = 200;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
            if (item) {
                QString text = item->text();

                painter.drawText( col * 1000, y*(row+3), text);


            }
        }
    }
    painter.end();
    QMessageBox::information(this, "PDF Downloaded", "PDF has been downloaded successfully.");
}
//END downloadPDF2


void gestion_Achat::init_participation(){
    QSqlQueryModel* model1 = new QSqlQueryModel();
    QSqlQueryModel* model2 = new QSqlQueryModel();
    model1->setQuery("select ide, nom, lieu, capacite from evenement where datefin > sysdate;");
    for (int i = 0; i < model1->rowCount(); ++i) {
            QString eventName = model1->data(model1->index(i, 1), Qt::DisplayRole).toString();
            QString lieu = model1->data(model1->index(i, 2), Qt::DisplayRole).toString();
            int capacite = model1->data(model1->index(i, 3), Qt::DisplayRole).toInt(); // Obtenir la capacité totale de l'événement
            int nombreParticipants = getNombreParticipants(model1->data(model1->index(i, 0), Qt::DisplayRole).toInt()); // Obtenir le nombre de participants inscrits
            int capaciteReelle = capacite - nombreParticipants;
            qDebug()<<"capacite:"<<capaciteReelle;// Calculer la capacité réelle disponible
            if (capaciteReelle > 0) { // Vérifier si la capacité réelle est supérieure à zéro
                QString eventInfo = eventName + " - " + lieu + " Capacité: " + QString::number(capaciteReelle); // Afficher la capacité réelle
                QVariant eventId = model1->data(model1->index(i, 0), Qt::DisplayRole);
                ui->Evenement_2->addItem(eventInfo, eventId);
            }
        }

    model2->setQuery("select cin,nom,prenom from participant;");
    for (int i = 0; i < model2->rowCount(); ++i) {
        QString cin = model2->data(model2->index(i, 0), Qt::DisplayRole).toString();
        QString prenom = model2->data(model2->index(i, 1), Qt::DisplayRole).toString();
        QString nom = model2->data(model2->index(i, 2), Qt::DisplayRole).toString();
        QString participantInfo = prenom + " " + nom + " - " + cin; // Concatenate prénom, nom et cin
        QVariant participantId = model2->data(model2->index(i, 0), Qt::DisplayRole);
        ui->Participant_2->addItem(participantInfo, participantId);
    }
}



void gestion_Achat::on_ajouter_participation_clicked()
{
    QVariant selectedParticipantId = ui->Participant_2->currentData(Qt::UserRole);
    int selectedParticipantIdValue = selectedParticipantId.toInt();

    QVariant selectEevenementId = ui->Evenement_2->currentData(Qt::UserRole);
    int selectEevenementIdValue = selectEevenementId.toInt();

    Participation P(selectEevenementIdValue,selectedParticipantIdValue);
    if(!P.existance_p(selectEevenementIdValue,selectedParticipantIdValue)){
        P.ajouter_Participation();
        sendConfirmationEmail(selectedParticipantIdValue,selectEevenementIdValue);
        detectAfficher2(0);
        ui->Participant_2->clear();
        ui->Evenement_2->clear();
        init_participation();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Participant deja affectee a ce evenement"));
    }

}
int gestion_Achat::getNombreParticipants(int eventId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM participation WHERE id_e = :eventId;");
    query.bindValue(":eventId", eventId);
    query.exec();
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
void gestion_Achat::supprimer()
{
    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;

    int id_p = senderButton->objectName().toInt(); // Retrieve id_e from object name

    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                     "Êtes-vous sûr de vouloir supprimer cette participation ?",
                                                                     QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::Yes) {
        bool success = Participation::supprimer(id_p);
        if (success) {
            QMessageBox::information(this, "Succès", "Participation supprimée avec succès.");
            detectAfficher2(0);
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de supprimer la participation.");
        }
    }
}


void gestion_Achat::Annuler()
{
    ui->Participant->setCurrentIndex(0);
    ui->Evenement->setCurrentIndex(0);
    ui->Oeuvre->setCurrentIndex(0);
}

void gestion_Achat::Annuler2()
{
    ui->Participant_2->setCurrentIndex(0);
    ui->Evenement_2->setCurrentIndex(0);
}

void gestion_Achat::Afficher2(QSqlQueryModel* model)
{
    ui->tableWidget_2->setRowCount(model->rowCount());
    ui->tableWidget_2->setColumnCount(model->columnCount());
    QStringList headers;
    for(int i=0;i<model->columnCount()-1;i++)
    {
        headers<<model->headerData(i,Qt::Horizontal).toString();
    }
    headers<<"SUPPRIMER"<<"SUPPRIMER";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    for(int row=0;row<model->rowCount();row++)
    {
        for(int column=0;column<model->columnCount()-1;column++)
        {
            if(column==1)
            {
                QSqlQuery query;
                query.prepare("SELECT nom FROM EVENEMENT WHERE IDE=:ID");
                query.bindValue(":ID",model->data(model->index(row,column)).toString());
                query.exec();
                if(query.next())
                {
                    QTableWidgetItem *headerItem = new QTableWidgetItem("Evenement");
                    QTableWidgetItem *headerItem1 = new QTableWidgetItem("CIN");
                    ui->tableWidget_2->setHorizontalHeaderItem(column, headerItem);
                    ui->tableWidget_2->setHorizontalHeaderItem(column-1, headerItem1);
                    QTableWidgetItem *item=new QTableWidgetItem(query.value(0).toString());
                    ui->tableWidget_2->setItem(row,column,item);
                }
            }
            else
            {
            QTableWidgetItem *item=new QTableWidgetItem(model->data(model->index(row,column)).toString());
            ui->tableWidget_2->setItem(row,column,item);
            }


        }
        QPushButton *deleteButton = new QPushButton("Supprimer", ui->tableWidget_2);
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
              ui->tableWidget_2->setCellWidget(row, model->columnCount()-1, deleteButton);
              connect(deleteButton, &QPushButton::clicked, this, &gestion_Achat::supprimer);
              int id_Part = model->data(model->index(row, 2)).toInt();
              deleteButton->setObjectName(QString::number(id_Part));
                QLayout *existingLayout = layout();
                if (existingLayout) {

                    QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
                    if (verticalLayout) {
                        verticalLayout->addWidget(ui->tableWidget_2);
                    }
                }
}
}

void gestion_Achat::sendConfirmationEmail(int id_p,int id_e)
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


void gestion_Achat::arduino() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer]() {
        timer->stop();
        QString data = A.read_from_arduino();
        if (!data.isEmpty()) {
            QMessageBox::information(this, tr("vérification"), tr("information envoyé : %1").arg(data));
            qDebug() << data;
            data = data.replace("\r\n","");
            bool isValidCode = verifyCode(data);
            if (isValidCode) {
                QString dataToSend = nomParticipant + ";" + nomEvenement;
                A.write_to_arduino(dataToSend.toUtf8());

            } else {
                A.write_to_arduino("aucune_participation");
            }
        }
    });
    const int timerInterval = 1000;
    timer->start(timerInterval);
}

//verification de code cin //

bool gestion_Achat::verifyCode(const QString &code) {
    bool test = false;
    QSqlQuery queryParticipant;
    QSqlQuery queryEvent;
    queryParticipant.prepare("SELECT NOM FROM PARTICIPANT WHERE CIN = (SELECT ID_P FROM PARTICIPATION WHERE ID_P = :code)");
    queryParticipant.bindValue(":code", code);
    if (queryParticipant.exec()) {
        if (queryParticipant.next()) {
            nomParticipant = queryParticipant.value(0).toString();
            qDebug() << "participant : " << nomParticipant;
            test = true;
        } else {
            qDebug() << "Aucun participant trouvé pour le code : " << code;
            test = false;
        }
    } else {
        test = false;
        return test;
    }
    queryEvent.prepare("SELECT NOM FROM EVENEMENT WHERE IDE = (SELECT ID_E FROM PARTICIPATION WHERE ID_P = :CODE)");
    queryEvent.bindValue(":CODE", code);
    if (queryEvent.exec()) {
        if (queryEvent.next()) {
            nomEvenement = queryEvent.value(0).toString();
            qDebug() << "Nomevent : " << nomEvenement;
            test = true;
        } else {
            qDebug() << "Aucun événement trouvé pour le code : " << code;
            test = false;
        }
    } else {
        test = false;
        return test;
    }
    return test;
}

