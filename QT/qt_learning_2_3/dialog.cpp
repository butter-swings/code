#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("myDialog");
}

Dialog::~Dialog() {}

void Dialog::on_cb_bold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::on_cb_underline(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::on_cb_italic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::setTextFontColour()
{
    QPalette plet = txtEdit->palette();
    if (ra_black->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::black);
    }
    else if (ra_red->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::red);
    }
    else if (ra_blue->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::blue);
    }
    else
        plet.setColor(QPalette::Text, Qt::black);
    txtEdit->setPalette(plet);
}

void Dialog::iniUI()
{
    cb_underline = new QCheckBox(tr("Underline"));
    cb_bold = new QCheckBox(tr("Bold"));
    cb_italic = new QCheckBox(tr("Italic"));

    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(cb_bold);
    HLay1->addWidget(cb_underline);
    HLay1->addWidget(cb_italic);

    ra_black = new QRadioButton(tr("black"));
    ra_black->setChecked(true);
    ra_red = new QRadioButton(tr("red"));
    ra_blue = new QRadioButton(tr("blue"));

    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(ra_black);
    HLay2->addWidget(ra_red);
    HLay2->addWidget(ra_blue);

    btn_cancel = new QPushButton(tr("cancel"));
    btn_confirm = new QPushButton(tr("confirm"));
    btn_quit = new QPushButton(tr("quit"));

    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btn_confirm);
    HLay3->addWidget(btn_cancel);
    HLay3->addStretch();
    HLay3->addWidget(btn_quit);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n\nIt is my demo");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void Dialog::iniSignalSlots()
{
    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btn_confirm, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btn_quit, SIGNAL(clicked()), this, SLOT(reject()));

    connect(ra_black, SIGNAL(clicked()), this, SLOT(setTextFontColour()));
    connect(ra_red, SIGNAL(clicked()), this, SLOT(setTextFontColour()));
    connect(ra_blue, SIGNAL(clicked()), this, SLOT(setTextFontColour()));

    connect(cb_bold, SIGNAL(clicked(bool)), this, SLOT(on_cb_bold(bool)));
    connect(cb_underline, SIGNAL(clicked(bool)), this, SLOT(on_cb_underline(bool)));
    connect(cb_italic, SIGNAL(clicked(bool)), this, SLOT(on_cb_italic(bool)));
}