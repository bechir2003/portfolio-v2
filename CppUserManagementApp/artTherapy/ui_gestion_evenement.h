/********************************************************************************
** Form generated from reading UI file 'gestion_evenement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_EVENEMENT_H
#define UI_GESTION_EVENEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_evenement
{
public:
    QLabel *label_11;
    QPushButton *telecharger;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QLabel *label_22;
    QPushButton *stat;
    QPushButton *pushButton_15;
    QPushButton *annuler;
    QPushButton *ajouter;
    QLineEdit *search;
    QPushButton *logout;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *nomevent;
    QLabel *label_6;
    QLineEdit *lieu;
    QLabel *label_7;
    QDateEdit *datedeb;
    QLabel *label_8;
    QDateEdit *datefin;
    QLabel *label_5;
    QLineEdit *description;
    QLabel *label_9;
    QComboBox *comboBox;
    QLabel *label_10;
    QLineEdit *capacite;
    QLabel *label;
    QLabel *Background;
    QLabel *logo;
    QPushButton *Menu;
    QPushButton *afficher;
    QComboBox *triCombo;
    QFrame *frame;
    QRadioButton *asc;
    QRadioButton *desc;
    QLabel *title;

    void setupUi(QDialog *gestion_evenement)
    {
        if (gestion_evenement->objectName().isEmpty())
            gestion_evenement->setObjectName(QStringLiteral("gestion_evenement"));
        gestion_evenement->resize(2001, 1078);
        gestion_evenement->setStyleSheet(QStringLiteral(""));
        label_11 = new QLabel(gestion_evenement);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 220, 271, 41));
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
        telecharger = new QPushButton(gestion_evenement);
        telecharger->setObjectName(QStringLiteral("telecharger"));
        telecharger->setGeometry(QRect(460, 670, 131, 41));
        telecharger->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    background-image: url(\"images/download.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-color: #ffffff; /* Arri\303\250re-plan blanc */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7; /* Arri\303\250re-plan bleu au survol */\n"
"    color: #ffff; /* Texte en blanc au survol */\n"
"}"));
        label_2 = new QLabel(gestion_evenement);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 20, 91, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/logo.png")));
        tableWidget = new QTableWidget(gestion_evenement);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(460, 190, 1331, 481));
        label_22 = new QLabel(gestion_evenement);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(2070, -70, 56, 31));
        label_22->setPixmap(QPixmap(QString::fromUtf8("../gestionevent/image/trash-2.svg")));
        stat = new QPushButton(gestion_evenement);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(500, 140, 111, 41));
        stat->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    border: 2px solid #792382;\n"
"    color: #792382; /* Changement de couleur du texte en violet */\n"
"    border-radius: 5px;\n"
"    background-image: url(\"images/bar-chart.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-color: #fff; /* Changement de couleur de fond en blanc */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7; /* Changement de couleur de fond au survol */\n"
"    color: #792382; /* Garder la couleur du texte en violet */\n"
"}\n"
"\n"
""));
        pushButton_15 = new QPushButton(gestion_evenement);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(1320, 130, 141, 41));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    background-image: url(\"images/calendar.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
"\n"
""));
        annuler = new QPushButton(gestion_evenement);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setGeometry(QRect(250, 590, 111, 41));
        annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    background-color: white; /* Fond blanc */\n"
