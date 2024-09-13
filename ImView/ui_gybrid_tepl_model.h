/********************************************************************************
** Form generated from reading UI file 'gybrid_tepl_model.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GYBRID_TEPL_MODEL_H
#define UI_GYBRID_TEPL_MODEL_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_Gybrid_tepl_model
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWebEngineView *webEngineView;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QWebEngineView *webEngineView_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QWebEngineView *webEngineView_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QWebEngineView *webEngineView_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QWebEngineView *webEngineView_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_7;
    Plot *plotg;

    void setupUi(QWidget *Gybrid_tepl_model)
    {
        if (Gybrid_tepl_model->objectName().isEmpty())
            Gybrid_tepl_model->setObjectName(QString::fromUtf8("Gybrid_tepl_model"));
        Gybrid_tepl_model->resize(1122, 663);
        gridLayout = new QGridLayout(Gybrid_tepl_model);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Gybrid_tepl_model);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        webEngineView = new QWebEngineView(tab);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_2->addWidget(webEngineView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        webEngineView_2 = new QWebEngineView(tab_2);
        webEngineView_2->setObjectName(QString::fromUtf8("webEngineView_2"));
        webEngineView_2->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_3->addWidget(webEngineView_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        webEngineView_3 = new QWebEngineView(tab_3);
        webEngineView_3->setObjectName(QString::fromUtf8("webEngineView_3"));
        webEngineView_3->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_4->addWidget(webEngineView_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        webEngineView_4 = new QWebEngineView(tab_4);
        webEngineView_4->setObjectName(QString::fromUtf8("webEngineView_4"));
        webEngineView_4->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_5->addWidget(webEngineView_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        webEngineView_5 = new QWebEngineView(tab_5);
        webEngineView_5->setObjectName(QString::fromUtf8("webEngineView_5"));
        webEngineView_5->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_6->addWidget(webEngineView_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_7 = new QGridLayout(tab_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        plotg = new Plot(tab_6);
        plotg->setObjectName(QString::fromUtf8("plotg"));

        gridLayout_7->addWidget(plotg, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Gybrid_tepl_model);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Gybrid_tepl_model);
    } // setupUi

    void retranslateUi(QWidget *Gybrid_tepl_model)
    {
        Gybrid_tepl_model->setWindowTitle(QCoreApplication::translate("Gybrid_tepl_model", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Gybrid_tepl_model", "\320\236\320\264\320\275\320\276\320\274\320\260\321\201\321\201\320\276\320\262\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Gybrid_tepl_model", "\320\224\320\262\321\203\321\205\320\274\320\260\321\201\321\201\320\276\320\262\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Gybrid_tepl_model", "\320\242\321\200\320\265\321\205\320\274\320\260\321\201\321\201\320\276\320\262\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Gybrid_tepl_model", "\320\247\320\265\321\202\321\213\321\200\320\265\321\205\320\274\320\260\321\201\321\201\320\276\320\262\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Gybrid_tepl_model", "\320\277\321\217\321\202\320\270\320\274\320\260\321\201\321\201\320\276\320\262\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Gybrid_tepl_model", "\320\242\321\200\320\265\320\275\320\264\321\213 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gybrid_tepl_model: public Ui_Gybrid_tepl_model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GYBRID_TEPL_MODEL_H
