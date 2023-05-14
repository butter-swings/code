/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBoy;
    QSpinBox *spinBoy;
    QPushButton *btnBoyInc;
    QPushButton *btnClassInfo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelGirl;
    QSpinBox *spinGirl;
    QPushButton *btnGirlInc;
    QPushButton *btnClear;
    QPlainTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(625, 387);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelBoy = new QLabel(centralwidget);
        labelBoy->setObjectName(QString::fromUtf8("labelBoy"));

        horizontalLayout->addWidget(labelBoy);

        spinBoy = new QSpinBox(centralwidget);
        spinBoy->setObjectName(QString::fromUtf8("spinBoy"));
        spinBoy->setValue(10);

        horizontalLayout->addWidget(spinBoy);

        btnBoyInc = new QPushButton(centralwidget);
        btnBoyInc->setObjectName(QString::fromUtf8("btnBoyInc"));

        horizontalLayout->addWidget(btnBoyInc);

        btnClassInfo = new QPushButton(centralwidget);
        btnClassInfo->setObjectName(QString::fromUtf8("btnClassInfo"));

        horizontalLayout->addWidget(btnClassInfo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelGirl = new QLabel(centralwidget);
        labelGirl->setObjectName(QString::fromUtf8("labelGirl"));

        horizontalLayout_2->addWidget(labelGirl);

        spinGirl = new QSpinBox(centralwidget);
        spinGirl->setObjectName(QString::fromUtf8("spinGirl"));
        spinGirl->setValue(20);

        horizontalLayout_2->addWidget(spinGirl);

        btnGirlInc = new QPushButton(centralwidget);
        btnGirlInc->setObjectName(QString::fromUtf8("btnGirlInc"));

        horizontalLayout_2->addWidget(btnGirlInc);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout_2->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        horizontalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 625, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelBoy->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\267\347\224\237\345\271\264\351\276\204", nullptr));
        btnBoyInc->setText(QCoreApplication::translate("MainWindow", "boy\351\225\277\345\244\247\344\270\200\345\262\201", nullptr));
        btnClassInfo->setText(QCoreApplication::translate("MainWindow", "\347\261\273\347\232\204\345\205\203\345\257\271\350\261\241\344\277\241\346\201\257", nullptr));
        labelGirl->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\245\263\347\224\237\345\271\264\351\276\204", nullptr));
        btnGirlInc->setText(QCoreApplication::translate("MainWindow", "girl\351\225\277\345\244\247\344\270\200\345\262\201", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
