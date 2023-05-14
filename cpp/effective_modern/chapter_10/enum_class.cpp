#include <vector>
#include <string>
#include <tuple>
#include <type_traits>

// enum Color{ black, white, red };
// auto white = false;
// error
//
// enum class
// it's OK

enum class Color{ black, white, red };
auto white = false;

// Color c1 = white;
// didn't specify the class
Color c2 = Color::white;
auto  c3 = Color::white;

void testEnum()
{
  enum Color{ black, white, red };
  std::vector<std::size_t>
    primeFactors(std::size_t x);
  
  Color c = red;
  if(c < 14.5)
  {
    auto factors = primeFactors(c);
  }
}

// if enum class 
// static_cast should be used
void testEnumClass()
{
  enum class Color{ black, white, red };
  std::vector<std::size_t>
    primeFactors(std::size_t x);
  
  Color c = Color::red;
  if(static_cast<double>(c) < 14.5)
  {
    auto factors = primeFactors(static_cast<double>(c));
  }
}

// enum class is abled to be forward(propositive) declared
enum class test1;

// microsoft allows forward declared enum
// gcc forbids it
// enum test2;


// if the enum like Color
// usually enum is base of type char
// bottom situation 
// the compiler will choose minimum type which is enough for enum
enum Status 
{
  good = 0,
  failed = 1,
  incomplete = 100,
  corrupt = 200,
  indetermination = 0xFFFFFFFF
};

// when do not use enum class
// a little modify will cause the system to be recompiled
//
//
// when using enum
// it's not necessary
enum class anotherStatus;
void continueProcessing(anotherStatus s);

// the type of enum class is automatically int
// use enum class xxx : type to modify
//
using UserInfo = std::tuple<std::string, std::string, std::size_t>;

UserInfo u = std::make_tuple("xf", "123456@qq.com", 100);
enum UserInfoFields{ uName, uEmail, uReputation };

auto val = std::get<uEmail>(u);

// when using enum class
// static_cast should be used
void fields()
{
  enum class UserInfoFields{ uName, uEmail, uReputation };
  UserInfo u = std::make_tuple("xf", "123456@qq.com", 100);
  auto val = std::get<static_cast<std::size_t>(UserInfoFields::uEmail)>(u);
}

// it's too uncomfortable to use enum class
// we can try to deal with it

// c++11
template <typename E>
constexpr typename std::underlying_type<E>::type
  toUType1(E enumerator) noexcept
{
  return static_cast<typename std::underlying_type<E>::type>(enumerator);
}

// c++14
template <typename E>
constexpr std::underlying_type_t<E>
  toUType2(E enumerator) noexcept
{
  return static_cast<std::underlying_type_t<E>>(enumerator);
}


// auto can also be used to automatically deduce the return type
template <typename E>
constexpr auto toUType3(E enumerator) noexcept
{
  return static_cast<std::underlying_type_t<E>>(enumerator);
}

enum class USER{ name, email, reputation };
auto get_val = std::get<toUType3(USER::email)>(u);

