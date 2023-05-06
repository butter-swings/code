#ifndef _MSTRING_H_
#define _MSTRING_H_

#include <cstddef>
#include <ostream>

class String;
std::ostream& operator << (std::ostream& _os, const String& str);

class String
{
  public:
    String();
    String(const char* str);

    ~String();

    bool operator == (const String& str);
    bool operator != (const String& str);

    String& operator = (const String& str);
    String& operator = (String&& str);

    String& operator + (const String& str);
    String& operator + (const char* str);

    String(const String& str);
    String(String&& str);


    std::size_t length();

    friend std::ostream& operator << (std::ostream& _os, const String& str);

  private:
    char* _str;
};

#endif
