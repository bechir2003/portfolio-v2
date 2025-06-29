/********************************************************************************
** Form generated from reading UI file 'gestion_charite.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_CHARITE_H
#define UI_GESTION_CHARITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_charite
{
public:
    QPushButton *Menu;
    QPushButton *stat;
    QLabel *label_9;
    QLineEdit *recherche;
    QPushButton *telecharger;
    QTableWidget *tableW;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *statut;
    QDateEdit *date;
    QLineEdit *montant;
    QComboBox *methode;
    QLabel *label_16;
    QLineEdit *contact;
    QLabel *label_17;
    QLineEdit *destination;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *ajouter;
    QPushButton *annuler;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_4;
    QPushButton *logout;
    QTableView *tv;
    QLabel *label;
    QLabel *Background;
    QLabel *label_11;
    QComboBox *triCombo;
    QPushButton *refresh;
    QLabel *title;
    QRadioButton *asc;
    QRadioButton *desc;
    QLabel *logo;

    void setupUi(QDialog *gestion_charite)
    {
        if (gestion_charite->objectName().isEmpty())
            gestion_charite->setObjectName(QStringLiteral("gestion_charite"));
        gestion_charite->resize(1937, 1012);
        Menu = new QPushButton(gestion_charite);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(30, 840, 171, 41));
        Menu->setMinimumSize(QSize(0, 41));
        Menu->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: transparent; /* Ajoutez cette ligne pour d\303\251finir la couleur de fond */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"    color: #ffff;\n"
"}\n"
""));
        stat = new QPushButton(gestion_charite);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(430, 160, 111, 41));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: white; /* Arri\303\250re-plan blanc */\n"
"    background-image: url(\"images/bar-chart.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        label_9 = new QLabel(gestion_charite);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 10, 121, 101));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/images/logo.png")));
        recherche = new QLineEdit(gestion_charite);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(620, 160, 601, 41));
        recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"images/search.svg\");\n"
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
        telecharger = new QPushButton(gestion_charite);
        telecharger->setObjectName(QStringLiteral("telecharger"));
        telecharger->setGeometry(QRect(410, 750, 131, 41));
        telecharger->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: white; /* Arri\303\250re-plan blanc */\n"
"\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/download.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        tableW = new QTableWidget(gestion_charite);
        tableW->setObjectName(QStringLiteral("tableW"));
        tableW->setGeometry(QRect(410, 220, 1491, 521));
        tableW->setStyleSheet(QStringLiteral(""));
        gridLayoutWidget = new QWidget(gestion_charite);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 250, 351, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(4, 4, 0, 5);
        statut = new QComboBox(gridLayoutWidget);
        statut->setObjectName(QStringLiteral("statut"));
        statut->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(statut, 5, 2, 1, 1);

        date = new QDateEdit(gridLayoutWidget);
        date->setObjectName(QStringLiteral("date"));
        date->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 2px solid #3498db;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(date, 2, 2, 1, 1);

        montant = new QLineEdit(gridLayoutWidget);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(montant, 1, 2, 1, 1);

        methode = new QComboBox(gridLayoutWidget);
        methode->setObjectName(QStringLiteral("methode"));
        methode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(methode, 3, 2, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_16, 4, 1, 1, 1);

        contact = new QLineEdit(gridLayoutWidget);
        contact->setObjectName(QStringLiteral("contact"));
        contact->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(contact, 4, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_17, 5, 1, 1, 1);

        destination = new QLineEdit(gridLayoutWidget);
        destination->setObjectName(QStringLiteral("destination"));
        destination->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}"));

        gridLayout->addWidget(destination, 0, 2, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_13, 1, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_12, 0, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_14, 2, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}"));

        gridLayout->addWidget(label_15, 3, 1, 1, 1);

        ajouter = new QPushButton(gridLayoutWidget);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /*padding: 10px 20px;*/\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: white; /* Ajoutez cette ligne pour d\303\251finir la couleur de fond */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        gridLayout->addWidget(ajouter, 6, 0, 1, 1);

        annuler = new QPushButton(gridLayoutWidget);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /*padding: 10px 20px;*/\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-color: white; /* Ajoutez cette ligne pour d\303\251finir la couleur de fond */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        gridLayout->addWidget(annuler, 6, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        logout = new QPushButton(gestion_charite);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(30, 740, 171, 51));
        logout->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    background-image: url(\"images/log-out.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        tv = new QTableView(gestion_charite);
        tv->setObjectName(QStringLiteral("tv"));
        tv->setGeometry(QRect(1540, 220, 281, 71));
        tv->setStyleSheet(QStringLiteral(""));
        label = new QLabel(gestion_charite);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-20, -100, 1401, 731));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/back.jpg")));
        Background = new QLabel(gestion_charite);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(0, 0, 2081, 1311));
        Background->setStyleSheet(QStringLiteral("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/back.jpg\");"));
        label_11 = new QLabel(gestion_charite);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 190, 231, 41));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #800080; /* Couleur du texte violette */\n"
