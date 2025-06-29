#include "gestion_personnel.h"
#include "forgetp.h"
#include "ui_gestion_personnel.h"

//BEGIN CONSTRUCTOR
Gestion_Personnel::Gestion_Personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_Personnel),
    alternate(false)
{
    ui->setupUi(this);

    //BEGIN Arduino
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    //END Arduino

    //BEGIN ONLY DIGITS
    QRegExpValidator *validatorNum = new QRegExpValidator(QRegExp("[0-9]*"));
    ui->CIN->setValidator(validatorNum);
    ui->salaire->setValidator(validatorNum);
    ui->numtel->setValidator(validatorNum);
    //END ONLY DIGITS

    //BEGIN ONLY LETTERS
    QRegExpValidator *validatorLet = new QRegExpValidator(QRegExp("[A-Za-z]*"));
    ui->nom->setValidator(validatorLet);
    ui->prenom->setValidator(validatorLet);
    //END ONLY LETTERS

    //BEGIN ONLY LETTERS AND DIGITS
    QRegExpValidator *validatorLetNum = new QRegExpValidator(QRegExp("[A-Za-z0-9]*"));
    ui->adresse->setValidator(validatorLetNum);
    //END ONLY LETTERS AND DIGITS

    //BEGIN affichage par defaut
    detectAfficher(0);
    //END affichage par defaut

    //BEGIN filterTable
    connect(ui->search, &QLineEdit::textChanged, this, &Gestion_Personnel::filterTable);
    //END filterTable

    //BEGIN trier
    connect(ui->triCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int newIndex) {
        ui->triCombo->setCurrentIndex(0);
        if(newIndex == 1){
            if(ui->asc->isChecked()){ 
                detectAfficher(5);
            }
            else if(ui->desc->isChecked()){
                detectAfficher(6);
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
                detectAfficher(1);
            }
            else if(ui->desc->isChecked()){
                detectAfficher(2);
            }
        }


    });
    //END trier


    //BEGIN menu
    connect(ui->menu, &QPushButton::clicked, this, [this]() {
        Menu* w = new Menu();
        w->show();
        this->close();
        delete(this);
    });
    //END menu

    //BEGIN ajouter
    connect(ui->ajouter, &QPushButton::clicked, this, &Gestion_Personnel::ajouterPersonnel);
    //END ajouter

    //BEGIN Annuler
    connect(ui->Annuler, &QPushButton::clicked, this, &Gestion_Personnel::clearForm);
    //END Annuler

    //BEGIN QrCode
    connect(ui->qrCode, &QPushButton::clicked, this, &Gestion_Personnel::GenererCodeQR);
    //END QrCode

    //BEGIN statON
    connect(ui->stat, &QPushButton::clicked, this, &Gestion_Personnel::statisticON);
    //END statON

    //BEGIN statOFF
    connect(ui->statOFF, &QPushButton::clicked, this, &Gestion_Personnel::statisticOFF);
    //END statOFF

    //BEGIN historique
    connect(ui->historique, &QPushButton::clicked, this, &Gestion_Personnel::historique);
    //END historique

    //BEGIN historiqueOff
    connect(ui->CloseH, &QPushButton::clicked, this, &Gestion_Personnel::historiqueOff);
    //END historiqueOff


    //BEGIN DownloadPDF
    connect(ui->downloadPDF, &QPushButton::clicked, this, &Gestion_Personnel::downloadPDF);
    //END DownloadPDF

    //BEGIN scan_CIN
    connect(ui->scan_CIN, &QPushButton::clicked, this, &Gestion_Personnel::scan_CIN);
    //END scan_CIN

    //BEGIN scan_Face
    connect(ui->scan_Face, &QPushButton::clicked, this, &Gestion_Personnel::scan_Face);
    //END scan_Face

    //BEGIN darkMode
    connect(ui->onDark1, &QPushButton::clicked, this, &Gestion_Personnel::switcher);
    //END darkMode

    //BEGIN Add_Finger
    connect(ui->Add_Finger, &QPushButton::clicked, this, &Gestion_Personnel::Show_FingerData);
    //END Add_Finger

    //BEGIN CloseAdF
    connect(ui->CloseAdF, &QPushButton::clicked, this, &Gestion_Personnel::Close_Add_Finger);
    //END CloseAdF

    QObject::connect(A.getserial(), &QIODevice::readyRead, this, [this]() {
        QTimer::singleShot(1500, this, &Gestion_Personnel::Get_data); // Adjust the delay (in milliseconds) as needed
    });


    // BEGIN refresh
    connect(ui->refresh, &QPushButton::clicked, this, [&](){
        detectAfficher(0);
    });
    // END refresh

    //BEGIN valideCIN
    connect(ui->CIN, &QLineEdit::textChanged, this, [this]() {
        if(!valideCIN(ui->CIN->text())){
            showError(ui->CIN);
        }
        else {
            hideError(ui->CIN);
        }
    });
    //END valideCIN

    //BEGIN valideNom
    connect(ui->nom, &QLineEdit::textChanged, this, [this]() {
        if(ui->nom->text().isEmpty() || ui->nom->text().length()<3 ){
            showError(ui->nom);
        }
        else {
            hideError(ui->nom);
        }
    });
    //END valideNom

    //BEGIN validePreNom
    connect(ui->prenom, &QLineEdit::textChanged, this, [this]() {
        if(ui->prenom->text().isEmpty() || ui->prenom->text().length()<3 ){
            showError(ui->prenom);
        }
        else {
            hideError(ui->prenom);
        }
    });
    //END validePreNom

    //BEGIN valideDateNaiss
    connect(ui->age, &QDateEdit::dateChanged, this, [this]() {
        if(!valideDateNaiss(ui->age->date())){
            ui->age->setStyleSheet(
                "QDateEdit {"
                "    padding: 5px;"
                "    border: 2px solid red;"
                "    border-radius: 5px;"
                "    font-size: 14px;"
                "    color: #333;"
                "}"
                "QDateEdit::drop-down {"
                "    subcontrol-origin: padding;"
                "    subcontrol-position: top right;"
                "    width: 20px;"
                "    border-left: 2px solid #3498db;"
                "}"
            );
        }
        else {
            ui->age->setStyleSheet(
                "QDateEdit {"
                "    padding: 5px;"
                "    border: 2px solid #43aff7;"
                "    border-radius: 5px;"
                "    font-size: 14px;"
                "    color: #333;"
                "}"
                "QDateEdit::drop-down {"
                "    subcontrol-origin: padding;"
                "    subcontrol-position: top right;"
                "    width: 20px;"
                "    border-left: 2px solid #3498db;"
                "}"
                "QDateEdit:focus {"
                "    border-color: #2ecc71;" // Color of the border when it is focused
                "}"
            );
        }
    });
    //END valideDateNaiss

    //BEGIN valideEmail
    connect(ui->email, &QLineEdit::textChanged, this, [this]() {
        if(!valideEmail(ui->email->text())){
            showError(ui->email);
        }
        else {
            hideError(ui->email);
        }
    });
    //END valideEmail

    //BEGIN valideNumTel
    connect(ui->numtel, &QLineEdit::textChanged, this, [this]() {
        if(!valideTEL(ui->numtel->text())){
            showError(ui->numtel);
        }
        else {
            hideError(ui->numtel);
        }
    });
    //END valideNumTel

    //BEGIN valideAdesse
    connect(ui->adresse, &QLineEdit::textChanged, this, [this]() {
        if(ui->adresse->text().isEmpty() || ui->adresse->text().length()<3 ){
            showError(ui->adresse);
        }
        else {
            hideError(ui->adresse);
        }
    });
    //END valideAdesse

    //BEGIN valideSalaire
    connect(ui->salaire, &QLineEdit::textChanged, this, [this]() {
        if(!valideSalaire(ui->salaire->text())){
            showError(ui->salaire);
        }
        else {
            hideError(ui->salaire);
        }
    });
    //END valideSalaire

    /*
    //BEGIN valideMdp
    connect(ui->mdp, &QLineEdit::textChanged, this, [this]() {
        if(!valideMdp(ui->mdp->text())){
            showError(ui->mdp);
        }
        else {
            hideError(ui->mdp);
        }
    });
    //END valideMdp
    */

    //BEGIN logout
    connect(ui->logout, &QPushButton::clicked, this, &Gestion_Personnel::logout);
    //END logout

    //BEGIN Modifier_Employee
        connect(ui->tableW, &QTableWidget::itemChanged, [=](QTableWidgetItem *item){
            int modifiedRow = item->row();
            int modifiedColumn = item->column();
            QTableWidgetItem *headerItem = ui->tableW->horizontalHeaderItem(modifiedColumn);
            QString columnHeader = headerItem->text();
            QWidget *widget = ui->tableW->cellWidget(modifiedRow, 11);
            QPushButton *button = qobject_cast<QPushButton*>(widget);
            employee E;
            if(ui->OnOffModification->isChecked()){
                if(E.Modifier_Employee(item,columnHeader,button->objectName().toInt())){
                    QMessageBox::information(this, "Succès", "Employé MODIFIE avec succès.");
                    historique();
                }
                else{
                    QMessageBox::critical(this, "Erreur", "Erreur.");
                }
                ui->OnOffModification->setCheckState(Qt::Unchecked);
            }
        });
    //END Modifier_Employee

    //BEGIN Tasks
        connect(ui->chat, &QPushButton::clicked, this, &Gestion_Personnel::tasks);
    //END Tasks

}
//END CONSTRUCTOR

