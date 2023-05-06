#pragma once
#include "ui_MainWindow.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_cb_italic(bool checked);
  void on_cb_underline(bool checked);
  void on_cb_bold(bool checked);
  void setTextPlainColour();

private:
  Ui_MainWindow* ui;
};
