/********************************************************************************
** Form generated from reading UI file 'modif.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIF_H
#define UI_MODIF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modif
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *ide;
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
    QPushButton *modifier;
    QLabel *label_2;

    void setupUi(QDialog *modif)
    {
        if (modif->objectName().isEmpty())
            modif->setObjectName(QStringLiteral("modif"));
        modif->resize(510, 688);
        formLayoutWidget = new QWidget(modif);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(80, 20, 341, 591));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ide = new QLineEdit(formLayoutWidget);
        ide->setObjectName(QStringLiteral("ide"));
        ide->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(0, QFormLayout::FieldRole, ide);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

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

        formLayout->setWidget(1, QFormLayout::FieldRole, nomevent);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

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

        formLayout->setWidget(2, QFormLayout::FieldRole, lieu);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

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

        formLayout->setWidget(3, QFormLayout::FieldRole, datedeb);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

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

        formLayout->setWidget(4, QFormLayout::FieldRole, datefin);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

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

        formLayout->setWidget(5, QFormLayout::FieldRole, description);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

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

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 18px;\n"
"    color: #792382; /* Couleur du texte */\n"
"    font-weight: bold; /* Gras */\n"
"    /* Ajoutez d'autres styles selon vos besoins */\n"
"}\n"
""));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

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

        formLayout->setWidget(7, QFormLayout::FieldRole, capacite);

        modifier = new QPushButton(formLayoutWidget);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"    display: inline-block;\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    cursor: pointer;\n"
"    border: 2px solid #43aff7;\n"
"    color: #43aff7;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-image: url(\"C:/Users/Kinza/Documents/projet cpp/edit.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
"    padding-left: 30px; /* Ajustez ceci selon la taille de votre image */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #792382;\n"
"    color: #ffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    transform: translateY(1px);\n"
"}"));

        formLayout->setWidget(8, QFormLayout::FieldRole, modifier);

        label_2 = new QLabel(modif);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-30, -600, 1701, 911));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/bechi/Downloads/7492038.jpg")));
        label_2->raise();
        formLayoutWidget->raise();

        retranslateUi(modif);

        QMetaObject::connectSlotsByName(modif);
    } // setupUi

    void retranslateUi(QDialog *modif)
    {
        modif->setWindowTitle(QApplication::translate("modif", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("modif", "id_event", Q_NULLPTR));
        ide->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("modif", "Nom \303\251v\303\250nement", Q_NULLPTR));
        nomevent->setPlaceholderText(QApplication::translate("modif", "entrer le nom ", Q_NULLPTR));
        label_6->setText(QApplication::translate("modif", "Lieu", Q_NULLPTR));
        lieu->setPlaceholderText(QApplication::translate("modif", "entrer le lieu", Q_NULLPTR));
        label_7->setText(QApplication::translate("modif", "Date d\303\251but", Q_NULLPTR));
        label_8->setText(QApplication::translate("modif", "Date fin", Q_NULLPTR));
        label_5->setText(QApplication::translate("modif", "Description", Q_NULLPTR));
        description->setPlaceholderText(QApplication::translate("modif", "d\303\251crire l'\303\251v\303\250nement", Q_NULLPTR));
        label_9->setText(QApplication::translate("modif", "Statut", Q_NULLPTR));
        label_10->setText(QApplication::translate("modif", "Capacit\303\251", Q_NULLPTR));
        capacite->setPlaceholderText(QApplication::translate("modif", "entrer la capacit\303\251", Q_NULLPTR));
        modifier->setText(QApplication::translate("modif", "Modifier", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modif: public Ui_modif {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIF_H