//BEGIN DESTRUCTOR
Gestion_Personnel::~Gestion_Personnel()
{
    delete ui;
}
//END DESTRUCTOR

//BEGIN LOGOUT
void Gestion_Personnel::logout(){
    A.close_arduino();
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
    delete(this);
}
//END LOGOUT

//BEGIN filterTable
void Gestion_Personnel::filterTable(const QString &text) {
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

//BEGIN detectAfficher
void Gestion_Personnel::detectAfficher(int code){
    QSqlQueryModel* m = new QSqlQueryModel();
    if(code==0){
        m=employee::afficher_Employees();
    }
    else if(code==1){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by salaire;");
    }
    else if(code==2){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by salaire desc;");
    }
    else if(code==3){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by datenaiss ;");
    }
    else if(code==4){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by datenaiss desc;");
    }
    else if(code==5){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by nom ;");
    }
    else if(code==6){
        m->setQuery("SELECT id_emp,CIN,nom, prenom,TO_CHAR(datenaiss, 'YYYY-MM-DD' ) as datenaiss,TO_CHAR(dateEmb, 'YYYY-MM-DD' ) as dateEmb,email,sexe, adresse, numtel, salaire,Role FROM employee order by nom desc;");
    }
    afficherPersonnels(m);
    delete(m);
}
//END detectAfficher

//BEGIN afficherPersonnels
void Gestion_Personnel::afficherPersonnels(QSqlQueryModel* m){
    ui->tableW->setRowCount(m->rowCount());
    ui->tableW->setColumnCount(m->columnCount());
    QStringList headers;
    for (int col = 1; col < m->columnCount(); ++col) {
        headers << m->headerData(col, Qt::Horizontal).toString();
    }
    headers << "Action1" << "Action2";
    ui->tableW->setHorizontalHeaderLabels(headers);
    for (int row = 0; row < m->rowCount(); ++row) {
        for (int col = 1; col < m->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(m->data(m->index(row, col)).toString());
            ui->tableW->setItem(row, col-1, item);
        }

        QPushButton *deleteButton = new QPushButton("supprimer", ui->tableW);
        deleteButton->setStyleSheet("QPushButton {\
                                        padding: 5px;\
                                        font-size: 16px;\
                                        text-align: center;\
                                        text-decoration: none;\
                                        border: 2px solid #792382;\
                                        color: #43aff7;\
                                        border-radius: 5px;\
                                        background-image: url('images/trash.svg');\
                                        background-repeat: no-repeat;\
                                        background-position: left center;\
                                        padding-left: 30px; \
                                    }\
                                    QPushButton:hover {\
                                        background-color: #792382;\
                                    }");
        ui->tableW->setCellWidget(row, m->columnCount()-1, deleteButton);
        connect(deleteButton, &QPushButton::clicked, this, &Gestion_Personnel::DeleteEmployee);
        int employeeId = m->data(m->index(row, 0)).toInt();
        deleteButton->setObjectName(QString::number(employeeId));

    }

    QLayout *existingLayout = layout();
    if (existingLayout) {

        QVBoxLayout *verticalLayout = qobject_cast<QVBoxLayout*>(existingLayout);
        if (verticalLayout) {
            verticalLayout->addWidget(ui->tableW);
        }
    }
}
//END afficherPersonnels

//BEGIN DeleteEmployee
void Gestion_Personnel::DeleteEmployee()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton)
        return;
    int idEmp = senderButton->objectName().toInt();
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation",
                                                                             "Êtes-vous sûr de vouloir supprimer cet employé ?",
                                                                             QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::Yes) {

        QString queryText = "select fingerid from employee WHERE id_emp = :id";
        QSqlQuery query1;
        query1.prepare(queryText);
        query1.bindValue(":id", idEmp);
        query1.exec();
        query1.next();
        QString id = query1.value(0).toString();

        if(id != 0){
            ui->t->setPlainText("");
            QByteArray commandData = "DDelete";
            QByteArray idData = (commandData+","+id).toUtf8();
            A.write_to_arduino(idData);
        }

        employee e;
        bool success = e.Effacer_Employee(idEmp);
        if (success) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
            detectAfficher(0);
            historique();
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'employé.");
        }
    }
}
//END DeleteEmployee