"    font-size: 20px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    background-color: #ffffff; /* Couleur de fond */\n"
"    border: 2px solid #800080; /* Bordure violette */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px; /* Marge int\303\251rieure */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #add8e6; /* Couleur de fond au survol (bleu clair) */\n"
"    border-color: #4B0082; /* Couleur de la bordure au survol */\n"
"}"));
        triCombo = new QComboBox(gestion_charite);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(1490, 140, 221, 41));
        triCombo->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
"QComboBox {\n"
"    padding: 8px;\n"
"    font-size: 16px;\n"
"    border: 2px solid #43aff7; /* Couleur de la bordure en bleu */\n"
"    border-radius: 5px;\n"
"    background-color: #fff;\n"
"    color: #792382; /* Couleur du texte en violet */\n"
"    background-image: url(\"C:/Users/user/Documents/interface \303\240 bechir/images/chevron-down.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: right center; /* Position de l'image \303\240 droite et centr\303\251e verticalement */\n"
"    padding-right: 25px; /* Ajustement de la taille pour laisser de l'espace \303\240 l'image */\n"
"}\n"
"\n"
"/* Style de la fl\303\250che du QComboBox */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Style de la fl\303\250che au survol */\n"
"QComboBox::drop-down:hover {\n"
"    background-color: #f0f0f0; /* Couleur de fond au survol en gris clair */\n"
"}\n"
"\n"
"/* Style du QComboBo"
                        "x au survol */\n"
"QComboBox:hover {\n"
"    background-color: #f0f0f0; /* Couleur de fond au survol en gris clair */\n"
"}\n"
""));
        refresh = new QPushButton(gestion_charite);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(1850, 170, 41, 41));
        refresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    color: #792382; /* Couleur du texte */\n"
