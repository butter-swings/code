#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <qlabel.h>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void on_actFontBold_triggered(bool checked);   // bold font action
    void on_actFontItalic_triggered(bool checked); // italic font action
    void on_actFontUnder_triggered(bool checked);  // underline font action

    void on_actFont_triggered(); // dialog of font choices

    void on_actNew_triggered();  // new file
    void on_actOpen_triggered(); // open file

    void on_txtEdit_selectionChanged();    // update bold underline italic action
    void on_txtEdit_copyAvailable(bool b); // if copyable,update the situation of enable on copy

    void on_actToolbarLab_triggered(bool checked); // set the format of toolbar button

    // custom slots
    void on_spinBoxFontSize_valueChanged(int aFontSize);        // reflection on the change of the font size in spinbox
    void on_comboFont_currentIndexChanged(const QString &arg1); // reflection on the font name in fontcombobox

private:
    Ui_mainwindow *ui;

    QString fCurFileName;       // current file name
    QLabel *fLabCurFile;        // the lable which shows the file name
    QProgressBar *progressBar1; // the lable of percent in the file

    QSpinBox *spinFontSize;   // the case of the font
    QFontComboBox *comboFont; // name of the font

    void updateCurFile(QString aFile); // refresh the name of current file and the percent
    void iniUI();                      // initialize the ui
    void iniSignalSlots();             // connet the signals and slots by hand
    void createNew();
};