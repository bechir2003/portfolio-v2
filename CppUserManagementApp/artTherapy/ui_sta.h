/********************************************************************************
** Form generated from reading UI file 'sta.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STA_H
#define UI_STA_H

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

class Ui_sta
{
public:
    QGraphicsView *graph;
    QLabel *label;
    QPushButton *retourner;

    void setupUi(QDialog *sta)
    {
        if (sta->objectName().isEmpty())
            sta->setObjectName(QStringLiteral("sta"));
        sta->resize(1252, 628);
        graph = new QGraphicsView(sta);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(-10, 0, 1301, 761));
        label = new QLabel(sta);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 181, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../423062592_412565247809359_4122753196054595283_n.png")));
        retourner = new QPushButton(sta);
        retourner->setObjectName(QStringLiteral("retourner"));
        retourner->setGeometry(QRect(1120, 10, 101, 41));
        retourner->setStyleSheet(QLatin1String("QPushButton {\n"
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

        retranslateUi(sta);

        QMetaObject::connectSlotsByName(sta);
    } // setupUi

    void retranslateUi(QDialog *sta)
    {
        sta->setWindowTitle(QApplication::translate("sta", "Dialog", Q_NULLPTR));
        label->setText(QString());
        retourner->setText(QApplication::translate("sta", "retourner", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sta: public Ui_sta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STA_H
