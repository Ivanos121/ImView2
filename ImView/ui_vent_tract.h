/********************************************************************************
** Form generated from reading UI file 'vent_tract.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENT_TRACT_H
#define UI_VENT_TRACT_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vent_tract
{
public:
    QGridLayout *gridLayout;
    QSlider *verticalSlider;
    QWebEngineView *webEngineView;
    QSlider *verticalSlider_2;

    void setupUi(QWidget *Vent_tract)
    {
        if (Vent_tract->objectName().isEmpty())
            Vent_tract->setObjectName(QString::fromUtf8("Vent_tract"));
        Vent_tract->resize(1166, 630);
        gridLayout = new QGridLayout(Vent_tract);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSlider = new QSlider(Vent_tract);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 1, 1, 1);

        webEngineView = new QWebEngineView(Vent_tract);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webEngineView, 0, 0, 1, 1);

        verticalSlider_2 = new QSlider(Vent_tract);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_2, 0, 2, 1, 1);

        verticalSlider->raise();
        verticalSlider_2->raise();
        webEngineView->raise();

        retranslateUi(Vent_tract);

        QMetaObject::connectSlotsByName(Vent_tract);
    } // setupUi

    void retranslateUi(QWidget *Vent_tract)
    {
        Vent_tract->setWindowTitle(QCoreApplication::translate("Vent_tract", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Vent_tract: public Ui_Vent_tract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENT_TRACT_H
