/********************************************************************************
** Form generated from reading UI file 'tepl_identf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEPL_IDENTF_H
#define UI_TEPL_IDENTF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_Tepl_identf
{
public:
    QGridLayout *gridLayout;
    Plot *plot;

    void setupUi(QWidget *Tepl_identf)
    {
        if (Tepl_identf->objectName().isEmpty())
            Tepl_identf->setObjectName(QString::fromUtf8("Tepl_identf"));
        Tepl_identf->resize(828, 680);
        gridLayout = new QGridLayout(Tepl_identf);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plot = new Plot(Tepl_identf);
        plot->setObjectName(QString::fromUtf8("plot"));

        gridLayout->addWidget(plot, 0, 0, 1, 1);


        retranslateUi(Tepl_identf);

        QMetaObject::connectSlotsByName(Tepl_identf);
    } // setupUi

    void retranslateUi(QWidget *Tepl_identf)
    {
        Tepl_identf->setWindowTitle(QCoreApplication::translate("Tepl_identf", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tepl_identf: public Ui_Tepl_identf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEPL_IDENTF_H