//BEGIN ajouterPersonnel
void Gestion_Personnel::ajouterPersonnel(){
    QString CIN=ui->CIN->text();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    QString adresse = ui->adresse->text();
    QString sexe = "";
    if(ui->H->isChecked()) {
        sexe = "H";
    } else if(ui->F->isChecked()) {
        sexe = "F";
    }

    QString Role = ui->Role->currentText();
    forgetP F;
    QString mdp = F.generateVerificationCode();
    int num_tel = ui->numtel->text().toInt();
    QDate age = ui->age->date();
    float salaire = ui->salaire->text().toFloat();

    if(!valideCIN(CIN) ||
       !valideTEL(ui->numtel->text()) ||
       !valideEmail(email) ||
       !valideDateNaiss(age) ||
       !valideSalaire(ui->salaire->text())||
       ui->nom->text().isEmpty() || ui->nom->text().length()<3 ||
       ui->prenom->text().isEmpty() || ui->prenom->text().length()<3 ||
       ui->adresse->text().isEmpty() || ui->adresse->text().length()<3
      )
    {
        QMessageBox::critical(this, "Erreur", "Il y a des champs non valides!");
        return;
     }

    if(ui->Role->currentText().isEmpty()){
        ui->Role->setStyleSheet(
            "padding: 5px;"
            "border: 2px solid red;"
            "border-radius: 5px;"
            "font-size: 14px;"
            "color: #333;"
        );
        return;
    }
    else{
        ui->Role->setStyleSheet(
            "padding: 5px;"
            "border: 2px solid #43aff7;"
            "border-radius: 5px;"
            "font-size: 14px;"
            "color: #333;"
        );
    }

    employee E(0, nom, prenom, age, email, Role, num_tel, adresse, sexe, mdp, salaire,CIN,age);
    if(E.Existance_Employee(email) || E.Existance_Employee_CIN(CIN)){
        QMessageBox::critical(nullptr, QObject::tr("system"),QObject::tr("Employee Exist.\n"));
    }
    else{
        bool test = E.Ajouter_Employee();

        if (test) {
            QStringList arguments;
            arguments << "C:\\Users\\bechi\\Desktop\\ProjetC++\\PythonScripts\\mail2.py" <<email<<mdp;

            QProcess::startDetached("python", arguments);
            QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Employee ajoute avec succes.\n"));
            detectAfficher(0);
            historique();
        } else {
            QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Erreur.\n"));
        }
    }


    ui->CIN->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->email->clear();
    ui->numtel->clear();
    ui->salaire->clear();
    ui->adresse->clear();
    hideError(ui->CIN);
    hideError(ui->nom);
    hideError(ui->prenom);
    hideError(ui->email);
    hideError(ui->numtel);
    hideError(ui->salaire);
    hideError(ui->adresse);
    ui->Role->setStyleSheet(
        "padding: 5px;"
        "border: 2px solid #43aff7;"
        "border-radius: 5px;"
        "font-size: 14px;"
        "color: #333;"
    );
    ui->Role->setCurrentIndex(0);
    ui->CIN->setPlaceholderText("CIN");
    ui->nom->setPlaceholderText("Nom");
    ui->prenom->setPlaceholderText("Prenom");
    ui->email->setPlaceholderText("Email");
    ui->numtel->setPlaceholderText("Numero de telephone");
    ui->salaire->setPlaceholderText("Salaire");
    ui->adresse->setPlaceholderText("Adresse");

}
//END ajouterPersonnel

//BEGIN valideEmail
bool Gestion_Personnel::valideEmail(QString email) {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    QRegularExpressionMatch match = regex.match(email);

    if (match.hasMatch()) {
        return true;
    } else {
        return false;
    }
}
//END valideEmail

//BEGIN valideCIN
bool Gestion_Personnel::valideCIN(QString CIN){
    QRegularExpression regex("^[0-9]{8}$");
        if (regex.match(CIN).hasMatch()) {
            return true;
        } else {
            return false;
        }
}
//END valideCIN

//BEGIN valideTEL
bool Gestion_Personnel::valideTEL(QString tel) {

    QRegularExpression regex("^\\d{8}$");

    QRegularExpressionMatch match = regex.match(tel);

    if (match.hasMatch()) {
        return true;
    } else {
        return false;
    }
}
//END valideTEL

//BEGIN valideSalaire
bool Gestion_Personnel::valideSalaire(QString salaire) {

    bool ok;
    float salaireValue = salaire.toFloat(&ok);

    if (ok && salaireValue > 0) {
        return true;
    } else {
        return false;
    }
}
//END valideSalaire

//BEGIN valideMdp
bool Gestion_Personnel::valideMdp(QString password) {

    bool hasLowercase = false;
    bool hasNumber = false;
    bool hasSpecialChar = false;

    for (const QChar& c : password) {
        if (c.isLower()) {
            hasLowercase = true;
        } else if (c.isDigit()) {
            hasNumber = true;
        } else if (!c.isLetterOrNumber()) {
            hasSpecialChar = true;
        }
    }

    if (password.length() >= 8 && hasLowercase && hasNumber && hasSpecialChar) {
        return true;
    } else {
        return false;
    }
}
//END valideMdp

//BEGIN valideDateNaiss
bool Gestion_Personnel::valideDateNaiss(QDate dateNaiss) {

    QDate currentDate = QDate::currentDate();

    int age = dateNaiss.daysTo(currentDate) / 365;

    if (age >= 18 && age <= 100) {
        return true;
    } else {
        return false;
    }
}
//END valideDateNaiss

