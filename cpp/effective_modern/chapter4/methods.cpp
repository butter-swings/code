#include <iostream>
#include <vector>

class Widget{};

template <typename T>
class TD{};

std::vector<Widget> createVec();

template <typename T>
void f(const T& param)
{
  std::cout << "T = \t" << typeid(T).name() << std::endl;
  std::cout << "param = \t" << typeid(param).name() << std::endl;

  // T and param both are outputed const Widget*( here should not be the true type of param)
  // the param's type should be const Widget * const &
  // !!!
  // the reference attribution seems to be ignored
  // the same as the top const to the pointer to Widget

  // if the true type name is wanted
  // may the Boost.TypeIndex is OK
  //
  // the true type
  // T is const Widget*
  // param is const Widget * const & (a const reference binds to T)
}

int main()
{
  const int theAnswer = 42;
  auto x = theAnswer;
  auto y = &theAnswer;

  // if class TD has no definition
  // the compiler will send error message
  TD<decltype(x)> xType;
  TD<decltype(y)> yType;

  // clang Windows MSVC
  std::cout << typeid(x).name() << std::endl;
  // output: int
  std::cout << typeid(y).name() << std::endl;
  // output: int const* __ptr64

  const auto vw = createVec();
  if(!vw.empty())
  {
    f(&vw[0]);
  }
}
