#include <atomic>
#include <cstdio>
#include <initializer_list>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Widget
{
  Widget& operator = (const Widget& w);

  Widget(const Widget& w) = default;
  Widget() = default;
  Widget(int para);
};

int x{}; 
// zero initialization
// <==> int x = {};

int y = 0;
int z(0);
// not int z();
// it's function declare

int main()
{
  Widget w1;
  // default constructor

  Widget w2 = w1;
  // copy constructor
  // not operator = 

  w1 = w2;
  // operator = 

  std::vector<int> v = { 1, 2, 5 };
  // <==> std::vector><int>{ 1, 2, 5 };

  class Widget
  {
    // initialization for non-static members
    private:
      int x{0};    // OK
      int y = 0;   // OK
      // int z(0); // failure
  };

  // some type can be initialized by both () and {} 
  // but cannot by = initialization
  // like std::atomic
  std::atomic<int> ai1{ 0 }; // OK
  std::atomic<int> ai2( 0 ); // OK

  // std::atomic<int> ai3 = 0;
  // failure

  // when using {} initialization
  // narrowing conversion is forbidden
  double x, y ,z;
  // int sum1{ x + y + z };
  // error happened
  
  // () initialization allows narrowing conversion
  int sum2 = x + y + z;
  int sum3( x + y + z );

  ::Widget w_1(10);
  ::Widget w_2(); // be cautious
                  // it's a function declare

  ::Widget w_3{}; // call the default constructor
                  // it's OK
}

void test1()
{
  class Widget
  {
    public:
      Widget(int i, bool b){}
      Widget(int i, double d){}
      Widget(std::initializer_list<long double> il){}
  };
  
  Widget w1(10, true);
  // called Widget(int i, bool b)
  Widget w2{10, true};
  // implicit conversion from bool to long double
  // called Widget(std::initializer_list<long double> il)


  Widget w3(10, 5.0);
  // called Widget(int i, double d)
  Widget w4{10, 5.0};
  // called Widget(std::initializer_list<long double> il) 
  
}

void test2()
{
  class Widget
  {
    public:
      Widget(int i, bool b){}
      Widget(int i, double d){}
      Widget(std::initializer_list<long double>){}
      Widget() = default;

      operator float(){ return 0.0; }
  };
  Widget w4;

  Widget w5(w4);
  // copy constructor
  Widget w6{w4};
  // implicit conversion from Widget to float,
  // then float will be improve to double
  // call Widget(std::initializer_list<long double>)

  Widget(std::move(w4));
  // move constructor
  Widget{std::move(w4)};
  // same as top
  // call Widget(std::initializer_list<long double>)
}

void test3()
{
  class Widget
  {
    public:
      Widget(int i, bool b){}
      Widget(int i, double d){}
      Widget(std::initializer_list<bool>){}
  };
  // Widget{10, 5.0};
  // narrowing is not allowed here
  // std::initializer_list<bool> exactly matching {10, 5.0}
}

void test4()
{
  class Widget
  {
    public:
      Widget(int i, bool b){}
      Widget(int i, double d){}
      Widget(std::initializer_list<std::string>){}
  };
  Widget w1(10, true);
  Widget w2{10, true};
  Widget w3(10, 5.0);
  Widget w4{10, 5.0};
  // conversion from int or double to std::string is not exists
  // here constructors will be called correctly
}

void test5()
{
  class Widget
  {
    public:
      Widget(std::initializer_list<long double>){}
      Widget() = default;
  };

  // when default constructor and initializer_list constructor
  // are both exist 
  // the default constructor is always called
  // to construct a default object

  Widget w1;
  // default constructor
  Widget w2{};
  // default constructor
  Widget w3();
  // function declare

  // if initializer_list constructor is needed
  // we can
  Widget w4({});
  Widget w5{{}};
  // called initializer_list constructor
}

std::vector<int> v1{10, 20};
// vector contains 10 and 20
std::vector<int> v2(10, 20);
// vector contains ten elements of 20