//BEGIN valideDate
bool Gestion_Personnel::valideDate(QDate DateEmb) {
    if (!DateEmb.isValid()) {
        return false;
        }
    return true;
}
//END valideDate

//BEGIN showError
void Gestion_Personnel::showError(QLineEdit* EditLine){
    QString styleSheet = "QLineEdit {"
                                         "    padding: 5px;"
                                         "    border: 2px solid red;"
                                         "    border-radius: 5px;"
                                         "    font-size: 14px;"
                                         "    color: #333;"
                                         "}"
                                         "QLineEdit::placeholder {"
                                         "    color: red;"
                                         "}";
    EditLine->setStyleSheet(styleSheet);
    EditLine->setPlaceholderText("non valide!");
    EditLine->setFocus();
}
//END showError

//BEGIN hideError
void Gestion_Personnel::hideError(QLineEdit* EditLine){
    EditLine->setStyleSheet("QLineEdit {"
                                            "padding: 5px;"
                                            "    border: 2px solid #43aff7;"
                                            "    border-radius: 5px;"
                                            "    font-size: 14px;"
                                            "    color: #333;"
                                            "}");
    EditLine->setPlaceholderText(EditLine->objectName());
}
//END hideError



//BEGIN downloadPDF
void Gestion_Personnel::downloadPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&pdfWriter);
    QString path="D:\\ESPRIT\\c++\\Projet\\ProjetC++\\images\\back2.png";
    if(alternate){
        path="D:\\ESPRIT\\c++\\Projet\\ProjetC++\\images\\backDark.png";
    }
    QImage originalImage(path);
    QSize maxSize(2000, 2000);
    QImage resizedImage = originalImage.scaled(maxSize, Qt::KeepAspectRatio);

    if (resizedImage.isNull()) {
        QMessageBox::warning(this, "Warning", "Failed to load background image!");
        return;
    } else {
        qDebug() << "Image loaded successfully.";
    }
    int numHorizontalTiles = qCeil(qreal(pdfWriter.width()) / qreal(resizedImage.width()));
        int numVerticalTiles = qCeil(qreal(pdfWriter.height()) / qreal(resizedImage.height()));

        // Draw the tiles of the background image
        for (int y = 0; y < numVerticalTiles; ++y) {
            for (int x = 0; x < numHorizontalTiles; ++x) {
                int xPos = x * resizedImage.width();
                int yPos = y * resizedImage.height();
                painter.drawImage(xPos, yPos, resizedImage);
            }
        }
    QImage logo("D:\\ESPRIT\\c++\\Projet\\ProjetC++\\images\\logo.png"); // Load logo image from resources or file system
    QRect logoRect(7900, 0, 1000, 1000); // Adjust position and size of logo
    painter.drawImage(logoRect, logo);

    QPen pen(Qt::black);
    QPen pen2(Qt::white);
    if(alternate){
        painter.setPen(pen2);
    }
    else{
        painter.setPen(pen);
    }

    painter.drawText(1, 1800, "Détails des Employees : ");

    const int tableLeft = 50;
    const int tableTop = 2000;
    const int cellWidth = 1500;
    const int cellHeight = 500;
    int numRows = ui->tableW->rowCount();
    int numCols = ui->tableW->columnCount();
    pen.setWidth(2);

    QStringList headers;
    painter.setPen(pen2);
    headers << "CIN" << "Nom" << "Prenom" << "Email" << "Salaire" << "Role";

    int rows=0;
    for (int row = 0; row < numRows; ++row) {

        if(!ui->tableW->isRowHidden(row)){
            rows++;
        }


    }
    if(alternate){
        painter.fillRect(tableLeft, tableTop, headers.size() * cellWidth, (rows+1) * cellHeight, Qt::black);
    }
    else {
        painter.fillRect(tableLeft, tableTop, headers.size() * cellWidth, (rows+1) * cellHeight, Qt::magenta);
    }


    for (int i = 0; i < headers.size(); ++i) {
        QRect cellRect(tableLeft + i * cellWidth, tableTop, cellWidth, cellHeight);
        painter.drawText(cellRect, Qt::AlignCenter, headers[i]);
        painter.drawRect(cellRect); // Draw border around each header cell
    }
    int skipedCols=0;
    int skipedRows=0;
    for (int row = 0; row < numRows; ++row) {
        if(ui->tableW->isRowHidden(row)) {
            skipedRows++;
            continue; // Skip these columns
        }
        for (int col = 0; col < numCols; ++col) {
            // Skip columns 3, 4, 6, 7, and 8
            if(col == 3 || col == 4 || col == 6 || col == 7 || col == 8) {
                skipedCols++;
                continue; // Skip these columns
            }
            QTableWidgetItem *item;
            item = ui->tableW->item(row, col);
            if (item) {
                QRect cellRect(tableLeft + (col-skipedCols) * cellWidth, tableTop + ((row-skipedRows) + 1) * cellHeight, cellWidth, cellHeight);
                painter.drawText(cellRect, Qt::AlignCenter, item->text());
                painter.drawRect(cellRect); // Draw border around each data cell
            }
        }
        skipedCols=0;
    }

    painter.end();
    QMessageBox::information(this, "PDF Downloaded", "PDF has been downloaded successfully.");
}
//END downloadPDF

