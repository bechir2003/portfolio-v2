#include "Connexion_Bd/connexion_bd.h"
#include <QApplication>
#include "mainwindow.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion_bd c;

    if(c.createconnect()){
        w.show();
    }
    else{
        cout<<"error";
    }

    return a.exec();
}
