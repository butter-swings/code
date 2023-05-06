#include <vector>

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


enum Status 
{
  good = 0,
  failed = 1,

};