//BEGIN statistic
void Gestion_Personnel::statistic() {

    QSqlQueryModel* model = employee::afficher_Employees();

    if (!model) {
        qDebug() << "Error: Failed to retrieve employee data.";
        return;
    }

    int rowCount = model->rowCount();

    int H = 0, F = 0, GP = 0, GPA = 0, GE = 0, GO = 0, GC = 0, E = 0;
    for (int i = 0; i < rowCount; ++i) {
        if (model->data(model->index(i, 7)).toString() == "H") {
            H++;
        } else if (model->data(model->index(i, 7)).toString() == "F") {
            F++;
        }

        if (model->data(model->index(i, 11)).toString() == "Employee") {
            E++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Personnels") {
            GP++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Oeuvres") {
            GO++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Participants") {
            GPA++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Charites") {
            GC++;
        } else {
            GE++;
        }
    }

    float PF = (F * 100.0) / rowCount;
    float PH = (H * 100.0) / rowCount;
    float PE = (E * 100.0) / rowCount;
    float PGP = (GP * 100.0) / rowCount;
    float PGO = (GO * 100.0) / rowCount;
    float PGPA = (GPA * 100.0) / rowCount;
    float PGC = (GC * 100.0) / rowCount;
    float PGE = (GE * 100.0) / rowCount;

    // Create a bar series
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    QtCharts::QBarSet *roleSet = new QtCharts::QBarSet("Role");
    *roleSet << PF << PH << PE << PGP << PGO << PGPA << PGC << PGE;
    series->append(roleSet);

    // Create a chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Statistics");

    // Create a category axis and set labels
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append("Female");
    axis->append("Male");
    axis->append("Employee");
    axis->append("Gestion_Personnels");
    axis->append("Gestion_Oeuvres");
    axis->append("Gestion_Participants");
    axis->append("Gestion_Charites");
    axis->append("Gestion_Evenements");

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
void Gestion_Personnel::statisticON() {
    ui->widget->show(); // Show the statistics widget
    ui->statOFF->show(); // Show the button to turn off statistics
    statistic(); // Refresh the statistics data
}
//END statisticON

//BEGIN statisticOFF
void Gestion_Personnel::statisticOFF() {
    ui->widget->hide();
    ui->statOFF->hide();
}
//END statisticOFF

//BEGIN updateStatistic
void Gestion_Personnel::updateStatistic() {
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

    QSqlQueryModel* model = employee::afficher_Employees();

    if (!model) {
        qDebug() << "Error: Failed to retrieve employee data.";
        return;
    }

    int rowCount = model->rowCount();

    int H = 0, F = 0, GP = 0, GPA = 0, GE = 0, GO = 0, GC = 0, E = 0;
    for (int i = 0; i < rowCount; ++i) {
        if (model->data(model->index(i, 7)).toString() == "H") {
            H++;
        } else if (model->data(model->index(i, 7)).toString() == "F") {
            F++;
        }

        if (model->data(model->index(i, 11)).toString() == "Employee") {
            E++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Personnels") {
            GP++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Oeuvres") {
            GO++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Participants") {
            GPA++;
        } else if (model->data(model->index(i, 11)).toString() == "Gestion_Charites") {
            GC++;
        } else {
            GE++;
        }
    }

    float PF = (F * 100.0) / rowCount;
    float PH = (H * 100.0) / rowCount;
    float PE = (E * 100.0) / rowCount;
    float PGP = (GP * 100.0) / rowCount;
    float PGO = (GO * 100.0) / rowCount;
    float PGPA = (GPA * 100.0) / rowCount;
    float PGC = (GC * 100.0) / rowCount;
    float PGE = (GE * 100.0) / rowCount;

    // Create a bar series
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

    QtCharts::QBarSet *roleSet = new QtCharts::QBarSet("Role");
    *roleSet << PF << PH << PE << PGP << PGO << PGPA << PGC << PGE;
    series->append(roleSet);

    // Create a chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Statistics");

    // Create a category axis and set labels
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append("Female");
    axis->append("Male");
    axis->append("Employee");
    axis->append("Gestion_Personnels");
    axis->append("Gestion_Oeuvres");
    axis->append("Gestion_Participants");
    axis->append("Gestion_Charites");
    axis->append("Gestion_Evenements");

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

//BEGIN assistance
void Gestion_Personnel::assistance() {
    QString activationScript = "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\Python312\\myenv312\\Scripts\\activate";

    // Path to the Python interpreter
    QString pythonInterpreter = "python";

    // Path to your Python script
    QString pythonScript = "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\Python312\\speechRecognition.py";

    // Command to activate the virtual environment and run the Python script
    QString command = QString("cmd /c \"%1 && %2 %3\"").arg(activationScript).arg(pythonInterpreter).arg(pythonScript);

    // Create a QProcess instance
    QProcess process;

    // Start the process with the command
    process.start(command);

    // Wait for the process to finish
    process.waitForFinished();

    // Read the output if needed
    QString result = process.readAllStandardOutput();

    Gestion_Personnel g;
    QTextToSpeech *tts = new QTextToSpeech(this);
    QString employeeID;



    QRegularExpression idRegex("\\b\\d+\\b"); // Matches a sequence of digits

    QStringList words = result.split(" ");
    QString text = result.replace(" ","");
    text=text.replace(",","");
    text=text.replace("$","");
    //QStringList words1 = result.split(" ", QString::SkipEmptyParts);

    if(result.contains("exit")){
        QTextToSpeech *tts = new QTextToSpeech(this);
        QString text = "Hope that i helped you ";
        tts->say(text);
    }
    else if (words.contains("delete") && words.contains("employee")) {
        for (const QString& word : words) {
               if (idRegex.match(word).hasMatch()) {
                   employeeID = word;
                   break;
               }
           }
        employee E;
        if(E.Existance_Employee_ID(employeeID.toInt())){
            if(E.Effacer_Employee(employeeID.toInt())){
                tts->say("Employee Deleted successfully");
                detectAfficher(0);
            }
            else {
                tts->say("An Error occured while deleting the Employee");
            }
        }
        else{
            tts->say("this Employee does not Exist");
        }
    }
    else if (result.indexOf("add") != -1 && result.indexOf("employee") != -1) {
        // Extracting information for adding an employee
        QString Nom, Prenom, Email, Adresse, Sexe,sex, Mdp, Role,CIN,NumTel,Salaire,age;
        QDate Age,DateEmb;
        //if (index + 14 <= words.size()) {
            // Initialize variables with extracted values
            Nom = words[words.indexOf("name") + 1];
            Prenom = words[words.lastIndexOf("name") + 1];
            int emailIndex = words.indexOf("email");
            int genderIndex = words.indexOf("gender");
            QStringList emailWords = words.mid(emailIndex + 1, genderIndex - emailIndex - 1);
                // Concatenate the words with a space between them to form the email address
                Email = emailWords.join(" ");
                // Replace placeholders in the email address
                Email.replace(" at ", "@");
                Email.replace(" dot ", ".");
                Email.replace(" ", "");
            sex=words[words.indexOf("gender") + 1][0].toUpper();
            if(sex=="M"){
                Sexe="H";
            }
            else{
                Sexe="F";
            }
            Adresse = words[words.indexOf("address")+1];
            if(text.indexOf("cin")!=-1){
                for (int i=text.indexOf("cin");i<text.length();i++){
                    if( text.at(i).isDigit() && CIN.length()<8 ){
                        CIN+=text.at(i);
                    }
                }
            }
            if(text.indexOf("phonenumber")!=-1){
                for (int i=text.indexOf("phonenumber");i<text.length();i++){
                    if( text.at(i).isDigit() && NumTel.length()<8 ){
                        NumTel+=text.at(i);
                    }
                }
            }
            if(text.indexOf("birthdate")!=-1){
                for (int i=text.indexOf("birthdate");i<text.length();i++){
                    if( (text.at(i).isDigit() || text.at(i)=="-") && NumTel.length()<10 ){
                        age+=text.at(i);
                    }
                }
            }
            age=age.replace("Dash","-");
            Age=QDate::fromString(age, "yyyy-MM-dd");
            Salaire = words[words.indexOf("salary")+1];
            employee E(0, Nom, Prenom, Age, Email, Role, NumTel.toInt(), Adresse, Sexe, Mdp, Salaire.toFloat(), CIN, DateEmb);
            if (E.Existance_Employee(Email) || E.Existance_Employee_CIN(CIN)) {
                tts->say("This employee already exists.");
            } else {
                // Attempt to add the employee
                bool success = E.Ajouter_Employee();
                if (success) {
                    tts->say("Employee added successfully.");
                    detectAfficher(0);
                } else {
                    tts->say("An error occurred while adding the employee.");
                }
            }
    }
    else if(words.contains("update")) {
        QString newValue;
        QString attribute;
        QString employeeIdIndex;

        // Check for the presence of keywords like "name", "email", etc.
        if (words.contains("name")) {
            attribute = "nom";
            newValue = words[words.indexOf("to") + 1];
        } else if (words.contains("email")) {
            attribute = "email";
            int emailIndex = words.indexOf("to") + 1;
            QStringList emailWords = words.mid(emailIndex, words.size() - emailIndex);
            newValue = emailWords.join("").replace(" ", "").replace("at", "@").replace("dot", ".");
        } else if (words.contains("address")) {
            attribute = "addresse";
            newValue = words[words.indexOf("to") + 1]; // Extract the new address
        } else if (words.contains("salary")) {
            attribute = "salaire";
            newValue = words[words.indexOf("to") + 1]; // Extract the new salary
            newValue.replace(",","");
            newValue.replace(".","");
            newValue.replace("\r","");
            newValue.replace("\n","");
        }

        for (const QString& word : words) {
            if (idRegex.match(word).hasMatch()) {
                employeeIdIndex = word;
                break;
            }
        }

        // Check if the attribute and employee ID are extracted correctly
        if (!attribute.isEmpty() && !employeeIdIndex.isEmpty()) {

            employee E;
            if (E.Existance_Employee_ID(employeeIdIndex.toInt())) {
                if (E.Modifier_Employee(employeeIdIndex.toInt(), attribute, newValue)) {
                    tts->say("Employee information updated successfully.");
                    detectAfficher(0);
                } else {
                    tts->say("An error occurred while updating employee information.");
                }
            } else {
                tts->say("Employee with ID " + employeeID + " does not exist.");
            }
        } else {
            tts->say("Insufficient information provided for updating employee.");
        }
    }

    else if(words.contains("download") ){
        ui->downloadPDF->click();
    }
    else {
        tts->say("that's an Invalid command: ");
    }
}
//END assistance

//BEGIN Tasks
void Gestion_Personnel::tasks() {

    QTextToSpeech *tts = new QTextToSpeech(this);

    QString text = "Hi, how can I assist you?";
    tts->say(text);

    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("Yes");
    comboBox->addItem("No");

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Enregistrement vocal", "Voulez-vous enregistrer votre voix ?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
       QMessageBox *recordingMessageBox = new QMessageBox(QMessageBox::Information, "Enregistrement vocal", "L'enregistrement vocal est en cours.", QMessageBox::NoButton, this);
        recordingMessageBox->show();
        assistance();
        recordingMessageBox->close();
    }
    delete(tts);

}
//END Tasks

//BEGIN scan_CIN
void Gestion_Personnel::scan_CIN(){
    QProcess process;

    QString pythonCommand = "python"; // Command to execute Python interpreter
    QStringList scriptArgs;
    scriptArgs << "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\cinScan.py";

    process.start(pythonCommand, scriptArgs);

    process.waitForFinished(-1);
    QString result = process.readAllStandardOutput();
    ui->CIN->setText(result);
    result=ui->CIN->text();
    result = result.left(result.length() - 2);
    ui->CIN->setText(result);
}
//END scan_CIN

//BEGIN scan_Face
void Gestion_Personnel::scan_Face(){
    QString role=ui->Role->currentText();
    if(!role.isEmpty()){
        QString pythonCommand = "python"; // Command to execute Python interpreter
        QStringList scriptArgs;

        scriptArgs << "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\face\\register.py"<<role;

        QProcess process;

        process.start(pythonCommand, scriptArgs);

        process.waitForFinished(-1);
    }
    else{
        QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Role est vide!!"));
    }




}
//END scan_Face

//BEGIN GenererCodeQR
void Gestion_Personnel::GenererCodeQR() {
    // Vérifier si une ligne est sélectionnée dans le tableau
    if (ui->tableW->selectionModel()->currentIndex().isValid()) {
        // Récupérer les données de la ligne sélectionnée
        QString CIN = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 0)).toString();
        QString Nom = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 1)).toString();
        QString Prenom = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 2)).toString();
        QString Email = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 5)).toString();
        QString NumTel = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 8)).toString();
        QString Role = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 10)).toString();

        // Construire le contenu du code QR avec les données récupérées
        QString qrContent = QString("CIN: %1\nNom: %2\nPrenom: %3\nEmail: %4\nNumTel: %5\nRole: %6").arg(CIN, Nom, Prenom, Email, NumTel, Role);

        // Générer le code QR avec le contenu
        const QrCode qr = QrCode::encodeText(qrContent.toStdString().c_str(), QrCode::Ecc::LOW);

        // Demander à l'utilisateur de spécifier le chemin et le nom du fichier
        QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le code QR"), QDir::homePath() + "/" + CIN + ".svg", tr("Fichiers SVG (*.svg)"));
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

