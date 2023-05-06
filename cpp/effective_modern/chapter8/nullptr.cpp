#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <mutex>
#include <utility>

class Widget{};

void f(int){ printf("called 'void f(int)'\n"); }
void f(void*){ printf("called 'void f(void*)'\n"); }
// void f(bool){ printf("called 'void f(bool)'\n"); }

int f1(std::shared_ptr<Widget> spw);
double f2(std::unique_ptr<Widget> upw);
bool f3(Widget* pw);

// c++11
template <typename FuncType,
          typename MuxType,
          typename PtrType>
auto lockAndCall(FuncType func,
                 MuxType&& mutex,
                 PtrType ptr) -> decltype(func(ptr))
{
  MuxType g(mutex);
  return func(ptr);
}

template <typename FuncType,
          typename MuxType,
          typename PtrType>
decltype(auto) lockAndCall_cpp14(FuncType func,
                                 MuxType& mutex,
                                 PtrType ptr)
{
  MuxType g(mutex);
  return func(ptr);
}

int main()
{
  f(0);

  // ambiguous 
  // int and void*
  // f(NULL);

  // called void f(void*)
  f(nullptr);

  std::mutex f1m, f2m, f3m;
  using MuxGuard = 
    std::lock_guard<std::mutex>;

  {
    MuxGuard g(f1m);
    auto result = f1(0);
  }
  // ...
  {
    MuxGuard g(f2m);
    auto result = f2(NULL);
  }
  // ...
  {
    MuxGuard g(f3m);
    auto result = f3(nullptr);
  }
  // the three are all ok
  // but nullptr is recommend



  // here comes the differences

  // error 0 can not be converted to std::shared_ptr
  // auto result1 = lockAndCall(f1, f1m, 0);

  // error NULL can not be converted to std::unique_ptr
  // auto result2 = lockAndCall(f2, f2m, NULL);

  // OK nullptr can be converted to Widget*
  auto result3 = lockAndCall(f3, f3m, nullptr);
}
