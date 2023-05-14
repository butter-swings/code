#include <QMetaProperty>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boy = new Person("王小明");
    boy->setProperty("score", 95);
    boy->setProperty("age", 10);
    boy->setProperty("sex", "Boy");
    connect(boy, &Person::ageChanged, this, &MainWindow::on_ageChanged);

    girl = new Person("张小丽");
    girl->setProperty("score", 81);
    girl->setProperty("age", 20);
    girl->setProperty("sex", "Girl");
    connect(girl, &Person::ageChanged, this, &MainWindow::on_ageChanged);

    ui->spinBoy->setProperty("isBoy", true);
    ui->spinGirl->setProperty("isBoy", false);

    connect(ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
    connect(ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ageChanged(int value)
{
  Q_UNUSED(value);

  Person *person = qobject_cast<Person*>(sender());
  QString name = person->property("name").toString();
  QString sex = person->property("sex").toString();
  int age = person->getAge();
  ui->textEdit->appendPlainText(name + "," + sex + QString::asprintf(",年龄=%d", age));
}

void MainWindow::on_spin_valueChanged(int arg)
{
  Q_UNUSED(arg);
  QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
  if (spinBox->property("isBoy").toBool())
    boy->setAge(spinBox->value());
  else
    girl->setAge(spinBox->value());
}

void MainWindow::on_btnClear_clicked()
{
  ui->textEdit->clear();
}

void MainWindow::on_btnBoyInc_clicked()
{
  boy->incAge();
  ui->spinBoy->setValue(boy->getAge());
}

void MainWindow::on_btnGirlInc_clicked()
{
  girl->incAge();
  ui->spinGirl->setValue(girl->getAge());
}

void MainWindow::on_btnClassInfo_clicked()
{
  const QMetaObject* meta = girl->metaObject();
  ui->textEdit->clear();
  ui->textEdit->appendPlainText("==元对象信息==");
  ui->textEdit->appendPlainText(QString("类名称: %1\n").arg(meta->className()));

  ui->textEdit->appendPlainText("property");
  for (int i = meta->propertyOffset(); i != meta->propertyCount(); ++i)
  {
    const char* propName = meta->property(i).name();
    ui->textEdit->appendPlainText(
        QString("属性名称=%1, 属性值=%2").
        arg(propName).
        arg(boy->property(propName).toString())
      );
  }
  ui->textEdit->appendPlainText("");
  ui->textEdit->appendPlainText("classInfo");
  for (int i = meta->classInfoOffset(); i != meta->classInfoCount(); ++i)
  {
    QMetaClassInfo classInfo = meta->classInfo(i);
    ui->textEdit->appendPlainText(
        QString("Name=%1, Value=%2").
        arg(classInfo.name()).
        arg(classInfo.value())
      );
  }
}
