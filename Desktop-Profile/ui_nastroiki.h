/********************************************************************************
** Form generated from reading UI file 'nastroiki.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NASTROIKI_H
#define UI_NASTROIKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nastroiki
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QWidget *page_3;
    QLabel *label_2;
    QWidget *page_4;
    QLabel *label_3;
    QWidget *page_5;
    QLabel *label_4;
    QWidget *page_6;
    QLabel *label_5;
    QWidget *page_7;
    QLabel *label_6;
    QWidget *page_2;
    QLabel *label_7;
    QListWidget *listWidget;

    void setupUi(QDialog *Nastroiki)
    {
        if (Nastroiki->objectName().isEmpty())
            Nastroiki->setObjectName(QString::fromUtf8("Nastroiki"));
        Nastroiki->resize(1019, 657);
        widget_2 = new QWidget(Nastroiki);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(743, 614, 270, 42));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMaximumSize(QSize(16777215, 45));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_3);

        stackedWidget = new QStackedWidget(Nastroiki);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(266, 10, 741, 598));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 111, 21));
        comboBox = new QComboBox(page);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(460, 40, 201, 32));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 50, 241, 16));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 220, 84, 30));
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 210, 45, 14));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_6 = new QLabel(page_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_7);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 0, 161, 21));
        stackedWidget->addWidget(page_2);
        listWidget = new QListWidget(Nastroiki);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 250, 598));
        listWidget->setMaximumSize(QSize(250, 16777215));

        retranslateUi(Nastroiki);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Nastroiki);
    } // setupUi

    void retranslateUi(QDialog *Nastroiki)
    {
        Nastroiki->setWindowTitle(QCoreApplication::translate("Nastroiki", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Nastroiki", "Ok", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Nastroiki", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Nastroiki", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Nastroiki", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\270\320\271 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Nastroiki", "PushButton", nullptr));
        label_9->setText(QCoreApplication::translate("Nastroiki", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217</span><span style=\" font-size:12pt; color:#000000;\"/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\276</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\255\320\275\320\265\321\200\320\263\320\265\321\202\320\270\320\272\320\260</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\242\320\265\320\277\320\273\320\276\320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\321\217</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Nastroiki", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#000000;\">\320\230\321\202\320\276\320\263\320\270</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nastroiki: public Ui_Nastroiki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NASTROIKI_H
