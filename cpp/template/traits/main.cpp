#include <iostream>
#include <iterator>

#include "my_traits.hpp"

int main()
{
  int arr[] = {2, 4, 55, 32, 13};
  const char str[] = "Hello World!";
  std::cout << accumulate(std::cbegin(arr), std::cend(arr)) << std::endl;
  std::cout << accumulate(std::cbegin(str), std::cend(str)) << std::endl;
}
