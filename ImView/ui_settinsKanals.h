/********************************************************************************
** Form generated from reading UI file 'settinsKanals.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINSKANALS_H
#define UI_SETTINSKANALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_settinsKanals
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QTableView *tableView_2;
    QPushButton *pushButton;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *settinsKanals)
    {
        if (settinsKanals->objectName().isEmpty())
            settinsKanals->setObjectName(QString::fromUtf8("settinsKanals"));
        settinsKanals->resize(705, 621);
        gridLayout = new QGridLayout(settinsKanals);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(settinsKanals);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        tableView_2 = new QTableView(settinsKanals);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout->addWidget(tableView_2, 0, 3, 1, 1);

        pushButton = new QPushButton(settinsKanals);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        tableView = new QTableView(settinsKanals);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        retranslateUi(settinsKanals);

        QMetaObject::connectSlotsByName(settinsKanals);
    } // setupUi

    void retranslateUi(QDialog *settinsKanals)
    {
        settinsKanals->setWindowTitle(QCoreApplication::translate("settinsKanals", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("settinsKanals", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("settinsKanals", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settinsKanals: public Ui_settinsKanals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINSKANALS_H
