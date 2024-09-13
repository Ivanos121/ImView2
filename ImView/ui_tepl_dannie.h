/********************************************************************************
** Form generated from reading UI file 'tepl_dannie.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEPL_DANNIE_H
#define UI_TEPL_DANNIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tepl_dannie
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Tepl_dannie)
    {
        if (Tepl_dannie->objectName().isEmpty())
            Tepl_dannie->setObjectName(QString::fromUtf8("Tepl_dannie"));
        Tepl_dannie->resize(961, 744);
        gridLayout = new QGridLayout(Tepl_dannie);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(Tepl_dannie);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);

        gridLayout->addWidget(tableWidget, 0, 0, 2, 1);


        retranslateUi(Tepl_dannie);

        QMetaObject::connectSlotsByName(Tepl_dannie);
    } // setupUi

    void retranslateUi(QWidget *Tepl_dannie)
    {
        Tepl_dannie->setWindowTitle(QCoreApplication::translate("Tepl_dannie", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tepl_dannie: public Ui_Tepl_dannie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEPL_DANNIE_H
