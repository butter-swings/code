// auto 
// the deduction of auto is the same as template para in chapter1
// except initializer_list (the {} constructor)

// only auto ? = ???
// the initializer_list deduction will work
//
// both auto func(){} in c++14
// and auto in lambdas in c++14(generic lambdas)
// !!!!!!!! the deduction can not deduce the initializer_list type

auto createInitialList()
{
  // return {1, 2, 3};
}
// cannot deduce return type from initializerlist

#include <vector>
std::vector<int> v;
auto resetV = [](const auto& newValue){ v = newValue; };

void testResetV()
{
  // resetV({1, 2, 3});
  // no matching function
}

#include <initializer_list>

auto x = 27;
const auto cx = x;
const auto& crx = x;

// the auto's behavior is like the template
template <typename T>
void func_for_x(T para);

template <typename T>
void func_for_cx(const T para);

template <typename T>
void func_for_crx(const T& para);

void test()
{
  func_for_x(27);
  // T --> int
  // para --> int
  func_for_cx(x);
  // T --> int
  // para --> const int
  func_for_crx(x);
  // T --> int
  // para --> const int&
}

void universal_ref_auto()
{
  auto&& uref1 = 27; // int&&
  auto&& uref2 = x;  // int&
  auto&& uref3 = cx; // const int&
  auto&& uref4 = crx;// const int&
}

void decay_or_not()
{
  const char str[] = "Hello World!";
  auto arr1 = str;
  // decay to const char*
  auto& arr2 = str;
  // non-decay 
  // const char (&)[std::strlen(str)]

  void someFunc(int, double);
  auto func1 = someFunc;
  // decay void(*)(int, double)
  auto& func2 = someFunc;
  // non-decay
  // void(&)(int, double)
}

template <typename T>
void f(T para);

template <typename T>
void f(std::initializer_list<T> initList);

int main()
{
  // auto x = { 1, 2, 3.0 };
  // the initializer_list doesn't allow double --> int(8bytes --> 4bytes)
  auto x = {1};
  auto x_parallel{1};
  // x is not the type of int
  // actually it's initializer_list<int>
  // value is {1}

  auto true_x(1);
  // true_x is the type of int

  f({1, 23, 5});
  // calls 
  // template <typename T>
  // void f(std::initializer_list<T> initList);
  // line 63
  // if not initializer_list it will be error
}
