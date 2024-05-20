/********************************************************************************
** Form generated from reading UI file 'tepl_nabludatel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEPL_NABLUDATEL_H
#define UI_TEPL_NABLUDATEL_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_tepl_nabludatel
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QWebEngineView *webEngineView;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    Plot *plot;

    void setupUi(QWidget *tepl_nabludatel)
    {
        if (tepl_nabludatel->objectName().isEmpty())
            tepl_nabludatel->setObjectName(QString::fromUtf8("tepl_nabludatel"));
        tepl_nabludatel->resize(858, 610);
        gridLayout = new QGridLayout(tepl_nabludatel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(tepl_nabludatel);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        webEngineView = new QWebEngineView(tab);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_3->addWidget(webEngineView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plot = new Plot(tab_2);
        plot->setObjectName(QString::fromUtf8("plot"));

        gridLayout_2->addWidget(plot, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(tepl_nabludatel);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(tepl_nabludatel);
    } // setupUi

    void retranslateUi(QWidget *tepl_nabludatel)
    {
        tepl_nabludatel->setWindowTitle(QCoreApplication::translate("tepl_nabludatel", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("tepl_nabludatel", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("tepl_nabludatel", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\275\321\213\321\205 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tepl_nabludatel: public Ui_tepl_nabludatel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEPL_NABLUDATEL_H
