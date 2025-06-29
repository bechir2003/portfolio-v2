#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QMessageBox>
#include "Menu/menu.h"
#include "Gestion_Charite/gestion_charite.h"
#include "Gestion_Evenement/gestion_evenement.h"
#include "Gestion_Oeuvre/gestion_oeuvre.h"
#include "Gestion_Participants/gestion_participant.h"
#include "Gestion_Personnel/gestion_personnel.h"
#include "Gestion_Personnel/forgetp.h"
#include "His_Achat/gestion_Achat.h"
#include "Arduino/arduino.h"
#include "Arduino/arduino2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Get_Data();
    void Close_Add_Finger();
    void get_code();

private:
    Ui::MainWindow *ui;
    Arduino A;
    Arduino2 A2;
    bool bOOl ;
    QString Code;


private slots:
    void on_login_clicked();
    void on_oublier_clicked();
    void on_FACE_SCAN_clicked();
    void on_FINGER_SCAN_clicked();
};
#endif // MAINWINDOW_H
