/********************************************************************************
** Form generated from reading UI file 'gestion_achat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_ACHAT_H
#define UI_GESTION_ACHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_gestion_Achat
{
public:
    QTableWidget *tableW;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_4;
    QLabel *label_40;
    QLabel *label_30;
    QLabel *label_31;
    QComboBox *Evenement;
    QPushButton *ajouter;
    QLabel *label_39;
    QComboBox *Participant;
    QComboBox *Oeuvre;
    QPushButton *Annuler;
    QLabel *label_43;
    QLabel *label_3;
    QLabel *label_46;
    QLabel *logo;
    QPushButton *logout;
    QLabel *label_45;
    QLabel *label;
    QLineEdit *search;
    QPushButton *downloadPDF;
    QFrame *frame;
    QComboBox *triCombo;
    QFrame *frame_2;
    QRadioButton *asc;
    QRadioButton *desc;
    QLabel *label_23;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_13;
    QComboBox *Participant_2;
    QLabel *label_14;
    QComboBox *Evenement_2;
    QPushButton *ajouter_participation;
    QPushButton *Annuler_2;
    QTableWidget *tableWidget_2;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *search_1;
    QComboBox *triCombo_1;
    QFrame *frame_3;
    QRadioButton *asc_2;
    QRadioButton *desc_2;
    QLabel *label_22;
    QPushButton *downloadPDF_2;
    QPushButton *Menu;
    QPushButton *refresh;
    QPushButton *refresh_2;

    void setupUi(QDialog *gestion_Achat)
    {
        if (gestion_Achat->objectName().isEmpty())
            gestion_Achat->setObjectName(QStringLiteral("gestion_Achat"));
        gestion_Achat->resize(2112, 994);
        tableW = new QTableWidget(gestion_Achat);
        tableW->setObjectName(QStringLiteral("tableW"));
        tableW->setGeometry(QRect(560, 230, 741, 481));
        formLayoutWidget_2 = new QWidget(gestion_Achat);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 270, 511, 321));
        formLayout_4 = new QFormLayout(formLayoutWidget_2);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_40 = new QLabel(formLayoutWidget_2);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_40);

        label_30 = new QLabel(formLayoutWidget_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_30);

        label_31 = new QLabel(formLayoutWidget_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_31);

        Evenement = new QComboBox(formLayoutWidget_2);
        Evenement->setObjectName(QStringLiteral("Evenement"));
        Evenement->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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

        formLayout_4->setWidget(3, QFormLayout::FieldRole, Evenement);

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
"    font-weight: bold; /* \303\211criture en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, ajouter);

        label_39 = new QLabel(formLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/b6651d8d-1e9f-45ec-8183-973f3ea7bf13_interface \303\240 bechir.zip.f13/PROJET C++/back.jpg")));

        formLayout_4->setWidget(12, QFormLayout::FieldRole, label_39);

        Participant = new QComboBox(formLayoutWidget_2);
        Participant->setObjectName(QStringLiteral("Participant"));
        Participant->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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

        formLayout_4->setWidget(1, QFormLayout::FieldRole, Participant);

        Oeuvre = new QComboBox(formLayoutWidget_2);
        Oeuvre->setObjectName(QStringLiteral("Oeuvre"));
        Oeuvre->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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

        formLayout_4->setWidget(2, QFormLayout::FieldRole, Oeuvre);

        Annuler = new QPushButton(formLayoutWidget_2);
        Annuler->setObjectName(QStringLiteral("Annuler"));
        Annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    background-color: white; /* Fond blanc */\n"
"    color: #792382; /* \303\211criture en violet */\n"
"    border-radius: 5px;\n"
"    font-weight: bold; /* \303\211criture en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        formLayout_4->setWidget(6, QFormLayout::FieldRole, Annuler);

        label_43 = new QLabel(gestion_Achat);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(730, 330, 61, 41));
        label_43->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/search (1).svg")));
        label_3 = new QLabel(gestion_Achat);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 70, 481, 41));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        label_46 = new QLabel(gestion_Achat);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(1140, 500, 61, 31));
        label_46->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/edit.svg")));
        logo = new QLabel(gestion_Achat);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(850, 0, 121, 81));
        logo->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        logout = new QPushButton(gestion_Achat);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(20, 950, 161, 41));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    font-weight: bold; /* \303\211criture en gras */\n"
"\n"
"    background-image: url(\"images/log-out.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));
        label_45 = new QLabel(gestion_Achat);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(730, 330, 61, 41));
        label_45->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/search (1).svg")));
        label = new QLabel(gestion_Achat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, -10, 2151, 1081));
        label->setStyleSheet(QStringLiteral("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/back.jpg\");"));
        search = new QLineEdit(gestion_Achat);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(570, 180, 311, 41));
        search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/search.svg\");\n"