//BEGIN switcher
void Gestion_Personnel::switcher(){
    if (alternate) {
            Dark_Mode_off();
    } else {

            Dark_Mode_on();
    }
    alternate = !alternate;
}
//END switcher

//BEGIN Dark_Mode_on
void Gestion_Personnel::Dark_Mode_on() {
    QString backgroundStyle = "background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/backDark.png\");";
    // Define the QPushButton styles as a QString
    QString darktoggleStyle = "QPushButton {"
                              "    background: transparent;"
                              "    background-image: url(images/toggle-right.svg);"
                              "    background-repeat: no-repeat;"
                              "}";

    QString commonButtonStyle =
        "QPushButton {"
        "    padding: 5px;"
        "    font-size: 16px;"
        "    text-align: center;"
        "    text-decoration: none;"
        "    border: 2px solid #792382;"
        "    color: white;"
        "    border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #43aff7;"
        "}";

    QString tableWidgetStyle =
        "QTableWidget {"
        "    background-color: transparent;"
        "}"
        "QTableWidget QTableCornerButton::section {"
        "    background-color: transparent;"
        "}"
        "QTableWidget QHeaderView::section {"
        "    background-color: transparent;"
        "    color: black;"
        "}"
        "QTableWidget::item {"
        "    color: white;"
        "}"
        "QTableWidget::item QPushButton {"
        "    background-color: transparent;"
        "}";


    QString labelStyle =
        "QLabel {"
        "    font-size: 22px;"
        "    color: white;"
        "    font-weight: bold;"
        "}";

    QString checkBoxStyle =
        "QCheckBox {"
        "    font-size: 22px;"
        "    color: white;"
        "    font-weight: bold;"
        "}";

    QString radioButtonStyle =
        "QRadioButton {"
        "    padding: 5px;"
        "    color: white;"
        "}";
    QString Download = "QPushButton { "
                        "    background-image: url(images/download.svg); "
                        "    background-repeat: no-repeat; "
                        "    background-position: left center; "
                        "    padding-left: 30px; "
                        "}";
    QString Logout = "QPushButton { "
                        "    background-image: url(images/log-out.svg); "
                        "    background-repeat: no-repeat; "
                        "    background-position: left center; "
                        "    padding-left: 30px; "
                        "}";
    QString Stat = "QPushButton { "
                        "    background-image: url(images/bar-chart.svg); "
                        "    background-repeat: no-repeat; "
                        "    background-position: left center; "
                        "    padding-left: 30px; "
                        "}";

        ui->Background->setStyleSheet(backgroundStyle);
        ui->stat->setStyleSheet(commonButtonStyle + Stat);
        ui->downloadPDF->setStyleSheet(commonButtonStyle + Download);
        ui->qrCode->setStyleSheet(commonButtonStyle);
        ui->menu->setStyleSheet(commonButtonStyle);
        ui->chat->setStyleSheet(commonButtonStyle);
        ui->logout->setStyleSheet(commonButtonStyle + Logout);
        ui->tableW->setStyleSheet(tableWidgetStyle);
        ui->title->setStyleSheet(labelStyle);
        ui->OnOffModification->setStyleSheet(checkBoxStyle);
        ui->H->setStyleSheet(radioButtonStyle);
        ui->F->setStyleSheet(radioButtonStyle);
        ui->Historic->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
        ui->onDark1->setStyleSheet(darktoggleStyle);
}
//END Dark_Mode_on

