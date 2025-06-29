#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    //BEGIN Greeting
    /*QTextToSpeech *tts = new QTextToSpeech(this);
    QString text = "Hi mister Bechir , hope you are doing well";
    tts->say(text);*/
    //END Greeting
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_GP_clicked(){
    Gestion_Personnel* w = new Gestion_Personnel();
    w->show();
    this->close();
    delete this;
}

void Menu::on_GPA_clicked(){
    gestion_participant* w = new gestion_participant();
    w->ShowMenu();
    w->show();
    delete this;
}

void Menu::on_GO_clicked(){
    gestion_oeuvre* w = new gestion_oeuvre();
    w->ShowMenu();
    w->show();
    delete this;
}

void Menu::on_GE_clicked(){
    gestion_evenement* w = new gestion_evenement();
    w->ShowMenu();
    w->show();
    delete this;
}

void Menu::on_GC_clicked(){
    gestion_charite* w = new gestion_charite();
    w->ShowMenu();
    w->show();
    delete this;
}

void Menu::on_GHA_clicked(){
    gestion_Achat* w = new gestion_Achat();
    w->ShowMenu();
    w->show();
    delete this;
}
