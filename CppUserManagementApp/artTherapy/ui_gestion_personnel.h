/********************************************************************************
** Form generated from reading UI file 'gestion_personnel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_PERSONNEL_H
#define UI_GESTION_PERSONNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gestion_Personnel
{
public:
    QPushButton *downloadPDF;
    QPushButton *stat;
    QPushButton *chat;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_4;
    QLabel *label_40;
    QLineEdit *CIN;
    QLabel *label_30;
    QLineEdit *nom;
    QLabel *label_31;
    QLineEdit *prenom;
    QLabel *label_32;
    QDateEdit *age;
    QLabel *label_33;
    QLineEdit *email;
    QLabel *label_34;
    QLineEdit *numtel;
    QLabel *label_35;
    QRadioButton *H;
    QRadioButton *F;
    QLabel *label_36;
    QLineEdit *adresse;
    QLabel *label_37;
    QLineEdit *salaire;
    QLabel *label_38;
    QComboBox *Role;
    QLabel *label_39;
    QPushButton *scan_Face;
    QPushButton *Add_Finger;
    QPushButton *ajouter;
    QPushButton *Annuler;
    QPushButton *scan_CIN;
    QFrame *frame;
    QRadioButton *asc;
    QRadioButton *desc;
    QPushButton *refresh;
    QLabel *title;
    QLabel *label_43;
    QTableWidget *tableW;
    QLabel *label_44;
    QLineEdit *search;
    QLabel *Background;
    QLabel *label_45;
    QPushButton *menu;
    QLabel *label_46;
    QLabel *label_47;
    QPushButton *logout;
    QCheckBox *OnOffModification;
    QWidget *widget;
    QComboBox *triCombo;
    QPushButton *qrCode;
    QPlainTextEdit *Historic;
    QPushButton *historique;
    QLabel *histLabel;
    QPushButton *CloseH;
    QPushButton *statOFF;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *onDark1;
    QLabel *label_3;
    QPlainTextEdit *t;
    QPushButton *CloseAdF;
    QLineEdit *HiddenId;
    QLabel *FingerL;
    QLabel *logo_3;
    QLabel *label_24;

    void setupUi(QDialog *Gestion_Personnel)
    {
        if (Gestion_Personnel->objectName().isEmpty())
            Gestion_Personnel->setObjectName(QStringLiteral("Gestion_Personnel"));
        Gestion_Personnel->resize(1928, 1012);
        downloadPDF = new QPushButton(Gestion_Personnel);
        downloadPDF->setObjectName(QStringLiteral("downloadPDF"));
        downloadPDF->setGeometry(QRect(430, 680, 131, 41));
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
        stat = new QPushButton(Gestion_Personnel);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(440, 120, 111, 41));
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
        chat = new QPushButton(Gestion_Personnel);
        chat->setObjectName(QStringLiteral("chat"));
        chat->setGeometry(QRect(10, 860, 161, 41));
        chat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        formLayoutWidget_2 = new QWidget(Gestion_Personnel);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 160, 411, 641));
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

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_40);

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

        formLayout_4->setWidget(2, QFormLayout::FieldRole, CIN);

        label_30 = new QLabel(formLayoutWidget_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_30);

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

        formLayout_4->setWidget(3, QFormLayout::FieldRole, nom);

        label_31 = new QLabel(formLayoutWidget_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_31);

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

        formLayout_4->setWidget(4, QFormLayout::FieldRole, prenom);

        label_32 = new QLabel(formLayoutWidget_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_32);

        age = new QDateEdit(formLayoutWidget_2);
        age->setObjectName(QStringLiteral("age"));
        age->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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

        formLayout_4->setWidget(5, QFormLayout::FieldRole, age);

        label_33 = new QLabel(formLayoutWidget_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_33);

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

        formLayout_4->setWidget(6, QFormLayout::FieldRole, email);

        label_34 = new QLabel(formLayoutWidget_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(7, QFormLayout::LabelRole, label_34);

        numtel = new QLineEdit(formLayoutWidget_2);
        numtel->setObjectName(QStringLiteral("numtel"));
        numtel->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_4->setWidget(7, QFormLayout::FieldRole, numtel);

        label_35 = new QLabel(formLayoutWidget_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(8, QFormLayout::LabelRole, label_35);

        H = new QRadioButton(formLayoutWidget_2);
        H->setObjectName(QStringLiteral("H"));
        H->setStyleSheet(QStringLiteral(""));
        H->setChecked(true);

        formLayout_4->setWidget(8, QFormLayout::FieldRole, H);

        F = new QRadioButton(formLayoutWidget_2);
        F->setObjectName(QStringLiteral("F"));
        F->setStyleSheet(QStringLiteral(""));

        formLayout_4->setWidget(9, QFormLayout::FieldRole, F);

        label_36 = new QLabel(formLayoutWidget_2);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(10, QFormLayout::LabelRole, label_36);

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

        formLayout_4->setWidget(10, QFormLayout::FieldRole, adresse);

        label_37 = new QLabel(formLayoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(11, QFormLayout::LabelRole, label_37);

        salaire = new QLineEdit(formLayoutWidget_2);
        salaire->setObjectName(QStringLiteral("salaire"));
        salaire->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_4->setWidget(11, QFormLayout::FieldRole, salaire);

        label_38 = new QLabel(formLayoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_4->setWidget(13, QFormLayout::LabelRole, label_38);

        Role = new QComboBox(formLayoutWidget_2);
        Role->setObjectName(QStringLiteral("Role"));
        Role->setStyleSheet(QLatin1String("padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333"));

        formLayout_4->setWidget(13, QFormLayout::FieldRole, Role);

        label_39 = new QLabel(formLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/b6651d8d-1e9f-45ec-8183-973f3ea7bf13_interface \303\240 bechir.zip.f13/PROJET C++/back.jpg")));

        formLayout_4->setWidget(16, QFormLayout::FieldRole, label_39);

        scan_Face = new QPushButton(formLayoutWidget_2);
        scan_Face->setObjectName(QStringLiteral("scan_Face"));
        scan_Face->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid white;\n"
"    color: black;\n"
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

        formLayout_4->setWidget(17, QFormLayout::SpanningRole, scan_Face);

        Add_Finger = new QPushButton(formLayoutWidget_2);
        Add_Finger->setObjectName(QStringLiteral("Add_Finger"));
        Add_Finger->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: left;\n"
"    text-decoration: none;\n"
"    border: 2px solid white;\n"
"    color: black;\n"
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

        formLayout_4->setWidget(18, QFormLayout::LabelRole, Add_Finger);

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
"\n"
""));

        formLayout_4->setWidget(18, QFormLayout::FieldRole, ajouter);

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
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
"\n"
""));

        formLayout_4->setWidget(19, QFormLayout::FieldRole, Annuler);

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

        formLayout_4->setWidget(1, QFormLayout::SpanningRole, scan_CIN);

        frame = new QFrame(Gestion_Personnel);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1780, 120, 141, 51));
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
        refresh = new QPushButton(frame);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(90, 10, 41, 41));
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
        title = new QLabel(Gestion_Personnel);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(860, 70, 271, 41));
        title->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        label_43 = new QLabel(Gestion_Personnel);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(720, 337, 61, 41));
        label_43->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/search (1).svg")));
        tableW = new QTableWidget(Gestion_Personnel);
        tableW->setObjectName(QStringLiteral("tableW"));
        tableW->setGeometry(QRect(420, 170, 1501, 481));
        label_44 = new QLabel(Gestion_Personnel);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(1130, 467, 61, 31));
        label_44->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/edit.svg")));
        search = new QLineEdit(Gestion_Personnel);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(740, 120, 651, 41));
        search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"    background-image: url(\"images/search.svg\");\n"
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
        Background = new QLabel(Gestion_Personnel);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(-30, 0, 2081, 1311));
        Background->setStyleSheet(QStringLiteral("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/back.jpg\");"));
        label_45 = new QLabel(Gestion_Personnel);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(720, 337, 61, 41));
        label_45->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/search (1).svg")));
        menu = new QPushButton(Gestion_Personnel);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(10, 810, 161, 41));
        menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_46 = new QLabel(Gestion_Personnel);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(1130, 507, 61, 31));
        label_46->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/edit.svg")));
        label_47 = new QLabel(Gestion_Personnel);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(1130, 507, 61, 31));
        label_47->setPixmap(QPixmap(QString::fromUtf8("../../../AppData/Local/Temp/Downloads/edit.svg")));
        logout = new QPushButton(Gestion_Personnel);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(10, 910, 161, 41));
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
        OnOffModification = new QCheckBox(Gestion_Personnel);
        OnOffModification->setObjectName(QStringLiteral("OnOffModification"));
        OnOffModification->setGeometry(QRect(860, 660, 421, 31));
        OnOffModification->setStyleSheet(QLatin1String("\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"\n"
"QCheckBox::indicator {\n"
"    /* Style for the unchecked indicator */\n"
"    image: url(images/on.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    /* Style for the checked indicator */\n"
"    image: url(images/off.png);\n"
"}\n"
""));
        widget = new QWidget(Gestion_Personnel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(410, 150, 1541, 641));
        triCombo = new QComboBox(Gestion_Personnel);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(1590, 120, 181, 41));
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
        qrCode = new QPushButton(Gestion_Personnel);
        qrCode->setObjectName(QStringLiteral("qrCode"));
        qrCode->setGeometry(QRect(570, 680, 141, 41));
        qrCode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Historic = new QPlainTextEdit(Gestion_Personnel);
        Historic->setObjectName(QStringLiteral("Historic"));
        Historic->setGeometry(QRect(1290, 690, 461, 291));
        Historic->setStyleSheet(QLatin1String("QPlainTextEdit {\n"
"    font-size: 14px;\n"
"    border: 2px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPlainTextEdit:hover {\n"
"    border-color: #43aff7;\n"
"}\n"
"\n"
"QPlainTextEdit:focus {\n"
"    border-color: #792382;\n"
"}\n"
""));
        historique = new QPushButton(Gestion_Personnel);
        historique->setObjectName(QStringLiteral("historique"));
        historique->setGeometry(QRect(720, 680, 141, 41));
        historique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        histLabel = new QLabel(Gestion_Personnel);
        histLabel->setObjectName(QStringLiteral("histLabel"));
        histLabel->setGeometry(QRect(1410, 650, 271, 41));
        histLabel->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        CloseH = new QPushButton(Gestion_Personnel);
        CloseH->setObjectName(QStringLiteral("CloseH"));
        CloseH->setGeometry(QRect(1720, 700, 31, 31));
        CloseH->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        statOFF = new QPushButton(Gestion_Personnel);
        statOFF->setObjectName(QStringLiteral("statOFF"));
        statOFF->setGeometry(QRect(1880, 170, 31, 31));
        statOFF->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        frame_2 = new QFrame(Gestion_Personnel);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(1270, 10, 491, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 10, 121, 61));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 25 px;\n"