//BEGIN Dark_Mode_off
void Gestion_Personnel::Dark_Mode_off() {
    QString backgroundStyle = "background-image: url(\"images/back.jpg\");";
    QString darktoggleStyle =
                              "    background: transparent;"
                              "    background-image: url(images/toggle-left.svg);"
                              "    background-repeat: no-repeat;"
                              "}";
    QString commonButtonStyle1 =
        "QPushButton {"
        "    padding: 5px;"
        "    font-size: 16px;"
        "    text-align: center;"
        "    text-decoration: none;"
        "    border: 2px solid #792382;"
        "    color: white;"
        "    border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #ffffff;"
        "}";
    QString commonButtonStyle2 =
        "QPushButton {"
        "    padding: 5px;"
        "    font-size: 16px;"
        "    text-align: center;"
        "    text-decoration: none;"
        "    border: 2px solid #792382;"
        "    color: #792382;"
        "    border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #ffffff;"
        "}";

    QString labelStyle =
        "QLabel {"
        "    font-size: 22px;"
        "    color: #792382;"
        "    font-weight: bold;"
        "}";

    QString checkBoxStyle =
        "QCheckBox {"
        "    font-size: 22px;"
        "    color: #792382;"
        "    font-weight: bold;"
        "}";

    QString radioButtonStyle =
        "QRadioButton {"
        "    padding: 5px;"
        "    color: #792382;"
        "}";

    QString Download = "QPushButton { "
                        "    background-image: url(images/download.svg); "
                        "    background-repeat: no-repeat; "
                        "    background-position: left center; "
                        "    padding-left: 30px; "
                        "}"
                       "QPushButton:hover {"
                       "    background-color: #ffffff;"
                       "}";
    QString Logout = "QPushButton { "
                            "    background-image: url(images/log-out.svg); "
                            "    background-repeat: no-repeat; "
                            "    background-position: left center; "
                            "    padding-left: 30px; "
                            "}"
                             "QPushButton:hover {"
                             "    background-color: #ffffff;"
                             "}";
    QString Stat = "QPushButton { "
                        "    background-image: url(images/bar-chart.svg); "
                        "    background-repeat: no-repeat; "
                        "    background-position: left center; "
                        "    padding-left: 30px; "
                        "}"
                       "QPushButton:hover {"
                       "    background-color: #ffffff;"
                       "}";

        ui->Background->setStyleSheet(backgroundStyle);
        ui->stat->setStyleSheet(commonButtonStyle2 + Stat);
        ui->downloadPDF->setStyleSheet(commonButtonStyle2 + Download);
        ui->qrCode->setStyleSheet(commonButtonStyle2);
        ui->menu->setStyleSheet(commonButtonStyle1);
        ui->chat->setStyleSheet(commonButtonStyle1);
        ui->Historic->setStyleSheet("");
        ui->logout->setStyleSheet(commonButtonStyle1 + Logout);
        ui->title->setStyleSheet(labelStyle);
        ui->OnOffModification->setStyleSheet(checkBoxStyle);
        ui->tableW->setStyleSheet("");
        ui->H->setStyleSheet(radioButtonStyle);
        ui->F->setStyleSheet(radioButtonStyle);
        ui->onDark1->setStyleSheet(darktoggleStyle);
}
//END Dark_Mode_off

