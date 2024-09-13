/********************************************************************************
** Form generated from reading UI file 'poisk.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POISK_H
#define UI_POISK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_poisk
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *poisk)
    {
        if (poisk->objectName().isEmpty())
            poisk->setObjectName(QString::fromUtf8("poisk"));
        poisk->resize(1837, 89);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(poisk->sizePolicy().hasHeightForWidth());
        poisk->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(poisk);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        gridLayout->setContentsMargins(6, 0, 6, 0);
        pushButton_2 = new QPushButton(poisk);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        label_2 = new QLabel(poisk);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(poisk);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(0, 0));
        pushButton_7->setMaximumSize(QSize(34, 34));
        pushButton_7->setFlat(false);

        gridLayout->addWidget(pushButton_7, 0, 5, 1, 1, Qt::AlignmentFlag::AlignRight);

        pushButton_5 = new QPushButton(poisk);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setFlat(false);

        gridLayout->addWidget(pushButton_5, 0, 3, 1, 1);

        label = new QLabel(poisk);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(poisk);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 1, 3, 1, 1);

        lineEdit_2 = new QLineEdit(poisk);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy4);
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(poisk);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy4.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(poisk);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(poisk);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(poisk);

        QMetaObject::connectSlotsByName(poisk);
    } // setupUi

    void retranslateUi(QWidget *poisk)
    {
        poisk->setWindowTitle(QCoreApplication::translate("poisk", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("poisk", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214 \320\270 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("poisk", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214:", nullptr));
        pushButton_7->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("poisk", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        label->setText(QCoreApplication::translate("poisk", "\320\230\321\201\320\272\320\260\321\202\321\214:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("poisk", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("poisk", "\320\235\320\260\320\271\321\202\320\270 \320\270 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272 ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("poisk", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\201\321\202\321\200\320\260\320\275\320\270\321\206 stackedwidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class poisk: public Ui_poisk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POISK_H
