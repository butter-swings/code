#include <utility>
#include <vector>
// decltype 
// almoslty we can get the same type ? in decltype(?)
//
// except bool type in containers like vector<bool>
// in chapter6 
// it's std::vector<bool>::reference
// a proxy


// in c++11
template <typename Container, typename Index>
auto authAndAccess1(Container& c, Index i)->decltype(c[i])
{
  return c[i];
}

// in c++14
template <typename Container, typename Index>
auto authAndAccess2(Container& c, Index i)
{
  return c[i];
}

// but the auto in return type deduction is template parameter deduction
// it will be error if we are trying to modify the value of c[i]
// decltype(auto) should be used in order to avoid return type's deduction non-reference
// in c++14

template <typename Container, typename Index>
decltype(auto) authAndAccess3(Container& c, Index i)
{
  return c[i];
}


// sometimes we need to pass a rvalue container to the function template
// but the pure lvalue reference can not accept a pure rvalue
// perhaps the function overload will address the problem
// sadly we will need to maintenance more functions
// so the universal reference is coming here

// c++14
template <typename Container, typename Index>
decltype(auto) authAndAccess4(Container&& c, Index i)
{
  // return std::forward<decltype(c[i])>(c[i]);

  // in effective modern c++ book
  return std::forward<Container>(c)[i];
}

// old version in c++11
template <typename Container, typename Index>
auto 
authAndAccess5(Container&& c, Index i)
->decltype(std::forward<Container>(c)[i])
{
  return std::forward<Container>(c)[i];
}

int main(int argc, char** argv)
{
  std::vector<int> vec;
  for(int i = 0; i != 10; ++i) vec.push_back(i);
  authAndAccess1(vec, 0) = 10;
  // error (cannot be compiled)
  // <==> authAndAccess2(vec, 0);
  authAndAccess3(vec, 0) = 10;
  // it's ok



  class Widget{};
  Widget w;
  const Widget& cw = w;

  auto mywidget1 = cw;
  // it will be Widget type
  decltype(auto) mywidget2 = cw;
  // it's const Widget& type


  int x = 0;
  // no doubtable y will be deduced to type int
  decltype(x) y = 10;
  // z is now a reference points to x
  decltype((x)) z = x;

  int a = 10;
  int* p = &a;

  decltype(&a) p_ = p;
  // p_ is int* type

  decltype(*p) p_ref = a;
  // be cautious !!!
  // decltype(*p) is int& type

}



