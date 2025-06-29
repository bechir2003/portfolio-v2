/********************************************************************************
** Form generated from reading UI file 'gestion_participant.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_PARTICIPANT_H
#define UI_GESTION_PARTICIPANT_H

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

class Ui_gestion_participant
{
public:
    QLabel *label_5;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QPushButton *scan_CIN;
    QLabel *label;
    QLineEdit *CIN;
    QLabel *label_4;
    QLineEdit *nom;
    QLabel *label_9;
    QLineEdit *prenom;
    QLabel *label_6;
    QRadioButton *homme;
    QRadioButton *femme;
    QLabel *label_7;
    QLineEdit *email;
    QLabel *label_16;
    QLineEdit *num_tel;
    QLabel *label_19;
    QLineEdit *adresse;
    QLabel *label_17;
    QDateEdit *date_naiss;
    QPushButton *ajouter;
    QPushButton *annuler;
    QPushButton *telecharger;
    QLineEdit *rechercher;
    QPushButton *afficher;
    QTableWidget *tableWidget;
    QPushButton *statistique;
    QPushButton *logout;
    QLabel *label_21;
    QPushButton *rafraichir_ajouter_p;
    QLabel *Background;
    QLabel *logo;
    QPushButton *Menu;
    QFrame *frame;
    QRadioButton *asc;
    QRadioButton *desc;
    QComboBox *triCombo;
    QLabel *title;
    QLabel *logo_2;
    QLabel *title_2;
    QLabel *title_3;
    QLabel *title_4;
    QLabel *logo_3;

    void setupUi(QDialog *gestion_participant)
    {
        if (gestion_participant->objectName().isEmpty())
            gestion_participant->setObjectName(QStringLiteral("gestion_participant"));
        gestion_participant->resize(1934, 997);
        label_5 = new QLabel(gestion_participant);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 120, 61, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/search (1).svg")));
        formLayoutWidget_2 = new QWidget(gestion_participant);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 230, 361, 471));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        scan_CIN = new QPushButton(formLayoutWidget_2);
        scan_CIN->setObjectName(QStringLiteral("scan_CIN"));
        scan_CIN->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    display: inline-block;\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    cursor: pointer;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-color: #ffffff; /* Arri\303\250re-plan blanc */\n"
"    background-image: url(\"C:/Users/user/Documents/interface \303\240 bechir/images/camera.svg\"); /* Chemin de l'image */\n"
"    background-repeat: no-repeat; /* Ne pas r\303\251p\303\251ter l'image */\n"
"    background-position: left center; /* Positionner l'image \303\240 gauche du bouton */\n"
"    padding-left: 40px; /* Ajustez ceci selon la taille de votre image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7; /* Arri\303\250re-plan bleu au survol */\n"
"    color: #ffff; /* Texte en blanc au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    transform: translateY(1px);\n"
"}\n"
""));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, scan_CIN);

        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        CIN = new QLineEdit(formLayoutWidget_2);
        CIN->setObjectName(QStringLiteral("CIN"));
        CIN->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(1, QFormLayout::FieldRole, CIN);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        nom = new QLineEdit(formLayoutWidget_2);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(2, QFormLayout::FieldRole, nom);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        prenom = new QLineEdit(formLayoutWidget_2);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(3, QFormLayout::FieldRole, prenom);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        homme = new QRadioButton(formLayoutWidget_2);
        homme->setObjectName(QStringLiteral("homme"));
        homme->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    padding: 5px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 15px;\n"
"    height: 15px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #2ecc71; /* Couleur de fond lorsque s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #3498db; /* Couleur de la bordure au survol */\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    background-color: #2ecc71; /* Couleur de fond lorsque s\303\251lectionn\303\251 et au survol */\n"
"}\n"
""));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, homme);

        femme = new QRadioButton(formLayoutWidget_2);
        femme->setObjectName(QStringLiteral("femme"));
        femme->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    padding: 5px;\n"