"    background-repeat: no-repeat;\n"
"\n"
"    background-position: left center;\n"
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
        downloadPDF = new QPushButton(gestion_Achat);
        downloadPDF->setObjectName(QStringLiteral("downloadPDF"));
        downloadPDF->setGeometry(QRect(560, 720, 131, 41));
        downloadPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame = new QFrame(gestion_Achat);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1660, 110, 51, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        triCombo = new QComboBox(gestion_Achat);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(950, 180, 181, 41));
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
"\n"
""));
        frame_2 = new QFrame(gestion_Achat);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(1170, 170, 111, 51));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        asc = new QRadioButton(frame_2);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(10, 0, 97, 20));
        asc->setStyleSheet(QStringLiteral("color:black"));
        asc->setChecked(true);
        desc = new QRadioButton(frame_2);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(10, 30, 97, 20));
        desc->setStyleSheet(QStringLiteral("color:black"));
        label_23 = new QLabel(gestion_Achat);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(1470, 110, 271, 51));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        formLayoutWidget_3 = new QWidget(gestion_Achat);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(20, 680, 521, 271));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(formLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_13);

        Participant_2 = new QComboBox(formLayoutWidget_3);
        Participant_2->setObjectName(QStringLiteral("Participant_2"));
        Participant_2->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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

        formLayout_3->setWidget(0, QFormLayout::FieldRole, Participant_2);

        label_14 = new QLabel(formLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_14);

        Evenement_2 = new QComboBox(formLayoutWidget_3);
        Evenement_2->setObjectName(QStringLiteral("Evenement_2"));
        Evenement_2->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Evenement_2);

        ajouter_participation = new QPushButton(formLayoutWidget_3);
        ajouter_participation->setObjectName(QStringLiteral("ajouter_participation"));
        ajouter_participation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    background-color: white; /* Fond blanc */\n"
"    color: #792382; /* \303\211criture en violet */\n"
"    border-radius: 5px;\n"
"    font-weight: bold; /* \303\211criture en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ajouter_participation);

        Annuler_2 = new QPushButton(formLayoutWidget_3);
        Annuler_2->setObjectName(QStringLiteral("Annuler_2"));
        Annuler_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    background-color: white; /* Fond blanc */\n"
"    color: #792382; /* \303\211criture en violet */\n"
"    border-radius: 5px;\n"
"    font-weight: bold; /* \303\211criture en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
""));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, Annuler_2);

        tableWidget_2 = new QTableWidget(gestion_Achat);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(1310, 230, 611, 481));
        tableWidget_2->setStyleSheet(QStringLiteral(""));
        label_24 = new QLabel(gestion_Achat);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(190, 210, 201, 49));
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_25 = new QLabel(gestion_Achat);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(770, 120, 241, 51));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        search_1 = new QLineEdit(gestion_Achat);
        search_1->setObjectName(QStringLiteral("search_1"));
        search_1->setGeometry(QRect(1310, 180, 341, 41));
        search_1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/search.svg\");\n"
