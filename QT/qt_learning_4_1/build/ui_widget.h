/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *editPrice;
    QPushButton *btnCal;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *editNum;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *editTotal;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *btnBin;
    QLineEdit *editDec;
    QLineEdit *editBin;
    QPushButton *btnHex;
    QLineEdit *editHex;
    QPushButton *btnDec;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(442, 215);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        editPrice = new QLineEdit(Widget);
        editPrice->setObjectName(QString::fromUtf8("editPrice"));

        gridLayout_2->addWidget(editPrice, 0, 4, 1, 1);

        btnCal = new QPushButton(Widget);
        btnCal->setObjectName(QString::fromUtf8("btnCal"));

        gridLayout_2->addWidget(btnCal, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        editNum = new QLineEdit(Widget);
        editNum->setObjectName(QString::fromUtf8("editNum"));

        gridLayout_2->addWidget(editNum, 0, 1, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        editTotal = new QLineEdit(Widget);
        editTotal->setObjectName(QString::fromUtf8("editTotal"));

        gridLayout_2->addWidget(editTotal, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(398, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnBin = new QPushButton(Widget);
        btnBin->setObjectName(QString::fromUtf8("btnBin"));

        gridLayout->addWidget(btnBin, 1, 2, 1, 1);

        editDec = new QLineEdit(Widget);
        editDec->setObjectName(QString::fromUtf8("editDec"));

        gridLayout->addWidget(editDec, 0, 1, 1, 1);

        editBin = new QLineEdit(Widget);
        editBin->setObjectName(QString::fromUtf8("editBin"));

        gridLayout->addWidget(editBin, 1, 1, 1, 1);

        btnHex = new QPushButton(Widget);
        btnHex->setObjectName(QString::fromUtf8("btnHex"));

        gridLayout->addWidget(btnHex, 2, 2, 1, 1);

        editHex = new QLineEdit(Widget);
        editHex->setObjectName(QString::fromUtf8("editHex"));

        gridLayout->addWidget(editHex, 2, 1, 1, 1);

        btnDec = new QPushButton(Widget);
        btnDec->setObjectName(QString::fromUtf8("btnDec"));

        gridLayout->addWidget(btnDec, 0, 2, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnCal->setText(QCoreApplication::translate("Widget", "\350\256\241\347\256\227", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\225\260 \351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\273 \344\273\267", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\225 \344\273\267", nullptr));
        btnBin->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        btnHex->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        btnDec->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\215\201 \350\277\233 \345\210\266", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\344\272\214 \350\277\233 \345\210\266", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
