/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *email;
    QLabel *label;
    QLineEdit *mdp;
    QLabel *label_3;
    QPushButton *login;
    QPushButton *oublier;
    QLabel *label_11;
    QLabel *label_2;
    QPushButton *FACE_SCAN;
    QPushButton *FINGER_SCAN;
    QLabel *label_4;
    QPlainTextEdit *t;
    QLabel *FingerL;
    QPushButton *CloseAdF;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1111, 694);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(320, 20, 451, 511));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        email = new QLineEdit(frame);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(130, 170, 201, 41));
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"C:/Users/Kinza/Documents/login/img login/user (1).svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #666; /* Couleur du texte de rep\303\250re */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 180, 56, 51));
        label->setStyleSheet(QLatin1String("background-repeat: no-repeat;\n"
"background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/user.svg\");\n"
""));
        mdp = new QLineEdit(frame);
        mdp->setObjectName(QStringLiteral("mdp"));
        mdp->setGeometry(QRect(130, 250, 201, 41));
        mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"C:/Users/Kinza/Documents/login/img login/key (1).svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #666; /* Couleur du texte de rep\303\250re */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}&"));
        mdp->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 260, 56, 51));
        label_3->setStyleSheet(QLatin1String("background-repeat: no-repeat;\n"
"background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/key.svg\");\n"
""));
        login = new QPushButton(frame);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(160, 310, 145, 34));
        login->setStyleSheet(QLatin1String("QPushButton {\n"
"    /*padding: 10px 20px;*/\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-image: url(\"images/log-in.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
"\n"
"\n"
""));
        oublier = new QPushButton(frame);
        oublier->setObjectName(QStringLiteral("oublier"));
        oublier->setGeometry(QRect(140, 370, 171, 34));
        oublier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: underline; /* Soulign\303\251 */\n"
"    border: none; /* Pas de contour */\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: transparent; /* Fond transparent */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 90, 121, 61));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 20, 121, 91));
        label_2->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        FACE_SCAN = new QPushButton(frame);
        FACE_SCAN->setObjectName(QStringLiteral("FACE_SCAN"));
        FACE_SCAN->setGeometry(QRect(110, 470, 251, 34));
        FACE_SCAN->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"	background : white;\n"
"	background-image: url(\"images/camera.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        FINGER_SCAN = new QPushButton(frame);
        FINGER_SCAN->setObjectName(QStringLiteral("FINGER_SCAN"));
        FINGER_SCAN->setGeometry(QRect(110, 430, 242, 34));
        FINGER_SCAN->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"	background : white;\n"
"	background-image: url(\"images/finger.png\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 1111, 681));
        label_4->setStyleSheet(QLatin1String("\n"
"background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/login.png\");\n"
""));
        t = new QPlainTextEdit(centralwidget);
        t->setObjectName(QStringLiteral("t"));
        t->setGeometry(QRect(380, 470, 331, 161));
        t->setStyleSheet(QLatin1String("background-color: transparent;\n"
" border: 0px;"));
        t->setReadOnly(true);
        FingerL = new QLabel(centralwidget);
        FingerL->setObjectName(QStringLiteral("FingerL"));
        FingerL->setGeometry(QRect(350, 160, 361, 471));
        FingerL->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"images/FingerIcon.png\");\n"
"	text-align: center;\n"
"	background-repeat: no-repeat;\n"
"	background-color: white;\n"
"\n"
"\n"
""));
        CloseAdF = new QPushButton(centralwidget);
        CloseAdF->setObjectName(QStringLiteral("CloseAdF"));
        CloseAdF->setGeometry(QRect(660, 170, 31, 31));
        CloseAdF->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        MainWindow->setCentralWidget(centralwidget);
        t->raise();
        CloseAdF->raise();
        FingerL->raise();
        label_4->raise();
        frame->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1111, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        email->setPlaceholderText(QApplication::translate("MainWindow", "Nom d'utilisateur", Q_NULLPTR));
        label->setText(QString());
        mdp->setPlaceholderText(QApplication::translate("MainWindow", "Mot de passe..", Q_NULLPTR));
        label_3->setText(QString());
        login->setText(QApplication::translate("MainWindow", "Se connecter", Q_NULLPTR));
        oublier->setText(QApplication::translate("MainWindow", "Mot de passe Oubli\303\251?", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Bienvenue", Q_NULLPTR));
        label_2->setText(QString());
        FACE_SCAN->setText(QApplication::translate("MainWindow", "Reconnaissance faciale", Q_NULLPTR));
        FINGER_SCAN->setText(QApplication::translate("MainWindow", "Empreinte Digital", Q_NULLPTR));
        label_4->setText(QString());
        FingerL->setText(QString());
        CloseAdF->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
