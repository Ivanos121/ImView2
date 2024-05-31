/********************************************************************************
** Form generated from reading UI file 'settingscanals.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSCANALS_H
#define UI_SETTINGSCANALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsCanals
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *SettingsCanals)
    {
        if (SettingsCanals->objectName().isEmpty())
            SettingsCanals->setObjectName(QString::fromUtf8("SettingsCanals"));
        SettingsCanals->resize(999, 601);
        SettingsCanals->setModal(true);
        gridLayout = new QGridLayout(SettingsCanals);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(SettingsCanals);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(150, 0));
        widget->setMaximumSize(QSize(150, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        gridLayout->addWidget(widget, 1, 1, 2, 1);

        pushButton_2 = new QPushButton(SettingsCanals);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton = new QPushButton(SettingsCanals);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        tableWidget_2 = new QTableWidget(SettingsCanals);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableWidget_2, 1, 2, 1, 1);

        tableWidget = new QTableWidget(SettingsCanals);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        label = new QLabel(SettingsCanals);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(SettingsCanals);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);


        retranslateUi(SettingsCanals);

        QMetaObject::connectSlotsByName(SettingsCanals);
    } // setupUi

    void retranslateUi(QDialog *SettingsCanals)
    {
        SettingsCanals->setWindowTitle(QCoreApplication::translate("SettingsCanals", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\272\320\260\320\275\320\260\320\273\320\276\320\262", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SettingsCanals", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 >>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SettingsCanals", "<< \320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SettingsCanals", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("SettingsCanals", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("SettingsCanals", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\242\321\200\320\265\320\261\321\203\320\265\320\274\321\213\320\265 \320\272\320\260\320\275\320\260\320\273\321\213</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsCanals", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\272\320\260\320\275\320\260\320\273\321\213</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsCanals: public Ui_SettingsCanals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSCANALS_H