"    background-repeat: no-repeat;\n"
"\n"
"    background-position: left center;\n"
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
        triCombo_1 = new QComboBox(gestion_Achat);
        triCombo_1->setObjectName(QStringLiteral("triCombo_1"));
        triCombo_1->setGeometry(QRect(1660, 180, 181, 41));
        triCombo_1->setStyleSheet(QString::fromUtf8("/* Style de base du QComboBox */\n"
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
        frame_3 = new QFrame(gestion_Achat);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(1840, 180, 111, 51));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        asc_2 = new QRadioButton(frame_3);
        asc_2->setObjectName(QStringLiteral("asc_2"));
        asc_2->setGeometry(QRect(10, 0, 97, 20));
        asc_2->setStyleSheet(QStringLiteral("color:black"));
        asc_2->setChecked(true);
        desc_2 = new QRadioButton(frame_3);
        desc_2->setObjectName(QStringLiteral("desc_2"));
        desc_2->setGeometry(QRect(10, 30, 97, 20));
        desc_2->setStyleSheet(QStringLiteral("color:black"));
        label_22 = new QLabel(gestion_Achat);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(130, 620, 291, 49));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        downloadPDF_2 = new QPushButton(gestion_Achat);
        downloadPDF_2->setObjectName(QStringLiteral("downloadPDF_2"));
        downloadPDF_2->setGeometry(QRect(1320, 720, 131, 41));
        downloadPDF_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Menu = new QPushButton(gestion_Achat);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(20, 890, 161, 41));
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
        refresh = new QPushButton(gestion_Achat);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(1870, 240, 41, 41));
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
        refresh_2 = new QPushButton(gestion_Achat);
        refresh_2->setObjectName(QStringLiteral("refresh_2"));
        refresh_2->setGeometry(QRect(1250, 240, 41, 41));
        refresh_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Menu->raise();
        label->raise();
        tableW->raise();
        formLayoutWidget_2->raise();
        label_43->raise();
        label_3->raise();
        label_46->raise();
        logo->raise();
        logout->raise();
        label_45->raise();
        search->raise();
        downloadPDF->raise();
        frame->raise();
        triCombo->raise();
        frame_2->raise();
        label_23->raise();
        formLayoutWidget_3->raise();
        tableWidget_2->raise();
        label_24->raise();
        label_25->raise();
        search_1->raise();
        triCombo_1->raise();
        frame_3->raise();
        label_22->raise();
        downloadPDF_2->raise();
        refresh->raise();
        refresh_2->raise();

        retranslateUi(gestion_Achat);

        QMetaObject::connectSlotsByName(gestion_Achat);
    } // setupUi

    void retranslateUi(QDialog *gestion_Achat)
    {
        gestion_Achat->setWindowTitle(QApplication::translate("gestion_Achat", "Dialog", Q_NULLPTR));
        label_40->setText(QApplication::translate("gestion_Achat", "Participant", Q_NULLPTR));
        label_30->setText(QApplication::translate("gestion_Achat", "Oeuvre", Q_NULLPTR));
        label_31->setText(QApplication::translate("gestion_Achat", "Evenement", Q_NULLPTR));
        ajouter->setText(QApplication::translate("gestion_Achat", "Ajouter", Q_NULLPTR));
        label_39->setText(QString());
        Annuler->setText(QApplication::translate("gestion_Achat", "Annuler", Q_NULLPTR));
        label_43->setText(QString());
        label_3->setText(QApplication::translate("gestion_Achat", "Gestion Historiques d'achats/Participation", Q_NULLPTR));
        label_46->setText(QString());
        logo->setText(QString());
        logout->setText(QApplication::translate("gestion_Achat", "Se deconnecter", Q_NULLPTR));
        label_45->setText(QString());
        label->setText(QString());
        search->setPlaceholderText(QApplication::translate("gestion_Achat", "Rechercher..", Q_NULLPTR));
        downloadPDF->setText(QApplication::translate("gestion_Achat", "T\303\251l\303\251charger", Q_NULLPTR));
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("gestion_Achat", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_Achat", "Date d'achat", Q_NULLPTR)
         << QApplication::translate("gestion_Achat", "Prix", Q_NULLPTR)
        );
        asc->setText(QApplication::translate("gestion_Achat", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("gestion_Achat", "desc", Q_NULLPTR));
        label_23->setText(QApplication::translate("gestion_Achat", "Liste des participations", Q_NULLPTR));
        label_13->setText(QApplication::translate("gestion_Achat", "Participant", Q_NULLPTR));
        Participant_2->clear();
        Participant_2->insertItems(0, QStringList()
         << QString()
        );
        label_14->setText(QApplication::translate("gestion_Achat", "Evenement", Q_NULLPTR));
        Evenement_2->clear();
        Evenement_2->insertItems(0, QStringList()
         << QString()
        );
        ajouter_participation->setText(QApplication::translate("gestion_Achat", "Ajouter participation", Q_NULLPTR));
        Annuler_2->setText(QApplication::translate("gestion_Achat", "Annuler", Q_NULLPTR));
        label_24->setText(QApplication::translate("gestion_Achat", "Ajouter un achat", Q_NULLPTR));
        label_25->setText(QApplication::translate("gestion_Achat", "Historiques d'achats", Q_NULLPTR));
        search_1->setPlaceholderText(QApplication::translate("gestion_Achat", "Rechercher..", Q_NULLPTR));
        triCombo_1->clear();
        triCombo_1->insertItems(0, QStringList()
         << QApplication::translate("gestion_Achat", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_Achat", "CIN", Q_NULLPTR)
         << QApplication::translate("gestion_Achat", "ID_E", Q_NULLPTR)
        );
        asc_2->setText(QApplication::translate("gestion_Achat", "asc", Q_NULLPTR));
        desc_2->setText(QApplication::translate("gestion_Achat", "desc", Q_NULLPTR));
        label_22->setText(QApplication::translate("gestion_Achat", "Ajouter une Participation", Q_NULLPTR));
        downloadPDF_2->setText(QApplication::translate("gestion_Achat", "T\303\251l\303\251charger", Q_NULLPTR));
        Menu->setText(QApplication::translate("gestion_Achat", "Menu", Q_NULLPTR));
        refresh->setText(QString());
        refresh_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gestion_Achat: public Ui_gestion_Achat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_ACHAT_H
