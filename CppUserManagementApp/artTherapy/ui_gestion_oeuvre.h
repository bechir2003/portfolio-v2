/********************************************************************************
** Form generated from reading UI file 'gestion_oeuvre.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_OEUVRE_H
#define UI_GESTION_OEUVRE_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_oeuvre
{
public:
    QPushButton *qrcode;
    QPushButton *logout;
    QFrame *frame;
    QRadioButton *asc;
    QRadioButton *desc;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QLineEdit *nom;
    QLabel *label_11;
    QComboBox *type;
    QLabel *label_12;
    QLineEdit *prix;
    QLabel *label_18;
    QLabel *label_16;
    QComboBox *evenement;
    QPushButton *ajouter;
    QPushButton *Annuler;
    QPushButton *historique;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_20;
    QTextEdit *textEdit;
    QLabel *label_22;
    QLabel *label_21;
    QPushButton *downloadPDF;
    QLabel *label_5;
    QLabel *label_23;
    QLineEdit *search;
    QTableWidget *tableW;
    QLabel *label;
    QComboBox *triCombo;
    QPushButton *stat;
    QWidget *widget;
    QPushButton *statOFF;
    QPushButton *refresh;
    QPushButton *Menu;
    QPushButton *CloseH;
    QLabel *label_24;

    void setupUi(QDialog *gestion_oeuvre)
    {
        if (gestion_oeuvre->objectName().isEmpty())
            gestion_oeuvre->setObjectName(QStringLiteral("gestion_oeuvre"));
        gestion_oeuvre->resize(1911, 1010);
        qrcode = new QPushButton(gestion_oeuvre);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(640, 670, 111, 41));
        qrcode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        logout = new QPushButton(gestion_oeuvre);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(40, 730, 171, 41));
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
        frame = new QFrame(gestion_oeuvre);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1320, 110, 51, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        asc = new QRadioButton(frame);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(0, 0, 97, 20));
        asc->setChecked(true);
        desc = new QRadioButton(frame);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(0, 20, 97, 20));
        formLayoutWidget_2 = new QWidget(gestion_oeuvre);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 220, 375, 327));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

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

        formLayout_2->setWidget(1, QFormLayout::FieldRole, nom);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_11);

        type = new QComboBox(formLayoutWidget_2);
        type->setObjectName(QStringLiteral("type"));
        type->setStyleSheet(QLatin1String("    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, type);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_12);

        prix = new QLineEdit(formLayoutWidget_2);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout_2->setWidget(5, QFormLayout::FieldRole, prix);

        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setPixmap(QPixmap(QString::fromUtf8("C:/Users/AppData/Local/Temp/b6651d8d-1e9f-45ec-8183-973f3ea7bf13_interface \303\240 bechir.zip.f13/PROJET C++/back.jpg")));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, label_18);

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

        evenement = new QComboBox(formLayoutWidget_2);
        evenement->setObjectName(QStringLiteral("evenement"));
        evenement->setStyleSheet(QLatin1String("    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, evenement);

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

        formLayout_2->setWidget(8, QFormLayout::FieldRole, ajouter);

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
""));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, Annuler);

        historique = new QPushButton(gestion_oeuvre);
        historique->setObjectName(QStringLiteral("historique"));
        historique->setGeometry(QRect(790, 670, 111, 41));
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
        label_3 = new QLabel(gestion_oeuvre);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 70, 271, 41));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 22px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));
        label_2 = new QLabel(gestion_oeuvre);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(780, 0, 121, 81));
        label_2->setStyleSheet(QLatin1String("\n"
"    background-image: url(\"images/logo.png\");"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/Documents/interface \303\240 bechir/interface \342\224\234\303\241 bechir/images/logo.png")));
        label_20 = new QLabel(gestion_oeuvre);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1120, 460, 61, 31));
        label_20->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/AppData/Local/Temp/Downloads/edit.svg")));
        textEdit = new QTextEdit(gestion_oeuvre);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(1480, 170, 411, 481));
        label_22 = new QLabel(gestion_oeuvre);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(1120, 500, 61, 31));
        label_22->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/AppData/Local/Temp/Downloads/edit.svg")));
        label_21 = new QLabel(gestion_oeuvre);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(1120, 500, 61, 31));
        label_21->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/AppData/Local/Temp/Downloads/edit.svg")));
        downloadPDF = new QPushButton(gestion_oeuvre);
        downloadPDF->setObjectName(QStringLiteral("downloadPDF"));
        downloadPDF->setGeometry(QRect(470, 670, 131, 41));
        downloadPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_5 = new QLabel(gestion_oeuvre);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 330, 61, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/AppData/Local/Temp/Downloads/search (1).svg")));
        label_23 = new QLabel(gestion_oeuvre);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(710, 330, 61, 41));
        label_23->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/AppData/Local/Temp/Downloads/search (1).svg")));
        search = new QLineEdit(gestion_oeuvre);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(540, 120, 531, 41));
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
"}\n"
""));
        tableW = new QTableWidget(gestion_oeuvre);
        tableW->setObjectName(QStringLiteral("tableW"));
        tableW->setGeometry(QRect(360, 170, 1061, 481));
        label = new QLabel(gestion_oeuvre);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, 0, 2631, 1041));
        label->setStyleSheet(QStringLiteral("background-image: url(\"images/back.jpg\");"));
        triCombo = new QComboBox(gestion_oeuvre);
        triCombo->setObjectName(QStringLiteral("triCombo"));
        triCombo->setGeometry(QRect(1130, 110, 181, 41));
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
        stat = new QPushButton(gestion_oeuvre);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(360, 120, 111, 41));
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
        widget = new QWidget(gestion_oeuvre);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(340, 160, 1551, 521));
        statOFF = new QPushButton(gestion_oeuvre);
        statOFF->setObjectName(QStringLiteral("statOFF"));
        statOFF->setGeometry(QRect(1850, 140, 31, 31));
        statOFF->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        refresh = new QPushButton(gestion_oeuvre);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(1370, 180, 41, 41));
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
        Menu = new QPushButton(gestion_oeuvre);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(10, 890, 145, 34));
        Menu->setStyleSheet(QLatin1String("QPushButton {\n"
"    /*padding: 10px 20px;*/\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #792382;\n"
"    color: #792382;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43aff7;\n"
"}\n"
"\n"
"\n"
""));
        CloseH = new QPushButton(gestion_oeuvre);
        CloseH->setObjectName(QStringLiteral("CloseH"));
        CloseH->setGeometry(QRect(1860, 140, 31, 31));
        CloseH->setStyleSheet(QStringLiteral(" background-image: url(\"images/x.svg\");"));
        label_24 = new QLabel(gestion_oeuvre);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(80, 150, 221, 51));
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
        CloseH->raise();
        textEdit->raise();
        Menu->raise();
        statOFF->raise();
        widget->raise();
        label->raise();
        qrcode->raise();
        logout->raise();
        frame->raise();
        formLayoutWidget_2->raise();
        historique->raise();
        label_3->raise();
        label_20->raise();
        label_22->raise();
        label_21->raise();
        downloadPDF->raise();
        label_5->raise();
        label_23->raise();
        search->raise();
        tableW->raise();
        triCombo->raise();
        label_2->raise();
        stat->raise();
        refresh->raise();
        label_24->raise();

        retranslateUi(gestion_oeuvre);

        QMetaObject::connectSlotsByName(gestion_oeuvre);
    } // setupUi

    void retranslateUi(QDialog *gestion_oeuvre)
    {
        gestion_oeuvre->setWindowTitle(QApplication::translate("gestion_oeuvre", "Dialog", Q_NULLPTR));
        qrcode->setText(QApplication::translate("gestion_oeuvre", "Qr code", Q_NULLPTR));
        logout->setText(QApplication::translate("gestion_oeuvre", "Se deconnecter", Q_NULLPTR));
        asc->setText(QApplication::translate("gestion_oeuvre", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("gestion_oeuvre", "desc", Q_NULLPTR));
        label_10->setText(QApplication::translate("gestion_oeuvre", "Nom Artiste", Q_NULLPTR));
        nom->setPlaceholderText(QApplication::translate("gestion_oeuvre", "NomArtiste", Q_NULLPTR));
        label_11->setText(QApplication::translate("gestion_oeuvre", "type", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("gestion_oeuvre", "Peinture a l'huile", Q_NULLPTR)
         << QApplication::translate("gestion_oeuvre", "Peinture a l'eau", Q_NULLPTR)
         << QApplication::translate("gestion_oeuvre", "Photographe", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("gestion_oeuvre", "Prix", Q_NULLPTR));
        prix->setPlaceholderText(QApplication::translate("gestion_oeuvre", "Prix", Q_NULLPTR));
        label_18->setText(QString());
        label_16->setText(QApplication::translate("gestion_oeuvre", "Evenement", Q_NULLPTR));
        evenement->clear();
        evenement->insertItems(0, QStringList()
         << QString()
        );
        ajouter->setText(QApplication::translate("gestion_oeuvre", "Ajouter", Q_NULLPTR));
        Annuler->setText(QApplication::translate("gestion_oeuvre", "Annuler", Q_NULLPTR));
        historique->setText(QApplication::translate("gestion_oeuvre", "Historique", Q_NULLPTR));
        label_3->setText(QApplication::translate("gestion_oeuvre", "Gestion des Oeuvres", Q_NULLPTR));
        label_2->setText(QString());
        label_20->setText(QString());
        label_22->setText(QString());
        label_21->setText(QString());
        downloadPDF->setText(QApplication::translate("gestion_oeuvre", "T\303\251l\303\251charger", Q_NULLPTR));
        label_5->setText(QString());
        label_23->setText(QString());
        search->setPlaceholderText(QApplication::translate("gestion_oeuvre", "Rechercher..", Q_NULLPTR));
        label->setText(QString());
        triCombo->clear();
        triCombo->insertItems(0, QStringList()
         << QApplication::translate("gestion_oeuvre", "Trier Selon :", Q_NULLPTR)
         << QApplication::translate("gestion_oeuvre", "Prix", Q_NULLPTR)
         << QApplication::translate("gestion_oeuvre", "Nom", Q_NULLPTR)
         << QApplication::translate("gestion_oeuvre", "Etat", Q_NULLPTR)
        );
        stat->setText(QApplication::translate("gestion_oeuvre", "Statistique", Q_NULLPTR));
        statOFF->setText(QString());
        refresh->setText(QString());
        Menu->setText(QApplication::translate("gestion_oeuvre", "Menu", Q_NULLPTR));
        CloseH->setText(QString());
        label_24->setText(QApplication::translate("gestion_oeuvre", "Ajouter un Oeuvre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_oeuvre: public Ui_gestion_oeuvre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_OEUVRE_H
