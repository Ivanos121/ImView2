/********************************************************************************
** Form generated from reading UI file 'ostat_resurs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSTAT_RESURS_H
#define UI_OSTAT_RESURS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_Ostat_resurs
{
public:
    QGridLayout *gridLayout;
    Plot *plots;

    void setupUi(QWidget *Ostat_resurs)
    {
        if (Ostat_resurs->objectName().isEmpty())
            Ostat_resurs->setObjectName(QString::fromUtf8("Ostat_resurs"));
        Ostat_resurs->resize(870, 678);
        gridLayout = new QGridLayout(Ostat_resurs);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plots = new Plot(Ostat_resurs);
        plots->setObjectName(QString::fromUtf8("plots"));

        gridLayout->addWidget(plots, 0, 0, 1, 1);


        retranslateUi(Ostat_resurs);

        QMetaObject::connectSlotsByName(Ostat_resurs);
    } // setupUi

    void retranslateUi(QWidget *Ostat_resurs)
    {
        Ostat_resurs->setWindowTitle(QCoreApplication::translate("Ostat_resurs", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ostat_resurs: public Ui_Ostat_resurs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSTAT_RESURS_H