"    color: white; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        onDark1 = new QPushButton(frame_2);
        onDark1->setObjectName(QStringLiteral("onDark1"));
        onDark1->setGeometry(QRect(270, 20, 81, 41));
        onDark1->setStyleSheet(QLatin1String("background: transparent;\n"
"background-image: url(\"images/toggle-left\");\n"
"background-repeat: no-repeat;"));
        label_3 = new QLabel(Gestion_Personnel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(910, 880, 47, 13));
        t = new QPlainTextEdit(Gestion_Personnel);
        t->setObjectName(QStringLiteral("t"));
        t->setGeometry(QRect(890, 480, 331, 161));
        t->setStyleSheet(QLatin1String("background-color: transparent;\n"
" border: 0px;"));
        t->setReadOnly(true);
        CloseAdF = new QPushButton(Gestion_Personnel);
        CloseAdF->setObjectName(QStringLiteral("CloseAdF"));
        CloseAdF->setGeometry(QRect(1190, 190, 31, 31));
        CloseAdF->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        HiddenId = new QLineEdit(Gestion_Personnel);
        HiddenId->setObjectName(QStringLiteral("HiddenId"));
        HiddenId->setGeometry(QRect(980, 910, 113, 22));
        FingerL = new QLabel(Gestion_Personnel);
        FingerL->setObjectName(QStringLiteral("FingerL"));
        FingerL->setGeometry(QRect(880, 180, 361, 471));
        FingerL->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"images/FingerIcon.png\");\n"
