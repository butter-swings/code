#include <iostream>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
{ 
  initUi();
  initSignalsSlots();
}

MainWindow::~MainWindow()
{ }

void MainWindow::initUi()
{
  setWindowTitle("QT_PROJECT_WITHOUT_VISUAL_UI");
  setGeometry(100, 100, 800, 500);
}

void MainWindow::initSignalsSlots()
{ }
