#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <Qcheckbox.h>
#include <Qradiobutton.h>
#include <Qplaintextedit.h>
#include <Qpushbutton.h>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_cb_underline(bool checked);
    void on_cb_italic(bool checked);
    void on_cb_bold(bool checked);
    void setTextFontColour();

private:
    QCheckBox *cb_underline;
    QCheckBox *cb_italic;
    QCheckBox *cb_bold;

    QRadioButton *ra_black;
    QRadioButton *ra_red;
    QRadioButton *ra_blue;

    QPlainTextEdit *txtEdit;

    QPushButton *btn_confirm;
    QPushButton *btn_cancel;
    QPushButton *btn_quit;

    void iniUI();
    void iniSignalSlots();
};
#endif // DIALOG_H
