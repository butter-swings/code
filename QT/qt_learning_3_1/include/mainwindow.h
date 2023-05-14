#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "person.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  Person* boy;
  Person* girl;

private slots:
  void on_ageChanged(int value);
  void on_spin_valueChanged(int arg);

  void on_btnClear_clicked();
  void on_btnBoyInc_clicked();
  void on_btnGirlInc_clicked();
  void on_btnClassInfo_clicked();

};

#endif // MAINWINDOW_H
