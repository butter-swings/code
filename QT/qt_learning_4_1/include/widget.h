#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  Ui::Widget *ui;

private slots:
  void on_btnDec_clicked();
  void on_btnCal_clicked();
};

#endif  // WIDGET_H
