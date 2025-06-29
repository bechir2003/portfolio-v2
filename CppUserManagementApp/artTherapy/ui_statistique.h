/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Statistique
{
public:
    QGraphicsView *graphicsView;
    QLabel *label_8;

    void setupUi(QDialog *Statistique)
    {
        if (Statistique->objectName().isEmpty())
            Statistique->setObjectName(QStringLiteral("Statistique"));
        Statistique->resize(940, 606);
        graphicsView = new QGraphicsView(Statistique);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(-5, 1, 991, 611));
        label_8 = new QLabel(Statistique);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 121, 81));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../../PROJET C++/logo sghayer .png")));

        retranslateUi(Statistique);

        QMetaObject::connectSlotsByName(Statistique);
    } // setupUi

    void retranslateUi(QDialog *Statistique)
    {
        Statistique->setWindowTitle(QApplication::translate("Statistique", "Dialog", Q_NULLPTR));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Statistique: public Ui_Statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