"    color: #333;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 15px;\n"
"    height: 15px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #2ecc71; /* Couleur de fond lorsque s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #3498db; /* Couleur de la bordure au survol */\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    background-color: #2ecc71; /* Couleur de fond lorsque s\303\251lectionn\303\251 et au survol */\n"
"}\n"
""));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, femme);

        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_7);

        email = new QLineEdit(formLayoutWidget_2);
        email->setObjectName(QStringLiteral("email"));
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(6, QFormLayout::FieldRole, email);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_16);

        num_tel = new QLineEdit(formLayoutWidget_2);
        num_tel->setObjectName(QStringLiteral("num_tel"));
        num_tel->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(7, QFormLayout::FieldRole, num_tel);

        label_19 = new QLabel(formLayoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_19);

        adresse = new QLineEdit(formLayoutWidget_2);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(8, QFormLayout::FieldRole, adresse);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_17);

        date_naiss = new QDateEdit(formLayoutWidget_2);
        date_naiss->setObjectName(QStringLiteral("date_naiss"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        date_naiss->setFont(font);
        date_naiss->setStyleSheet(QString::fromUtf8("/* Style de base pour QDateEdit */\n"
"QDateEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"/* Style lorsqu'il est activ\303\251 */\n"
"QDateEdit:focus {\n"
"    border-color: #2ecc71;\n"
"}\n"
""));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, date_naiss);

        ajouter = new QPushButton(formLayoutWidget_2);
        ajouter->setObjectName(QStringLiteral("ajouter"));
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

        formLayout_2->setWidget(11, QFormLayout::FieldRole, ajouter);

        annuler = new QPushButton(formLayoutWidget_2);
        annuler->setObjectName(QStringLiteral("annuler"));
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

        formLayout_2->setWidget(12, QFormLayout::FieldRole, annuler);

        telecharger = new QPushButton(gestion_participant);
        telecharger->setObjectName(QStringLiteral("telecharger"));
        telecharger->setGeometry(QRect(530, 580, 101, 31));
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
        rechercher = new QLineEdit(gestion_participant);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(720, 190, 401, 41));
        rechercher->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"images/search.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #666; /* Couleur du texte de rep\303\250re */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        afficher = new QPushButton(gestion_participant);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(1020, 290, 41, 31));
        afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    display: inline-block;\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    cursor: pointer;\n"
