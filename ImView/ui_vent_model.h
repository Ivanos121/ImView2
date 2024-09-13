/********************************************************************************
** Form generated from reading UI file 'vent_model.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENT_MODEL_H
#define UI_VENT_MODEL_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_vent_model
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QGridLayout *gridLayout_6;
    QWebEngineView *webEngineView;
    QWidget *tab_8;
    QGridLayout *gridLayout_7;
    QWebEngineView *webEngineView_2;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget_3;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QWebEngineView *webEngineView_3;
    QWidget *tab_9;
    QGridLayout *gridLayout_10;
    QWebEngineView *webEngineView_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_9;
    Plot *plot;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QWebEngineView *webEngineView_4;

    void setupUi(QWidget *vent_model)
    {
        if (vent_model->objectName().isEmpty())
            vent_model->setObjectName(QString::fromUtf8("vent_model"));
        vent_model->resize(1096, 673);
        gridLayout = new QGridLayout(vent_model);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(vent_model);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget_2 = new QTabWidget(tab_5);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_6 = new QGridLayout(tab_7);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        webEngineView = new QWebEngineView(tab_7);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_6->addWidget(webEngineView, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        gridLayout_7 = new QGridLayout(tab_8);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        webEngineView_2 = new QWebEngineView(tab_8);
        webEngineView_2->setObjectName(QString::fromUtf8("webEngineView_2"));
        webEngineView_2->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_7->addWidget(webEngineView_2, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_8, QString());

        gridLayout_4->addWidget(tabWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget_3 = new QTabWidget(tab);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        webEngineView_3 = new QWebEngineView(tab_3);
        webEngineView_3->setObjectName(QString::fromUtf8("webEngineView_3"));
        webEngineView_3->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_2->addWidget(webEngineView_3, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_3, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        gridLayout_10 = new QGridLayout(tab_9);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        webEngineView_5 = new QWebEngineView(tab_9);
        webEngineView_5->setObjectName(QString::fromUtf8("webEngineView_5"));
        webEngineView_5->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_10->addWidget(webEngineView_5, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_9, QString());

        gridLayout_5->addWidget(tabWidget_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_9 = new QGridLayout(tab_6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        plot = new Plot(tab_6);
        plot->setObjectName(QString::fromUtf8("plot"));

        gridLayout_9->addWidget(plot, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        webEngineView_4 = new QWebEngineView(tab_4);
        webEngineView_4->setObjectName(QString::fromUtf8("webEngineView_4"));
        webEngineView_4->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_8->addWidget(webEngineView_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(vent_model);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(vent_model);
    } // setupUi

    void retranslateUi(QWidget *vent_model)
    {
        vent_model->setWindowTitle(QCoreApplication::translate("vent_model", "Form", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("vent_model", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\321\213 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\276\320\271 \321\201\320\265\321\202\320\270", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("vent_model", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\202\320\276\321\200\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("vent_model", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QCoreApplication::translate("vent_model", "\320\236\320\264\320\270\320\275 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\202\320\276\321\200", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QCoreApplication::translate("vent_model", "\320\235\320\265\320\267\320\260\320\262\320\270\321\201\320\270\320\274\320\260\321\217 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("vent_model", "\320\222\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\267\320\260\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("vent_model", "\320\242\321\200\320\265\320\275\320\264\321\213 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\276\320\271 \321\201\320\265\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("vent_model", "\320\255\320\275\320\265\321\200\320\263\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260 \320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\202\320\276\321\200\320\260 \320\270 \320\265\320\263\320\276 \321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vent_model: public Ui_vent_model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENT_MODEL_H