"	text-align: center;\n"
"	background-repeat: no-repeat;\n"
"	background-color: white;\n"
"\n"
"\n"
""));
        logo_3 = new QLabel(Gestion_Personnel);
        logo_3->setObjectName(QStringLiteral("logo_3"));
        logo_3->setGeometry(QRect(920, 0, 121, 81));
        logo_3->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/logo.png\");"));
        logo_3->setPixmap(QPixmap(QString::fromUtf8("../../../Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        label_24 = new QLabel(Gestion_Personnel);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(60, 100, 241, 49));
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
        t->raise();
        CloseAdF->raise();
        FingerL->raise();
        HiddenId->raise();
        CloseH->raise();
        widget->raise();
        histLabel->raise();
        Historic->raise();
        Background->raise();
        statOFF->raise();
        downloadPDF->raise();
        stat->raise();
        chat->raise();
        formLayoutWidget_2->raise();
        frame->raise();
        title->raise();
        label_43->raise();
        tableW->raise();
        label_44->raise();
        search->raise();
        label_45->raise();
        menu->raise();
        label_46->raise();
        label_47->raise();
        logout->raise();
        OnOffModification->raise();
        triCombo->raise();
        qrCode->raise();
        historique->raise();
        frame_2->raise();
        label_3->raise();
        logo_3->raise();
        label_24->raise();

        retranslateUi(Gestion_Personnel);

        QMetaObject::connectSlotsByName(Gestion_Personnel);
    } // setupUi

    void retranslateUi(QDialog *Gestion_Personnel)
    {
        Gestion_Personnel->setWindowTitle(QApplication::translate("Gestion_Personnel", "Dialog", Q_NULLPTR));
        downloadPDF->setText(QApplication::translate("Gestion_Personnel", "T\303\251l\303\251charger", Q_NULLPTR));
        stat->setText(QApplication::translate("Gestion_Personnel", "Statistique", Q_NULLPTR));
        chat->setText(QApplication::translate("Gestion_Personnel", "CommandesVocales", Q_NULLPTR));
        label_40->setText(QApplication::translate("Gestion_Personnel", "CIN", Q_NULLPTR));
        CIN->setPlaceholderText(QApplication::translate("Gestion_Personnel", "CIN", Q_NULLPTR));
        label_30->setText(QApplication::translate("Gestion_Personnel", "Nom", Q_NULLPTR));
        nom->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Nom", Q_NULLPTR));
        label_31->setText(QApplication::translate("Gestion_Personnel", "Pr\303\251nom", Q_NULLPTR));
        prenom->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Prenom", Q_NULLPTR));
        label_32->setText(QApplication::translate("Gestion_Personnel", "Date de naissance", Q_NULLPTR));
        label_33->setText(QApplication::translate("Gestion_Personnel", "E-mail", Q_NULLPTR));
        email->setPlaceholderText(QApplication::translate("Gestion_Personnel", "email", Q_NULLPTR));
        label_34->setText(QApplication::translate("Gestion_Personnel", "Numero telephone", Q_NULLPTR));
        numtel->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Numero de telephone", Q_NULLPTR));
        label_35->setText(QApplication::translate("Gestion_Personnel", "Sexe", Q_NULLPTR));
        H->setText(QApplication::translate("Gestion_Personnel", "Homme", Q_NULLPTR));
        F->setText(QApplication::translate("Gestion_Personnel", "Femme", Q_NULLPTR));
        label_36->setText(QApplication::translate("Gestion_Personnel", "Adresse", Q_NULLPTR));
        adresse->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Adresse", Q_NULLPTR));
        label_37->setText(QApplication::translate("Gestion_Personnel", "Salaire", Q_NULLPTR));
        salaire->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Salaire", Q_NULLPTR));
        label_38->setText(QApplication::translate("Gestion_Personnel", "Role", Q_NULLPTR));
        Role->clear();
        Role->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Gestion_Personnel", "Employee", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Gestion_Personnels", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Gestion_Oeuvres", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Gestion_Participants", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Gestion_Charites", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Gestion_Evenements", Q_NULLPTR)
        );
        label_39->setText(QString());
        scan_Face->setText(QApplication::translate("Gestion_Personnel", "Prendre une photo pour la reconnaissnace faciale", Q_NULLPTR));
        Add_Finger->setText(QApplication::translate("Gestion_Personnel", "   Ajouter une empreinte", Q_NULLPTR));
        ajouter->setText(QApplication::translate("Gestion_Personnel", "Ajouter", Q_NULLPTR));
        Annuler->setText(QApplication::translate("Gestion_Personnel", "Annuler", Q_NULLPTR));
        scan_CIN->setText(QApplication::translate("Gestion_Personnel", "Scanner votre cin", Q_NULLPTR));
        asc->setText(QApplication::translate("Gestion_Personnel", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("Gestion_Personnel", "desc", Q_NULLPTR));
        refresh->setText(QString());
        title->setText(QApplication::translate("Gestion_Personnel", "Gestion des personnels", Q_NULLPTR));
        label_43->setText(QString());
        label_44->setText(QString());
        search->setPlaceholderText(QApplication::translate("Gestion_Personnel", "Rechercher..", Q_NULLPTR));
        Background->setText(QString());
        label_45->setText(QString());
        menu->setText(QApplication::translate("Gestion_Personnel", "MENU", Q_NULLPTR));
        label_46->setText(QString());
        label_47->setText(QString());
        logout->setText(QApplication::translate("Gestion_Personnel", "Se deconnecter", Q_NULLPTR));
        OnOffModification->setText(QApplication::translate("Gestion_Personnel", "Cocher pour Activer la Modification", Q_NULLPTR));
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("Gestion_Personnel", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Nom", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Date de naissance", Q_NULLPTR)
         << QApplication::translate("Gestion_Personnel", "Salaire", Q_NULLPTR)
        );
        qrCode->setText(QApplication::translate("Gestion_Personnel", "GenererQrCode", Q_NULLPTR));
        historique->setText(QApplication::translate("Gestion_Personnel", "Historique", Q_NULLPTR));
        histLabel->setText(QApplication::translate("Gestion_Personnel", "Historique", Q_NULLPTR));
        CloseH->setText(QString());
        statOFF->setText(QString());
        label_2->setText(QApplication::translate("Gestion_Personnel", "Changer le mode:", Q_NULLPTR));
        onDark1->setText(QString());
        label_3->setText(QString());
        CloseAdF->setText(QString());
        FingerL->setText(QString());
        logo_3->setText(QString());
        label_24->setText(QApplication::translate("Gestion_Personnel", "Ajouter un Employ\303\251e", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Gestion_Personnel: public Ui_Gestion_Personnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_PERSONNEL_H
