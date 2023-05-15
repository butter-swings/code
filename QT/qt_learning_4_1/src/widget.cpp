#include <QString>

#include "ui_widget.h"
#include "widget.h"

Widget::Widget(QWidget *parent) 
  : QWidget(parent), ui(new Ui::Widget)
{
  ui->setupUi(this);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::on_btnCal_clicked()
{
  int num = ui->editNum->text().toInt();
  double price = ui->editPrice->text().toDouble();
  double total = num * price;
}

void Widget::on_btnDec_clicked()
{
  QString str = ui->editDec->text();
  int value = str.toInt();

  str = QString::number(value, 16);
  str = str.toUpper();
  ui->editHex->setText(str);

  str = QString::number(value, 2);
  ui->editBin->setText(str);
}
