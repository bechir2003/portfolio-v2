/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLineEdit *nom;
    QLabel *label_18;
    QLabel *label_15;
    QRadioButton *V;
    QRadioButton *NV;
    QPushButton *Modifier;
    QPushButton *Annuler;
    QLineEdit *prix;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QComboBox *evenement;
    QLabel *label_16;
    QComboBox *type;
    QLabel *label_13;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(607, 651);
        formLayoutWidget_2 = new QWidget(Dialog);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(140, 160, 327, 381));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
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

        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setPixmap(QPixmap(QString::fromUtf8("C:/Users/AppData/Local/Temp/b6651d8d-1e9f-45ec-8183-973f3ea7bf13_interface \303\240 bechir.zip.f13/PROJET C++/back.jpg")));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, label_18);

        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_15);

        V = new QRadioButton(formLayoutWidget_2);
        V->setObjectName(QStringLiteral("V"));
        V->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        V->setChecked(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, V);

        NV = new QRadioButton(formLayoutWidget_2);
        NV->setObjectName(QStringLiteral("NV"));
        NV->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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

        formLayout_2->setWidget(8, QFormLayout::FieldRole, NV);

        Modifier = new QPushButton(formLayoutWidget_2);
        Modifier->setObjectName(QStringLiteral("Modifier"));
        Modifier->setStyleSheet(QLatin1String("QPushButton {\n"
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
""));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, Modifier);

        Annuler = new QPushButton(formLayoutWidget_2);
        Annuler->setObjectName(QStringLiteral("Annuler"));
        Annuler->setStyleSheet(QLatin1String("QPushButton {\n"
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

        formLayout_2->setWidget(11, QFormLayout::FieldRole, Annuler);

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

        evenement = new QComboBox(formLayoutWidget_2);
        evenement->setObjectName(QStringLiteral("evenement"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, evenement);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_16);

        type = new QComboBox(formLayoutWidget_2);
        type->setObjectName(QStringLiteral("type"));
        type->setStyleSheet(QLatin1String("    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, type);

        label_13 = new QLabel(Dialog);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(220, 70, 191, 33));
        label_13->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        nom->setPlaceholderText(QApplication::translate("Dialog", "NomArtiste", Q_NULLPTR));
        label_18->setText(QString());
        label_15->setText(QApplication::translate("Dialog", "Etat", Q_NULLPTR));
        V->setText(QApplication::translate("Dialog", "Disponible", Q_NULLPTR));
        NV->setText(QApplication::translate("Dialog", "Non,disponible", Q_NULLPTR));
        Modifier->setText(QApplication::translate("Dialog", "Modifier", Q_NULLPTR));
        Annuler->setText(QApplication::translate("Dialog", "Annuler", Q_NULLPTR));
        prix->setPlaceholderText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_12->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_11->setText(QApplication::translate("Dialog", "type", Q_NULLPTR));
        label_10->setText(QApplication::translate("Dialog", "Nom Artiste", Q_NULLPTR));
        evenement->clear();
        evenement->insertItems(0, QStringList()
         << QString()
        );
        label_16->setText(QApplication::translate("Dialog", "Evenement", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Dialog", "Peinture a l'huile", Q_NULLPTR)
         << QApplication::translate("Dialog", "Peinture a l'eau", Q_NULLPTR)
         << QApplication::translate("Dialog", "Photographe", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("Dialog", "Modifier une Oeuvre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
