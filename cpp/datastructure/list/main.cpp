#include <iostream>
#include "list.hpp"

int main(int argc, char** argv)
{
  list<int> list;
  for(int i = 0; i != 10; ++i)
  {
    list.insert(i);
  }
  std::cout << list.front();
}
