#include <iostream>

struct X
{
  X() = default;
  X(const X& x) { std::cout << "copy constructor" << std::endl; }
  X(X&& x) { std::cout << "move constructor" << std::endl; }
};

X getX() 
{
  // RVO
  return X{}; 

  // NRVO
  // X temp = X{};
  // return temp;
}

void testX(X x) { std::cout << &x << std::endl; }

int main(int argc, char** argv)
{
  // copy elision
  X cur_x = getX();
  std::endl(std::cout);
  
  // move constructor
  // avoid RVO
  X move_x = std::move(getX());
  std::endl(std::cout);

  // copy constructor
  testX(cur_x);
  std::endl(std::cout);

  // copy elision to parameter x which is type X
  testX(getX());
  std::endl(std::cout);

}
