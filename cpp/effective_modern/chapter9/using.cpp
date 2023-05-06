#include <list>
#include <type_traits>
#include <unordered_map>
#include <memory>
#include <string>

// it seems both are OK
typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

// when define uncomplete type
// it's a disaster
typedef void (*FP)(int, const std::string&);

// oh it's very cool
using FP = void(*)(int, const std::string&);

// when using typedef u cannot use template

template <typename T>
class MyAlloc : public std::allocator<T>{ };

class Widget{ };

// using with template
template <typename T>
using MyAllocList1 = std::list<T, MyAlloc<T>>;

MyAllocList1<Widget> lw1;

// when using typedef
// it cannot be so easy
// you should
template <typename T>
struct MyAllocList2
{
  typedef std::list<T, MyAlloc<T>> type;
};

MyAllocList2<Widget>::type lw2;

// if you need to use lw2 in a class
// unluckily typename keyword should be provided
template <typename T>
class teste
{
private:
  // with typename
  typename MyAllocList2<T>::type list1;
  // alias template
  MyAllocList1<T> list2;
};
// if without typename keyword
// the compiler will try to explain ::type as a class member

// so usually it's bottom situation
class Wine{ };

template <typename T>
class MyAllocList
{
public:
  using type = std::list<T, MyAlloc<T>>;
};

template < >
class MyAllocList<Wine>
{

private:
  enum class WineType{ White, Red, Rose };
  WineType type;
  // type is not a type here
};

// alias template
// example
//
//
// c++14
// std::remove_reference_t<type>
// =>
// namespace std
// {
//    template <typename T>
//    using remove_reference_t = typename remove_reference<T>::type
// }
//
//
// c++11
// std::remove_reference<type>::type


int main()
{
}