"    color: #792382; /* \303\211criture en violet */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        ajouter = new QPushButton(gestion_evenement);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(80, 590, 111, 41));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    background-color: white; /* Fond blanc */\n"
"    color: #792382; /* \303\211criture en violet */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        search = new QLineEdit(gestion_evenement);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(740, 140, 571, 41));
        search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        logout = new QPushButton(gestion_evenement);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(50, 750, 151, 51));
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
        formLayoutWidget = new QWidget(gestion_evenement);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 300, 401, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        nomevent = new QLineEdit(formLayoutWidget);
        nomevent->setObjectName(QStringLiteral("nomevent"));
        nomevent->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, nomevent);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        lieu = new QLineEdit(formLayoutWidget);
        lieu->setObjectName(QStringLiteral("lieu"));
        lieu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));

        formLayout->setWidget(1, QFormLayout::FieldRole, lieu);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        datedeb = new QDateEdit(formLayoutWidget);
        datedeb->setObjectName(QStringLiteral("datedeb"));
        datedeb->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::FieldRole, datedeb);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        datefin = new QDateEdit(formLayoutWidget);
        datefin->setObjectName(QStringLiteral("datefin"));
        datefin->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::FieldRole, datefin);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        description = new QLineEdit(formLayoutWidget);
        description->setObjectName(QStringLiteral("description"));
        description->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));

        formLayout->setWidget(4, QFormLayout::FieldRole, description);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_10);

        capacite = new QLineEdit(formLayoutWidget);
        capacite->setObjectName(QStringLiteral("capacite"));
        capacite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));

        formLayout->setWidget(6, QFormLayout::FieldRole, capacite);

        label = new QLabel(gestion_evenement);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 56, 16));
        Background = new QLabel(gestion_evenement);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(-10, 0, 2081, 1311));
        Background->setStyleSheet(QStringLiteral("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/back.jpg\");"));
        logo = new QLabel(gestion_evenement);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(950, 0, 111, 91));
        logo->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        Menu = new QPushButton(gestion_evenement);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(40, 840, 181, 41));
        Menu->setStyleSheet(QLatin1String("QPushButton {\n"
"    /*padding: 10px 20px;*/\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
"\n"
""));
        afficher = new QPushButton(gestion_evenement);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(1740, 200, 41, 41));
        afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        triCombo = new QComboBox(gestion_evenement);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(1480, 130, 221, 41));
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
        frame = new QFrame(gestion_evenement);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1710, 130, 81, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        asc = new QRadioButton(frame);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(10, 0, 97, 20));
        asc->setStyleSheet(QStringLiteral("color:#43aff7"));
        asc->setChecked(true);
        desc = new QRadioButton(frame);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(10, 30, 97, 20));
        desc->setStyleSheet(QStringLiteral("color:#43aff7"));
        title = new QLabel(gestion_evenement);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(870, 90, 271, 41));
        title->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        Menu->raise();
        Background->raise();
        label_11->raise();
        telecharger->raise();
        label_2->raise();
        tableWidget->raise();
        label_22->raise();
        stat->raise();
        pushButton_15->raise();
        annuler->raise();
        ajouter->raise();
        search->raise();
        logout->raise();
        formLayoutWidget->raise();
        label->raise();
        logo->raise();
        afficher->raise();
        triCombo->raise();
        frame->raise();
        title->raise();

        retranslateUi(gestion_evenement);

        QMetaObject::connectSlotsByName(gestion_evenement);
    } // setupUi

    void retranslateUi(QDialog *gestion_evenement)
    {
        gestion_evenement->setWindowTitle(QApplication::translate("gestion_evenement", "Dialog", Q_NULLPTR));
        label_11->setText(QApplication::translate("gestion_evenement", "Ajouter un \303\251v\303\250nement", Q_NULLPTR));
        telecharger->setText(QApplication::translate("gestion_evenement", "T\303\251l\303\251charger", Q_NULLPTR));
        label_2->setText(QString());
        label_22->setText(QString());
        stat->setText(QApplication::translate("gestion_evenement", "Statistique", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("gestion_evenement", "Calendrier", Q_NULLPTR));
        annuler->setText(QApplication::translate("gestion_evenement", "Annuler", Q_NULLPTR));
        ajouter->setText(QApplication::translate("gestion_evenement", "Ajouter", Q_NULLPTR));
        search->setPlaceholderText(QApplication::translate("gestion_evenement", "Rechercher..", Q_NULLPTR));
        logout->setText(QApplication::translate("gestion_evenement", "D\303\251connexion", Q_NULLPTR));
        label_4->setText(QApplication::translate("gestion_evenement", "Nom \303\251v\303\251nement", Q_NULLPTR));
        nomevent->setPlaceholderText(QApplication::translate("gestion_evenement", "entrer le nom ", Q_NULLPTR));
        label_6->setText(QApplication::translate("gestion_evenement", "Lieu", Q_NULLPTR));
        lieu->setPlaceholderText(QApplication::translate("gestion_evenement", "entrer le lieu", Q_NULLPTR));
        label_7->setText(QApplication::translate("gestion_evenement", "Date d\303\251but", Q_NULLPTR));
        label_8->setText(QApplication::translate("gestion_evenement", "Date fin", Q_NULLPTR));
        label_5->setText(QApplication::translate("gestion_evenement", "Description", Q_NULLPTR));
        description->setPlaceholderText(QApplication::translate("gestion_evenement", "d\303\251crire l'\303\251v\303\250nement", Q_NULLPTR));
        label_9->setText(QApplication::translate("gestion_evenement", "Statut", Q_NULLPTR));
        label_10->setText(QApplication::translate("gestion_evenement", "Capacit\303\251", Q_NULLPTR));
        capacite->setPlaceholderText(QApplication::translate("gestion_evenement", "entrer la capacit\303\251", Q_NULLPTR));
        label->setText(QString());
        Background->setText(QString());
        logo->setText(QString());
        Menu->setText(QApplication::translate("gestion_evenement", "Menu", Q_NULLPTR));
        afficher->setText(QString());
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("gestion_evenement", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_evenement", "Nom", Q_NULLPTR)
         << QApplication::translate("gestion_evenement", "Lieu", Q_NULLPTR)
         << QApplication::translate("gestion_evenement", "Statut", Q_NULLPTR)
        );
        asc->setText(QApplication::translate("gestion_evenement", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("gestion_evenement", "desc", Q_NULLPTR));
        title->setText(QApplication::translate("gestion_evenement", "Gestion des \303\251v\303\250nements", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_evenement: public Ui_gestion_evenement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_EVENEMENT_H
