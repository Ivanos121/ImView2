/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *actionclose;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(609, 355);
        actionclose = new QPushButton(AboutDialog);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        actionclose->setGeometry(QRect(510, 310, 85, 33));
        actionclose->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 320, 111, 21));
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 611, 301));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/data/img/images/zastavka.png")));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "Dialog", nullptr));
        actionclose->setText(QCoreApplication::translate("AboutDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\222\320\265\321\200\321\201\320\270\321\217 0.4.2</span></p></body></html>", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
