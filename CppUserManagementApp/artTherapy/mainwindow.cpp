#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Code = "";
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

    //BEGIN Arduino
    int rett=A2.connect_arduino();
    switch(rett){
    case(0):qDebug()<< "arduino is available and connected to : "<< A2.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A2.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    //END Arduino

    QObject::connect(A.getserial(), &QIODevice::readyRead, this, [this]() {
        QTimer::singleShot(100, this, &MainWindow::Get_Data); // Adjust the delay (in milliseconds) as needed
    });

    //BEGIN CloseAdF
    connect(ui->CloseAdF, &QPushButton::clicked, this, &MainWindow::Close_Add_Finger);
    //END CloseAdF
}

MainWindow::~MainWindow()
{
    delete ui;
}

//BEGIN LOGIN
void MainWindow::on_login_clicked() {
    QString email = ui->email->text();
    QString mdp = ui->mdp->text();
    QSqlQuery query;
    query.prepare("SELECT role FROM employee WHERE mdp = :mdp AND email = :email;");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    if (query.exec()) {
        if (query.next()) {
            A2.write_to_arduino("porte");
            if (query.value(0).toString() == "Gestion_Personnels") {


                // Create a QTimer object
                QTimer *timer = new QTimer(this);

                // Connect the timeout signal of the QTimer to a lambda function
                connect(timer, &QTimer::timeout, [=]() {
                    A2.close_arduino();
                    delete timer; // Delete the timer after it's done
                });
                A.close_arduino();
                // Start the timer with a delay of 2 seconds (2000 milliseconds)
                timer->start(500);

                Menu* w = new Menu();
                w->show();
                this->close();
            }

            else if (query.value(0).toString()=="Gestion_Participants") {
                A.close_arduino();
                gestion_participant* w = new gestion_participant();
                w->HideMenu();
                w->show();
                this->close();
            }
            else if (query.value(0).toString()=="Gestion_Oeuvres") {
                A.close_arduino();
                gestion_oeuvre* w = new gestion_oeuvre();
                w->HideMenu();
                w->show();
                this->close();
            }
            else if (query.value(0).toString()=="Gestion_Charites") {
                A.close_arduino();
                gestion_charite* w = new gestion_charite();
                w->HideMenu();
                w->show();
                this->close();
            }
            else if (query.value(0).toString()=="Gestion_Evenements") {
                A.close_arduino();
                gestion_evenement* w = new gestion_evenement();
                w->HideMenu();
                w->show();
                this->close();
            }
            else if (query.value(0).toString()=="Employee") {
                A.close_arduino();
                gestion_Achat* w = new gestion_Achat();
                w->HideMenu();
                w->show();
                this->close();
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Veuillez vérifier votre adresse e-mail et votre mot de passe.");
        }
    }
}
//END LOGIN

//BEGIN FACE_SCAN
void MainWindow::on_FACE_SCAN_clicked() {

    QProcess process;

    QString pythonCommand = "python";
    QStringList scriptArgs;
    scriptArgs << "D:\\ESPRIT\\c++\\Projet\\ProjetC++\\PythonScripts\\face\\main.py";

    process.start(pythonCommand, scriptArgs);

    process.waitForFinished(-1);
    QString role = process.readAllStandardOutput();

    if(role.contains("Gestion_Personnels")){

        A.close_arduino();
        Menu* w = new Menu();
        w->show();
        this->close();
    }
    else if (role.contains("Gestion_Participants")) {
        A.close_arduino();
        gestion_participant* w = new gestion_participant();
        w->show();
        this->close();
    }
    else if (role.contains("Gestion_Oeuvres")) {
        gestion_oeuvre* w = new gestion_oeuvre();
        w->HideMenu();
        w->show();
        this->close();
        A.close_arduino();
    }
    else if (role.contains("Gestion_Charites")) {
        A.close_arduino();
        gestion_charite* w = new gestion_charite();
        w->show();
        this->close();
    }
    else if (role.contains("Gestion_Evenements")) {
        A.close_arduino();
        gestion_evenement* w = new gestion_evenement();
        w->show();
        this->close();
    }
    else if (role.contains("Employee")) {
        A.close_arduino();
        gestion_Achat* w = new gestion_Achat();
        w->show();
        this->close();
    }
    else if (role.contains("Unkown")){
        QMessageBox::critical(this, "System", "visage non reconnu!!");
    }
}
//END FACE_SCAN

void MainWindow::Get_Data()
{
    QByteArray data = A.read_from_arduino();
    QList<QByteArray> lines = data.split('\n');

    foreach(const QByteArray &line, lines) {

        QList<QByteArray> words = line.split(' ');

        foreach(const QByteArray &word, words) {
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
        QObject::disconnect(A.getserial(), &QIODevice::readyRead, this, &MainWindow::Get_Data);

        QRegularExpression regex("#(\\d+)");
        QRegularExpressionMatch match = regex.match(textWithoutNewlines, index);
        if (match.hasMatch()) {
            QString numberString = match.captured(1); // Get the first captured group (the digits)
            int idf = numberString.toInt();
            QString queryText = "select role from employee WHERE fingerid = :fid";
            QSqlQuery query;
            query.prepare(queryText);
            query.bindValue(":fid", idf);
            query.exec();
            if(query.next()){
                QTimer::singleShot(1500, this, [this]() {
                    QObject::disconnect(A.getserial(), &QIODevice::readyRead, this, &MainWindow::Get_Data);
                });

                QString role = query.value(0).toString();
                if(role.contains("Gestion_Personnels") && !bOOl){
                    A2.write_to_arduino("porte");
                    bOOl = true;
                    A.close_arduino();
                    Menu* w = new Menu();
                    w->show();
                    this->close();
                }
                else if (role.contains("Gestion_Participants") && !bOOl) {
                    bOOl = true;
                    A.close_arduino();
                    gestion_participant* w = new gestion_participant();
                    w->show();
                    this->close();
                }
                else if (role.contains("Gestion_Oeuvres") && !bOOl) {
                    bOOl = true;
                    gestion_oeuvre* w = new gestion_oeuvre();
                    w->show();
                    this->close();
                    A.close_arduino();
                }
                else if (role.contains("Gestion_Charites") && !bOOl) {
                    bOOl = true;
                    A.close_arduino();
                    gestion_charite* w = new gestion_charite();
                    w->show();
                    this->close();
                }
                else if (role.contains("Gestion_Evenements") && !bOOl) {
                    bOOl = true;
                    A.close_arduino();
                    gestion_evenement* w = new gestion_evenement();
                    w->show();
                    this->close();
                }
                else if (role.contains("Employee") && !bOOl) {
                    bOOl = true;
                    A.close_arduino();
                    gestion_Achat* w = new gestion_Achat();
                    w->show();
                    this->close();
                }

            }
        }
    }
    if(textWithoutNewlines.contains("Did not find a match ")){
        QTimer::singleShot(500, this, [this]() {
            QObject::disconnect(A.getserial(), &QIODevice::readyRead, this, &MainWindow::Get_Data);
        });
        if(!bOOl){
            bOOl = true;
            Close_Add_Finger();
            QMessageBox::critical(this, "System", "Empreinte non reconnu!!");

        }
    }

    int index3 = textWithoutNewlines.indexOf("the code is : ");
    if (index3 != -1) {
        QRegularExpression regex("(\\d+)");
        QRegularExpressionMatch match = regex.match(textWithoutNewlines, index3);
        if (match.hasMatch()) {
            Code = match.captured(1);
            qDebug() << "Extracted Code:" << Code;
            if (Code == "1234") {
                A.write_to_arduino("ToneOff");
            } else {
                QTextToSpeech *tts = new QTextToSpeech(this);
                QString text = "the Code is incorrect try again";
                tts->say(text);
            }
            ui->t->setPlainText("");
        }
    }



}

void MainWindow::on_FINGER_SCAN_clicked(){
    bOOl = false;
    QObject::connect(A.getserial(), &QIODevice::readyRead, this, [this]() {
        QTimer::singleShot(1500, this, &MainWindow::Get_Data); // Adjust the delay (in milliseconds) as needed
    });
    ui->t->setPlainText("");

    QTimer *timer = new QTimer(this);
    int blinkCount = 0; // Variable to track the number of blinks
    ui->FingerL->raise();

    QObject::connect(timer, &QTimer::timeout, [=]() mutable {
        if (blinkCount < 4) {
            ui->FingerL->setVisible(!ui->FingerL->isVisible());
            blinkCount++;
        } else {

            QObject::disconnect(timer, &QTimer::timeout, nullptr, nullptr);
            timer->stop();
            delete timer;
            ui->t->setPlainText("Put your finger!!");
            ui->t->raise();
            ui->CloseAdF->raise();
        }
    });


    int interval = 500;
    timer->start(interval);
    QByteArray commandData = "CCheck";
    A.write_to_arduino(commandData);
}

//END FORGET
void MainWindow::on_oublier_clicked(){
    forgetP* w = new forgetP();
    w->show();
}
//END FORGET

//BEGIN Close_Add_Finger
void MainWindow::Close_Add_Finger()
{
    ui->t->lower();
    ui->CloseAdF->lower();
    ui->FingerL->lower();
}
//END Close_Add_Finger

/*//BEGIN generateCode
QString MainWindow::generateCode() {
    QString code;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);
    for (int i = 0; i < 4; ++i) {
        code.append(QString::number(dis(gen)));
    }
    return code;
}
//END generateCode*/
