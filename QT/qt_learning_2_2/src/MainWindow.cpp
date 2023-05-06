#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_MainWindow)
{
  ui->setupUi(this);
  QObject::connect(ui->ra_black, SIGNAL(clicked()), this,
                   SLOT(setTextPlainColour()));
  QObject::connect(ui->ra_red, SIGNAL(clicked()), this,
                   SLOT(setTextPlainColour()));
  QObject::connect(ui->ra_blue, SIGNAL(clicked()), this,
                   SLOT(setTextPlainColour()));
  QObject::connect(ui->cb_bold, SIGNAL(clicked(bool)), this,
                   SLOT(on_cb_bold(bool)));
  QObject::connect(ui->cb_italic, SIGNAL(clicked(bool)), this,
                   SLOT(on_cb_italic(bool)));
  QObject::connect(ui->cb_underline, SIGNAL(clicked(bool)), this,
                   SLOT(on_cb_underline(bool)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_cb_italic(bool checked)
{
  QFont font = ui->plainTextEdit->font();
  font.setItalic(checked);
  ui->plainTextEdit->setFont(font);
}

void MainWindow::on_cb_underline(bool checked)
{
  QFont font = ui->plainTextEdit->font();
  font.setUnderline(checked);
  ui->plainTextEdit->setFont(font);
}

void MainWindow::on_cb_bold(bool checked)
{
  QFont font = ui->plainTextEdit->font();
  font.setBold(checked);
  ui->plainTextEdit->setFont(font);
}

void MainWindow::setTextPlainColour()
{
  QPalette plet = ui->plainTextEdit->palette();
  if (ui->ra_black->isChecked()) { plet.setColor(QPalette::Text, Qt::black); }
  else if (ui->ra_red->isChecked()) { plet.setColor(QPalette::Text, Qt::red); }
  else if (ui->ra_blue->isChecked())
  {
    plet.setColor(QPalette::Text, Qt::blue);
  }
  else
    plet.setColor(QPalette::Text, Qt::black);
  ui->plainTextEdit->setPalette(plet);
}
