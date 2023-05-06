#include "mainwindow.h"
#include <QTextCharFormat>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QCoreApplication>

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_mainwindow)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    if (checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->setCurrentCharFormat(fmt);
}

void mainwindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void mainwindow::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
void mainwindow::on_actFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
        ui->txtEdit->setFont(font);
} // dialog of font choices

void mainwindow::on_actNew_triggered()
{
    ui->txtEdit->clear();
    updateCurFile("");
} // new file

void mainwindow::on_actOpen_triggered()
{
    QString curPath, aFileName;
    curPath = QCoreApplication::applicationDirPath(); // 获取应用程序的路径

    // 调用打开文件对话框打开一个文件
    aFileName = QFileDialog::getOpenFileName(this, tr(u8"打开一个文件"), curPath,
                                             u8"C++程序文件(*.cpp);;H头文件(*.h);;文本文件(*.txt);;所有文件(*.*)");

    if (!aFileName.isEmpty())
    {
        QFile aFile(aFileName); // 以文件方式读出
        if (aFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream aStream(&aFile); // 用文本流读取文件
            QString temp;
            while (!aStream.atEnd())
            {
                temp = aStream.readLine().toLocal8Bit();
                ui->txtEdit->append(temp); // 读取一个文本行
            }
            updateCurFile(aFileName); // 更新状态栏显示
        }
        aFile.close();
    }
} // open file

void mainwindow::on_txtEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
    ui->actFontBold->setChecked(fmt.font().bold());
} // update bold underline italic action

void mainwindow::on_txtEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);  // 能否 cut
    ui->actCopy->setEnabled(b); // 能否copy

    ui->actPaste->setEnabled(ui->txtEdit->canPaste()); // 能否paste
} // if copyable,update the situation of enable on copy

void mainwindow::on_actToolbarLab_triggered(bool checked)
{
    if (checked)
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    else
        ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
} // set the format of toolbar button

// custom slots
void mainwindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
} // reflection on the change of the font size in spinbox

void mainwindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
} // reflection on the font name in fontcombobox

void mainwindow::updateCurFile(QString aFile)
{
    fCurFileName = aFile;
    fLabCurFile->setText(u8"当前文件:" + fCurFileName);
} // refresh the name of current file and the percent

void mainwindow::iniUI()
{
    // statusbar
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText(u8"当前文件:");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1);

    // toolBar
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->toolBar->addWidget(new QLabel(u8"字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(new QLabel(u8" 字体 "));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->txtEdit);

} // initialize the ui

void mainwindow::iniSignalSlots()
{
    connect(spinFontSize, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBoxFontSize_valueChanged(int)));

    connect(comboFont, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(on_comboFont_currentIndexChanged(const QString &)));
} // connet the signals and slots by hand

// void mainwindow::createNew() {}