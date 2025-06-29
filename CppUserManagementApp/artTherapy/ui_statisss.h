/********************************************************************************
** Form generated from reading UI file 'statisss.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISSS_H
#define UI_STATISSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Statisss
{
public:
    QPushButton *batons;
    QPushButton *retourner;
    QPushButton *pushButton;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QPushButton *cercle;
    QLabel *label;
    QPushButton *retourner_2;
    QPushButton *batons_2;
    QPushButton *cercle_2;

    void setupUi(QDialog *Statisss)
    {
        if (Statisss->objectName().isEmpty())
            Statisss->setObjectName(QStringLiteral("Statisss"));
        Statisss->resize(1378, 723);
        batons = new QPushButton(Statisss);
        batons->setObjectName(QStringLiteral("batons"));
        batons->setGeometry(QRect(1400, 480, 31, 31));
        batons->setStyleSheet(QLatin1String("QPushButton {\n"
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
"    background-image: url(\"C:/Users/Kinza/Documents/evenement/bar-chart-2 (1).svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
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
        retourner = new QPushButton(Statisss);
        retourner->setObjectName(QStringLiteral("retourner"));
        retourner->setGeometry(QRect(1500, 480, 101, 41));
        retourner->setStyleSheet(QLatin1String("QPushButton {\n"
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
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
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
        pushButton = new QPushButton(Statisss);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1710, 527, 101, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
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
        label_2 = new QLabel(Statisss);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1580, 470, 221, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../423062592_412565247809359_4122753196054595283_n.png")));
        graphicsView = new QGraphicsView(Statisss);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(-10, 0, 1381, 721));
        graphicsView->setStyleSheet(QStringLiteral(""));
        cercle = new QPushButton(Statisss);
        cercle->setObjectName(QStringLiteral("cercle"));
        cercle->setGeometry(QRect(1450, 480, 31, 31));
        cercle->setStyleSheet(QLatin1String("QPushButton {\n"
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
"    background-image: url(\"C:/Users/Kinza/Documents/evenement/pie-chart.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    background-size: contain;\n"
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
        label = new QLabel(Statisss);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1190, 10, 441, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../423062592_412565247809359_4122753196054595283_n.png")));
        retourner_2 = new QPushButton(Statisss);
        retourner_2->setObjectName(QStringLiteral("retourner_2"));
        retourner_2->setGeometry(QRect(1110, 20, 101, 41));
        retourner_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #43aff7;\n"
"    color: #43aff7;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
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
        batons_2 = new QPushButton(Statisss);
        batons_2->setObjectName(QStringLiteral("batons_2"));
        batons_2->setGeometry(QRect(1010, 20, 31, 31));
        batons_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #43aff7;\n"
"    color: #43aff7;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-image: url(\"images/bar-chart.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
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
        cercle_2 = new QPushButton(Statisss);
        cercle_2->setObjectName(QStringLiteral("cercle_2"));
        cercle_2->setGeometry(QRect(1060, 20, 31, 31));
        cercle_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    border: 2px solid #43aff7;\n"
"    color: #43aff7;\n"
"    border-radius: 5px;\n"
"    transition: background-color 0.3s, color 0.3s;\n"
"    background-image: url(\"images/pie-chart.svg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
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

        retranslateUi(Statisss);

        QMetaObject::connectSlotsByName(Statisss);
    } // setupUi

    void retranslateUi(QDialog *Statisss)
    {
        Statisss->setWindowTitle(QApplication::translate("Statisss", "Dialog", Q_NULLPTR));
        batons->setText(QString());
        retourner->setText(QApplication::translate("Statisss", "retourner", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Statisss", "retourner", Q_NULLPTR));
        label_2->setText(QString());
        cercle->setText(QString());
        label->setText(QString());
        retourner_2->setText(QApplication::translate("Statisss", "retourner", Q_NULLPTR));
        batons_2->setText(QString());
        cercle_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Statisss: public Ui_Statisss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISSS_H
