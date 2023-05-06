/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cb_underline;
    QCheckBox *cb_italic;
    QCheckBox *cb_bold;
    QHBoxLayout *horizontalLayout;
    QRadioButton *ra_black;
    QRadioButton *ra_blue;
    QRadioButton *ra_red;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_reject;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_quit;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cb_underline = new QCheckBox(centralwidget);
        cb_underline->setObjectName(QString::fromUtf8("cb_underline"));
        QFont font;
        font.setPointSize(15);
        cb_underline->setFont(font);

        horizontalLayout_2->addWidget(cb_underline);

        cb_italic = new QCheckBox(centralwidget);
        cb_italic->setObjectName(QString::fromUtf8("cb_italic"));
        cb_italic->setFont(font);

        horizontalLayout_2->addWidget(cb_italic);

        cb_bold = new QCheckBox(centralwidget);
        cb_bold->setObjectName(QString::fromUtf8("cb_bold"));
        cb_bold->setFont(font);

        horizontalLayout_2->addWidget(cb_bold);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ra_black = new QRadioButton(centralwidget);
        ra_black->setObjectName(QString::fromUtf8("ra_black"));
        ra_black->setFont(font);

        horizontalLayout->addWidget(ra_black);

        ra_blue = new QRadioButton(centralwidget);
        ra_blue->setObjectName(QString::fromUtf8("ra_blue"));
        ra_blue->setFont(font);

        horizontalLayout->addWidget(ra_blue);

        ra_red = new QRadioButton(centralwidget);
        ra_red->setObjectName(QString::fromUtf8("ra_red"));
        ra_red->setFont(font);

        horizontalLayout->addWidget(ra_red);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font1;
        font1.setPointSize(35);
        plainTextEdit->setFont(font1);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_reject = new QPushButton(centralwidget);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));
        btn_reject->setFont(font);
        btn_reject->setAutoRepeatDelay(310);

        horizontalLayout_3->addWidget(btn_reject);

        btn_confirm = new QPushButton(centralwidget);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setFont(font);
        btn_confirm->setAutoRepeatDelay(310);

        horizontalLayout_3->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setFont(font);
        btn_quit->setAutoRepeatDelay(310);

        horizontalLayout_3->addWidget(btn_quit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 414, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btn_quit, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(btn_reject, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(btn_confirm, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cb_underline->setText(QCoreApplication::translate("MainWindow", "underline", nullptr));
        cb_italic->setText(QCoreApplication::translate("MainWindow", "italic", nullptr));
        cb_bold->setText(QCoreApplication::translate("MainWindow", "bold", nullptr));
        ra_black->setText(QCoreApplication::translate("MainWindow", "black", nullptr));
        ra_blue->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        ra_red->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "This is a test!!", nullptr));
        btn_reject->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        btn_confirm->setText(QCoreApplication::translate("MainWindow", "confirm", nullptr));
        btn_quit->setText(QCoreApplication::translate("MainWindow", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