//BEGIN clearForm
void Gestion_Personnel::clearForm() {
    ui->CIN->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->numtel->clear();
    ui->email->clear();
    ui->salaire->clear();
    ui->adresse->clear();
    ui->Role->setCurrentIndex(0);
    hideError(ui->CIN);
    hideError(ui->nom);
    hideError(ui->prenom);
    hideError(ui->numtel);
    hideError(ui->email);
    hideError(ui->salaire);
    hideError(ui->adresse);
}
//END clearForm

//BEGIN historique
void Gestion_Personnel::historique()
{
    QFile file("historic.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        ui->Historic->setPlainText(content);
        file.close();
        ui->histLabel->raise();
        ui->Historic->raise();
        ui->CloseH->raise();
    }
}
//END historique

//BEGIN historiqueOff
void Gestion_Personnel::historiqueOff()
{
    ui->histLabel->lower();
    ui->Historic->lower();
    ui->CloseH->lower();
    ui->Historic->setPlainText("");
}
//END historiqueOff

//BEGIN Add_Finger
void Gestion_Personnel::Add_Finger()
{

        ui->t->setPlainText("");
        QByteArray commandData = "AAjouter";



        QString queryText = "SELECT FLOOR(DBMS_RANDOM.VALUE(1, 125)) AS random_number "
                            "FROM dual "
                            "WHERE NOT EXISTS ( "
                            "    SELECT 1 "
                            "    FROM employee "
                            "    WHERE fingerid = FLOOR(DBMS_RANDOM.VALUE(1, 125)) "
                            ") "
                            "AND ROWNUM = 1";

        QSqlQuery query;
        query.prepare(queryText);
        query.exec();
        query.next();

        QString id = query.value(0).toString(); // Convert QVariant to integer
        ui->HiddenId->setText(id);
        qDebug()<<"id: "<<id;
        QByteArray idData = (commandData+","+id).toUtf8();
        A.write_to_arduino(idData);



}
//END Add_Finger

//BEGIN Add_Finger
void Gestion_Personnel::Show_FingerData()
{
    if (ui->tableW->selectionModel()->currentIndex().isValid()) {
        QString CIN = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 0)).toString();
        //qDebug()<< CIN;
        QString queryText = "select fingerid from employee WHERE CIN = :cin";
        QSqlQuery query;
        query.prepare(queryText);
        query.bindValue(":cin", CIN);
        query.exec();
        if(query.next()){
            //qDebug()<< query.value(0);
            int idF = query.value(0).toInt();
            if (idF == 0) {
                Add_Finger(); // Ajoutez un doigt (une fonction qui n'est pas définie ici)

                QTimer *timer = new QTimer(this);
                int blinkCount = 0; // Variable to track the number of blinks
                ui->FingerL->raise();
                // Connect the timeout signal of the timer to a lambda that toggles the visibility of a widget
                QObject::connect(timer, &QTimer::timeout, [=]() mutable { // Declare the lambda as mutable
                    if (blinkCount < 6) { // Blink 3 times (on and off, so 6 toggle operations)
                        ui->FingerL->setVisible(!ui->FingerL->isVisible()); // Toggle visibility
                        blinkCount++;
                    } else {
                        // Disconnect the timer after the third blink
                        QObject::disconnect(timer, &QTimer::timeout, nullptr, nullptr);
                        timer->stop(); // Stop the timer
                        delete timer; // Delete the timer
                        ui->t->setPlainText("Put your finger!!");
                        ui->t->raise();
                        ui->CloseAdF->raise();
                    }
                });

                // Start the timer with an interval of 500 ms
                int interval = 500; // Interval of the timer in milliseconds
                timer->start(interval);


            }


            else{
                QMessageBox::warning(this, tr("Avertissement"), tr("Empreinte deja affectee ! "));
            }
        }

    } else {
        QMessageBox::warning(this, tr("Avertissement"), tr("Veuillez sélectionner une ligne dans le tableau."));
    }
}
//END Add_Finger

//BEGIN Close_Add_Finger
void Gestion_Personnel::Close_Add_Finger()
{
    ui->t->lower();
    ui->CloseAdF->lower();
    ui->FingerL->lower();
}
//END Close_Add_Finger

//BEGIN Get_data
void Gestion_Personnel::Get_data()
{
    //ui->t->setPlainText("Stored!");
    QByteArray data = A.read_from_arduino();

    // Split the data into lines based on newline characters
    QList<QByteArray> lines = data.split('\n');

    // Process each line
    foreach(const QByteArray &line, lines) {
        // Split the line into words based on whitespace
        QList<QByteArray> words = line.split(' ');

        // Append each word to the QPlainTextEdit
        foreach(const QByteArray &word, words) {
            // Check if the word is not empty
            if (!word.isEmpty()) {
                ui->t->appendPlainText(word);
            }
        }
    }
    QString textWithNewlines = ui->t->toPlainText();
    QString textWithoutNewlines = textWithNewlines.replace('\n', " ");
    ui->t->setPlainText(textWithoutNewlines);

    int index = textWithoutNewlines.indexOf("#");
    if (index != -1) {
        // Use regular expression to match the digits after "#"
        QRegularExpression regex("#(\\d+)");
        QRegularExpressionMatch match = regex.match(textWithoutNewlines, index);
        if (match.hasMatch()) {
            QString numberString = match.captured(1); // Get the first captured group (the digits)
            int number = numberString.toInt();
            qDebug() << "#Id: " << number;
        }
    }

    //ui->t->setPlainText("Stored! ");
    int index1 = textWithoutNewlines.indexOf("Stored! ");
    if (index1 != -1) {
        ui->t->setPlainText("");
        if (ui->tableW->selectionModel()->currentIndex().isValid()) {
            QString Fid = ui->HiddenId->text();
            QString CIN = ui->tableW->model()->data(ui->tableW->model()->index(ui->tableW->selectionModel()->currentIndex().row(), 0)).toString();
            QString queryText = "UPDATE employee SET FINGERID = :value WHERE CIN = :cin ;";
            QSqlQuery query;
            query.prepare(queryText);
            query.bindValue(":value", Fid);
            query.bindValue(":cin", CIN);
            if(query.exec()){
                QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Empreite affectee avec succes.\n"));
            }
            else {
                QMessageBox::information(nullptr, QObject::tr("system"),QObject::tr("Erreur.\n"));
            }


        }
    }

}
//END Get_data

