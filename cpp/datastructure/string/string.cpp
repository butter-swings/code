#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstddef>
#include <cstring>

#include "string.hpp"

String::String() : _str( new char[1]{'\0'} ) {}

String::String(const char* str)
{
  _str = new char[std::strlen(str) + 1];
  std::strcpy(_str, str);
}

String::~String()
{
  delete [] _str;
}

bool String::operator == (const String& str)
{
  return std::strcmp(_str, str._str) == 0;
}

bool String::operator != (const String& str)
{
  return !this->operator == (str);
}

String::String(const String& str)
{
  assert(&str != this);
  // this assertion is to forbid from constructing a String by itself
  if(this != &str)
  {
    _str = new char[std::strlen(str._str) + 1];
    std::strcpy(_str, str._str);
  }
  else _str = new char[1]{'\0'};
}

String::String(String&& str) : _str(str._str) { str._str = new char[1]{'\0'}; }

String& String::operator = (const String &str)
{
  if(this != &str)
  {
    delete [] _str;
    _str = new char[std::strlen(str._str) + 1];
    std::strcpy(_str, str._str);
  }
  return *this;
}

String& String::operator = (String&& str)
{
  delete [] _str;
  _str = str._str;
  str._str = new char[1]{'\0'};
  return *this;
}

std::ostream& operator << (std::ostream &_os, const String& str) 
{ 
  return _os << str._str; 
}

std::size_t String::length() { return std::strlen(_str); }

String& String::operator + (const char* str)
{
  std::strcat(_str, str);
  return *this;
}

String& String::operator + (const String& str)
{
  std::strcat(_str, str._str);
  return *this;
}
