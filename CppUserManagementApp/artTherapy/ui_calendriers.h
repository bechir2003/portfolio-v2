/********************************************************************************
** Form generated from reading UI file 'calendriers.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDRIERS_H
#define UI_CALENDRIERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_calendriers
{
public:
    QCalendarWidget *calendarWidget;
    QTableWidget *tableWidget;

    void setupUi(QDialog *calendriers)
    {
        if (calendriers->objectName().isEmpty())
            calendriers->setObjectName(QStringLiteral("calendriers"));
        calendriers->resize(1474, 729);
        calendarWidget = new QCalendarWidget(calendriers);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(40, 30, 651, 471));
        calendarWidget->setStyleSheet(QString::fromUtf8("/* Style global du widget Calendrier */\n"
"QCalendarWidget {\n"
"    background-color: #792382; /* Couleur de fond */\n"
"    border: 2px solid #792382; /* Bordure */\n"
"    color: white; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style pour les jours de la semaine */\n"
"QCalendarWidget QHeaderView {\n"
"    background-color: #792382; /* Couleur de fond de l'en-t\303\252te */\n"
"    color: #792382; /* Couleur du texte de l'en-t\303\252te */\n"
"    border: none; /* Supprimer la bordure */\n"
"}\n"
"\n"
"/* Style pour les jours du calendrier */\n"
"QCalendarWidget QAbstractItemView {\n"
"    selection-background-color: #ff69b4; /* Couleur de fond de la s\303\251lection */\n"
"    color: #792382; /* Couleur du texte des jours */\n"
"}\n"
"\n"
"/* Style pour les boutons \"Pr\303\251c\303\251dent\" et \"Suivant\" */\n"
"QCalendarWidget QPushButton {\n"
"    background-color: #43aff7; /* Couleur de fond */\n"
"    border: 1px solid #43aff7; /* Bordure */\n"
"    color: white; /* Couleur du texte */\n"
"    paddin"
                        "g: 5px; /* Espacement int\303\251rieur */\n"
"}\n"
"\n"
"/* Style pour les boutons \"Pr\303\251c\303\251dent\" et \"Suivant\" au survol */\n"
"QCalendarWidget QPushButton:hover {\n"
"    background-color: #43aff7; /* Couleur de fond */\n"
"    border: 1px solid #43aff7; /* Bordure */\n"
"    color: white; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style pour les boutons \"Pr\303\251c\303\251dent\" et \"Suivant\" press\303\251s */\n"
"QCalendarWidget QPushButton:pressed {\n"
"    background-color: #43aff7; /* Couleur de fond */\n"
"    border: 1px solid #43aff7; /* Bordure */\n"
"    color: #43aff7; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style pour le s\303\251lecteur de date */\n"
"QCalendarWidget QAbstractItemView:enabled:selected {\n"
"    background-color: #ff69b4; /* Couleur de fond de la date s\303\251lectionn\303\251e */\n"
"    color: #792382; /* Couleur du texte de la date s\303\251lectionn\303\251e */\n"
"}"));
        tableWidget = new QTableWidget(calendriers);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(750, 40, 531, 441));

        retranslateUi(calendriers);

        QMetaObject::connectSlotsByName(calendriers);
    } // setupUi

    void retranslateUi(QDialog *calendriers)
    {
        calendriers->setWindowTitle(QApplication::translate("calendriers", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class calendriers: public Ui_calendriers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDRIERS_H
