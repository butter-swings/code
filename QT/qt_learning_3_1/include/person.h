#ifndef PERSON_H
#define PERSON_H
#include <QObject>

class Person : public QObject
{
  Q_OBJECT
  Q_CLASSINFO("author", "july")
  Q_CLASSINFO("company", "ujs")
  Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
  Q_PROPERTY(QString name MEMBER m_name)
  Q_PROPERTY(int score MEMBER m_score)

private:
  int m_age   = 10;
  int m_score = 79;

  QString m_name;

public:
  explicit Person(QString fName, QObject* parent = nullptr);

  int  getAge();
  void setAge(int value);

  void incAge();

signals:
  void ageChanged(int value);

public slots:

};

#endif
