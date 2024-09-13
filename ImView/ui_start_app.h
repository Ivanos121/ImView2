/********************************************************************************
** Form generated from reading UI file 'start_app.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_APP_H
#define UI_START_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start_app
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_16;
    QTableWidget *tableWidget_2;
    QLabel *label_3;
    QWidget *widget_3;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Start_app)
    {
        if (Start_app->objectName().isEmpty())
            Start_app->setObjectName(QString::fromUtf8("Start_app"));
        Start_app->resize(1671, 660);
        gridLayout = new QGridLayout(Start_app);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(Start_app);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        label_16->setFont(font);

        verticalLayout->addWidget(label_16, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        tableWidget_2 = new QTableWidget(widget_2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy);
        tableWidget_2->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette;
        QBrush brush(QColor(239, 240, 241, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        tableWidget_2->setPalette(palette);
        tableWidget_2->setFrameShape(QFrame::Shape::NoFrame);
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tableWidget_2->setShowGrid(false);
        tableWidget_2->setGridStyle(Qt::PenStyle::SolidLine);
        tableWidget_2->setSortingEnabled(false);

        verticalLayout->addWidget(tableWidget_2);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QPalette palette1;
        QBrush brush1(QColor(166, 166, 166, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        label_3->setPalette(palette1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    text: \"Hello world\"\n"
"    font.pixelSize: 200\n"
"    font.italic: true\n"
"    color: red\n"
"}"));

        verticalLayout->addWidget(label_3, 0, Qt::AlignmentFlag::AlignHCenter);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(Start_app);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(550, 0));
        widget_3->setMaximumSize(QSize(550, 16777215));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 6, 141, 21));
        label->setFont(font);
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 513, 401));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 4, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 5, 0, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 6, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 7, 0, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 8, 0, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 9, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 10, 0, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 11, 0, 1, 1);


        gridLayout->addWidget(widget_3, 0, 2, 1, 1);

        widget = new QWidget(Start_app);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(500, 0));
        widget->setMaximumSize(QSize(500, 16777215));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::TextFormat::AutoText);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        tableWidget->setPalette(palette2);
        tableWidget->setFrameShape(QFrame::Shape::NoFrame);
        tableWidget->setShowGrid(false);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Start_app);

        QMetaObject::connectSlotsByName(Start_app);
    } // setupUi

    void retranslateUi(QWidget *Start_app)
    {
        Start_app->setWindowTitle(QCoreApplication::translate("Start_app", "Form", nullptr));
        label_16->setText(QCoreApplication::translate("Start_app", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Start_app", "<html><head/><body><p><span style=\" font-size:100pt; font-style:italic;\">IM View</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Start_app", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Start_app", "\320\236\321\201\320\275\320\276\320\262\321\213 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("Start_app", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\201\320\265\321\201\321\201\320\270\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("Start_app", "\320\222\320\262\320\276\320\264 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_7->setText(QCoreApplication::translate("Start_app", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262 \321\201\321\205\320\265\320\274\321\213 \320\267\320\260\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("Start_app", "\320\255\320\275\320\265\321\200\320\263\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_9->setText(QCoreApplication::translate("Start_app", "\320\242\320\265\320\277\320\273\320\276\320\262\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_10->setText(QCoreApplication::translate("Start_app", "\320\222\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_11->setText(QCoreApplication::translate("Start_app", "\320\242\320\265\320\277\320\273\320\276\320\262\320\265\320\275\321\202\320\270\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("Start_app", "\320\237\321\200\320\276\320\263\320\275\320\276\320\267 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_13->setText(QCoreApplication::translate("Start_app", "\320\242\320\265\320\277\320\273\320\276\320\262\320\276\320\271 \320\275\320\260\320\261\320\273\321\216\320\264\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_14->setText(QCoreApplication::translate("Start_app", "\320\236\321\201\321\202\320\260\321\202\320\276\321\207\320\275\321\213\320\271 \321\202\320\265\320\277\320\260\320\273\320\276\320\262\320\276\320\271 \321\200\320\265\321\201\321\203\321\200\321\201 \320\276\320\261\320\274\320\276\321\202\320\272\320\270 \321\201\321\202\320\260\321\202\320\276\321\200\320\260 \320\260\321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_15->setText(QCoreApplication::translate("Start_app", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\320\260 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("Start_app", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start_app: public Ui_Start_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_APP_H
