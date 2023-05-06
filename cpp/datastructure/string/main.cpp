#include "string.hpp"
#include <iostream>

int main()
{
  String s1 = "Hello World!";
  String s2;
  String s3;
  s2 = s3 = s1;
  std::cout << s1.length() << " " << s2.length() << std::endl;
  std::cout << s1
            << " "
            << s2
            << " "
            << s3;
  return 0;
}