"    border-radius: 5px;\n"
"    background-color: #ffffff; /* Arri\303\250re-plan blanc */\n"
"    border: none; \n"
"    background-image: url(\"images/refresh-ccw.svg\"); \n"
"    background-repeat: no-repeat; /* Ne pas r\303\251p\303\251ter l'image */\n"
"    background-position: center; /* Centrer l'image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7; /* Arri\303\250re-plan bleu au survol */\n"
"    color: #ffff; /* Texte en blanc au survol */\n"
"}\n"
"\n"
""));
        title = new QLabel(gestion_charite);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(890, 90, 271, 41));
        title->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        asc = new QRadioButton(gestion_charite);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(1730, 140, 97, 20));
        asc->setStyleSheet(QStringLiteral("color:#43aff7"));
        asc->setChecked(true);
        desc = new QRadioButton(gestion_charite);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(1730, 160, 97, 20));
        desc->setStyleSheet(QStringLiteral("color:#43aff7"));
        logo = new QLabel(gestion_charite);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(950, 0, 111, 91));
        logo->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        Menu->raise();
        Background->raise();
        label->raise();
        stat->raise();
        label_9->raise();
        recherche->raise();
        telecharger->raise();
        tableW->raise();
        gridLayoutWidget->raise();
        logout->raise();
        tv->raise();
        label_11->raise();
        triCombo->raise();
        refresh->raise();
        title->raise();
        asc->raise();
        desc->raise();
        logo->raise();

        retranslateUi(gestion_charite);

        QMetaObject::connectSlotsByName(gestion_charite);
    } // setupUi

    void retranslateUi(QDialog *gestion_charite)
    {
        gestion_charite->setWindowTitle(QApplication::translate("gestion_charite", "Dialog", Q_NULLPTR));
        Menu->setText(QApplication::translate("gestion_charite", "Menu", Q_NULLPTR));
        stat->setText(QApplication::translate("gestion_charite", "statistique", Q_NULLPTR));
        label_9->setText(QString());
        recherche->setText(QString());
        recherche->setPlaceholderText(QApplication::translate("gestion_charite", "Rechercher..", Q_NULLPTR));
        telecharger->setText(QApplication::translate("gestion_charite", "T\303\251l\303\251charger", Q_NULLPTR));
        montant->setPlaceholderText(QApplication::translate("gestion_charite", "entrer le montant", Q_NULLPTR));
        label_16->setText(QApplication::translate("gestion_charite", "  :", Q_NULLPTR));
        contact->setPlaceholderText(QApplication::translate("gestion_charite", "+216 ********", Q_NULLPTR));
        label_17->setText(QApplication::translate("gestion_charite", "  :", Q_NULLPTR));
        destination->setText(QString());
        destination->setPlaceholderText(QApplication::translate("gestion_charite", "entrer la destination", Q_NULLPTR));
        label_13->setText(QApplication::translate("gestion_charite", "  :", Q_NULLPTR));
        label_12->setText(QApplication::translate("gestion_charite", "  : ", Q_NULLPTR));
        label_14->setText(QApplication::translate("gestion_charite", "  :", Q_NULLPTR));
        label_15->setText(QApplication::translate("gestion_charite", "  :", Q_NULLPTR));
        ajouter->setText(QApplication::translate("gestion_charite", "Ajouter", Q_NULLPTR));
        annuler->setText(QApplication::translate("gestion_charite", "Annuler", Q_NULLPTR));
        label_2->setText(QApplication::translate("gestion_charite", "Destination", Q_NULLPTR));
        label_6->setText(QApplication::translate("gestion_charite", "Montant", Q_NULLPTR));
        label_5->setText(QApplication::translate("gestion_charite", "Date", Q_NULLPTR));
        label_3->setText(QApplication::translate("gestion_charite", "M\303\251thode", Q_NULLPTR));
        label_8->setText(QApplication::translate("gestion_charite", "Num\303\251ro", Q_NULLPTR));
        label_4->setText(QApplication::translate("gestion_charite", "Etat", Q_NULLPTR));
        logout->setText(QApplication::translate("gestion_charite", "D\303\251connexion", Q_NULLPTR));
        label->setText(QString());
        Background->setText(QString());
        label_11->setText(QApplication::translate("gestion_charite", "Ajouter une Charit\303\251", Q_NULLPTR));
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("gestion_charite", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_charite", "Montant", Q_NULLPTR)
         << QApplication::translate("gestion_charite", "Date_donation ", Q_NULLPTR)
         << QApplication::translate("gestion_charite", "Destination", Q_NULLPTR)
        );
        refresh->setText(QString());
        title->setText(QApplication::translate("gestion_charite", "Gestion des Oeuvres", Q_NULLPTR));
        asc->setText(QApplication::translate("gestion_charite", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("gestion_charite", "desc", Q_NULLPTR));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gestion_charite: public Ui_gestion_charite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_CHARITE_H
