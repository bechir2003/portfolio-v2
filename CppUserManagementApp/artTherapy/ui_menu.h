/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *GP;
    QLabel *label;
    QPushButton *GC;
    QPushButton *GE;
    QPushButton *GO;
    QLabel *label_2;
    QPushButton *GPA;
    QLabel *label_3;
    QPushButton *GHA;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(1283, 654);
        GP = new QPushButton(Menu);
        GP->setObjectName(QStringLiteral("GP"));
        GP->setGeometry(QRect(1050, 10, 191, 61));
        GP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        label = new QLabel(Menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1341, 661));
        label->setStyleSheet(QLatin1String("background-image: url(\"D:/ESPRIT/c++/Projet/ProjetC++/images/menu.png\");\n"
""));
        GC = new QPushButton(Menu);
        GC->setObjectName(QStringLiteral("GC"));
        GC->setGeometry(QRect(370, 110, 171, 61));
        GC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        GE = new QPushButton(Menu);
        GE->setObjectName(QStringLiteral("GE"));
        GE->setGeometry(QRect(150, 80, 211, 61));
        GE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        GO = new QPushButton(Menu);
        GO->setObjectName(QStringLiteral("GO"));
        GO->setGeometry(QRect(10, 20, 171, 61));
        GO->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(640, 100, 171, 121));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/423062592_412565247809359_4122753196054595283_n.png")));
        GPA = new QPushButton(Menu);
        GPA->setObjectName(QStringLiteral("GPA"));
        GPA->setGeometry(QRect(840, 70, 201, 61));
        GPA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        label_3 = new QLabel(Menu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 20, 191, 51));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #800080; /* Couleur du texte violette */\n"
"    font-size: 20px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    background-color: #f0f0f0; /* Couleur de fond */\n"
"    border: 2px solid #800080; /* Bordure violette */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px; /* Marge int\303\251rieure */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol (bleu clair) */\n"
"    border-color: #4B0082; /* Couleur de la bordure au survol */\n"
"}"));
        GHA = new QPushButton(Menu);
        GHA->setObjectName(QStringLiteral("GHA"));
        GHA->setGeometry(QRect(550, 140, 361, 61));
        GHA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: none; /* Supprimer la bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 10px 24px; /* Marge int\303\251rieure */\n"
"    text-align: center; /* Alignement du texte */\n"
"    text-decoration: none; /* Supprimer la d\303\251coration du texte */\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    border-radius: 10px; /* Arrondir les coins */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #aa00ff; /* Couleur de fond au survol */\n"
"}"));
        label->raise();
        GP->raise();
        GC->raise();
        GE->raise();
        GO->raise();
        label_2->raise();
        GPA->raise();
        label_3->raise();
        GHA->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", Q_NULLPTR));
        GP->setText(QApplication::translate("Menu", "Gestion personnels", Q_NULLPTR));
        label->setText(QString());
        GC->setText(QApplication::translate("Menu", "Gestion charit\303\251s", Q_NULLPTR));
        GE->setText(QApplication::translate("Menu", "Gestion \303\251v\303\250nements", Q_NULLPTR));
        GO->setText(QApplication::translate("Menu", "Gestion oeuvres", Q_NULLPTR));
        label_2->setText(QString());
        GPA->setText(QApplication::translate("Menu", "Gestion participants", Q_NULLPTR));
        label_3->setText(QApplication::translate("Menu", "Page d'acceuil", Q_NULLPTR));
        GHA->setText(QApplication::translate("Menu", "Gestion Historiques d'achats / Participation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