"    color: #792382; /* Couleur du texte */\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-color: #ffffff; /* Arri\303\250re-plan blanc */\n"
"    border: none; /* Supprimer la bordure */\n"
"    outline: none; /* Supprimer le contour au focus */\n"
"    background-image: url(\"C:/Users/user/Documents/interface \303\240 bechir/images/refresh-ccw.svg\"); /* Chemin de l'image */\n"
"    background-repeat: no-repeat; /* Ne pas r\303\251p\303\251ter l'image */\n"
"    background-position: center; /* Centrer l'image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7; /* Arri\303\250re-plan bleu au survol */\n"
"    color: #ffff; /* Texte en blanc au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    transform: translateY(1px);\n"
"}\n"
""));
        tableWidget = new QTableWidget(gestion_participant);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(520, 240, 1311, 321));
        tableWidget->setStyleSheet(QStringLiteral(""));
        statistique = new QPushButton(gestion_participant);
        statistique->setObjectName(QStringLiteral("statistique"));
        statistique->setGeometry(QRect(540, 200, 121, 31));
        statistique->setStyleSheet(QLatin1String("QPushButton {\n"
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
        logout = new QPushButton(gestion_participant);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(30, 890, 161, 41));
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
        label_21 = new QLabel(gestion_participant);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(60, 160, 251, 51));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        rafraichir_ajouter_p = new QPushButton(gestion_participant);
        rafraichir_ajouter_p->setObjectName(QStringLiteral("rafraichir_ajouter_p"));
        rafraichir_ajouter_p->setGeometry(QRect(1780, 250, 41, 31));
        rafraichir_ajouter_p->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Background = new QLabel(gestion_participant);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(0, -10, 2081, 1311));
        Background->setStyleSheet(QStringLiteral("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/back.jpg\");"));
        logo = new QLabel(gestion_participant);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(910, 0, 111, 91));
        logo->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        Menu = new QPushButton(gestion_participant);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(30, 830, 161, 41));
        Menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame = new QFrame(gestion_participant);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1560, 180, 141, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        asc = new QRadioButton(frame);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(10, 0, 97, 20));
        asc->setStyleSheet(QStringLiteral("color:#ffffff"));
        asc->setChecked(true);
        desc = new QRadioButton(frame);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(10, 30, 97, 20));
        desc->setStyleSheet(QLatin1String("color:#ffffff\n"
""));
        triCombo = new QComboBox(gestion_participant);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(1300, 180, 231, 41));
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
        title = new QLabel(gestion_participant);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(830, 80, 271, 41));
        title->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        logo_2 = new QLabel(gestion_participant);
        logo_2->setObjectName(QStringLiteral("logo_2"));
        logo_2->setGeometry(QRect(1470, 880, 111, 91));
        logo_2->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo_2->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        title_2 = new QLabel(gestion_participant);
        title_2->setObjectName(QStringLiteral("title_2"));
        title_2->setGeometry(QRect(1390, 960, 271, 41));
        title_2->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        title_3 = new QLabel(gestion_participant);
        title_3->setObjectName(QStringLiteral("title_3"));
        title_3->setGeometry(QRect(1660, 960, 271, 41));
        title_3->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        title_4 = new QLabel(gestion_participant);
        title_4->setObjectName(QStringLiteral("title_4"));
        title_4->setGeometry(QRect(1670, 960, 271, 41));
        title_4->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        logo_3 = new QLabel(gestion_participant);
        logo_3->setObjectName(QStringLiteral("logo_3"));
        logo_3->setGeometry(QRect(1660, 910, 111, 91));
        logo_3->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo_3->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        Background->raise();
        label_5->raise();
        formLayoutWidget_2->raise();
        telecharger->raise();
        rechercher->raise();
        afficher->raise();
        tableWidget->raise();
        statistique->raise();
        logout->raise();
        label_21->raise();
        rafraichir_ajouter_p->raise();
        logo->raise();
        Menu->raise();
        frame->raise();
        triCombo->raise();
        title->raise();
        logo_2->raise();
        title_2->raise();
        title_3->raise();
        title_4->raise();
        logo_3->raise();

        retranslateUi(gestion_participant);

        QMetaObject::connectSlotsByName(gestion_participant);
    } // setupUi

    void retranslateUi(QDialog *gestion_participant)
    {
        gestion_participant->setWindowTitle(QApplication::translate("gestion_participant", "Dialog", Q_NULLPTR));
        label_5->setText(QString());
        scan_CIN->setText(QApplication::translate("gestion_participant", "Scanner la carte CIN", Q_NULLPTR));
        label->setText(QApplication::translate("gestion_participant", "CIN", Q_NULLPTR));
        CIN->setText(QString());
        CIN->setPlaceholderText(QApplication::translate("gestion_participant", "CIN", Q_NULLPTR));
        label_4->setText(QApplication::translate("gestion_participant", "Nom", Q_NULLPTR));
        nom->setPlaceholderText(QApplication::translate("gestion_participant", "Nom ", Q_NULLPTR));
        label_9->setText(QApplication::translate("gestion_participant", "Pr\303\251nom", Q_NULLPTR));
        prenom->setPlaceholderText(QApplication::translate("gestion_participant", "prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("gestion_participant", "Sexe", Q_NULLPTR));
        homme->setText(QApplication::translate("gestion_participant", "Homme", Q_NULLPTR));
        femme->setText(QApplication::translate("gestion_participant", "Femme", Q_NULLPTR));
        label_7->setText(QApplication::translate("gestion_participant", "Email", Q_NULLPTR));
        email->setPlaceholderText(QApplication::translate("gestion_participant", "email", Q_NULLPTR));
        label_16->setText(QApplication::translate("gestion_participant", "Num Tel", Q_NULLPTR));
        num_tel->setPlaceholderText(QApplication::translate("gestion_participant", "numero", Q_NULLPTR));
        label_19->setText(QApplication::translate("gestion_participant", "Adresse", Q_NULLPTR));
        adresse->setPlaceholderText(QApplication::translate("gestion_participant", "adresse", Q_NULLPTR));
        label_17->setText(QApplication::translate("gestion_participant", "Date naissance", Q_NULLPTR));
        ajouter->setText(QApplication::translate("gestion_participant", "Ajouter", Q_NULLPTR));
        annuler->setText(QApplication::translate("gestion_participant", "Annuler", Q_NULLPTR));
        telecharger->setText(QApplication::translate("gestion_participant", "PDF", Q_NULLPTR));
        rechercher->setPlaceholderText(QApplication::translate("gestion_participant", "Rechercher..", Q_NULLPTR));
        afficher->setText(QString());
        statistique->setText(QApplication::translate("gestion_participant", "Statistique", Q_NULLPTR));
        logout->setText(QApplication::translate("gestion_participant", "Deconnexion", Q_NULLPTR));
        label_21->setText(QApplication::translate("gestion_participant", "Ajouter un Participant", Q_NULLPTR));
        rafraichir_ajouter_p->setText(QString());
        Background->setText(QString());
        logo->setText(QString());
        Menu->setText(QApplication::translate("gestion_participant", "Menu", Q_NULLPTR));
        asc->setText(QApplication::translate("gestion_participant", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("gestion_participant", "desc", Q_NULLPTR));
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("gestion_participant", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_participant", "Sexe", Q_NULLPTR)
         << QApplication::translate("gestion_participant", "Date de naissance", Q_NULLPTR)
         << QApplication::translate("gestion_participant", "Prenom", Q_NULLPTR)
        );
        title->setText(QApplication::translate("gestion_participant", "Gestion des participants", Q_NULLPTR));
        logo_2->setText(QString());
        title_2->setText(QApplication::translate("gestion_participant", "Gestion des participants", Q_NULLPTR));
        title_3->setText(QApplication::translate("gestion_participant", "Gestion des participants", Q_NULLPTR));
        title_4->setText(QApplication::translate("gestion_participant", "Gestion des participants", Q_NULLPTR));
        logo_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gestion_participant: public Ui_gestion_participant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_PARTICIPANT_H
