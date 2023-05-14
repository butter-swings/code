#include "person.h"

Person::Person(QString fName, QObject* parent)
{
  m_name = fName;
}

int Person::getAge()
{
  return m_age;
}

void Person::setAge(int value)
{
  m_age = value;
  emit ageChanged(m_age);
}

void Person::incAge()
{
  ++m_age;
  emit ageChanged(m_age);
}
