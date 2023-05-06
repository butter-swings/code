#include <iostream>
#include <type_traits>
#include <utility>
#include <string>

template <typename T>
using typeToString = typename std::enable_if<std::is_convertible<T, std::string>::value>::type;

// template <typename T>
// concept test = std::is_convertible<T, std::string>::value;

class Person
{
  public:

    // template <typename Arg, typename = typeToString<Arg>>
    //
    // or
    // template <typename Arg>
    // requires test<Arg>
    //
    template< typename Arg, typename = std::enable_if_t< 
                                       std::is_convertible_v< Arg, std::string > > >
    Person(Arg&& arg) : _name( std::forward<Arg>(arg) ) { }

    // template <typename Arg,
    //           typename = typename std::enable_if<
    //                               std::is_convertible<Arg, std::string>::value>::type>
    // Person(Arg&& arg) : _name( std::forward<Arg>(arg) ) { }

    Person(const Person& person) { _name = person._name; }
    Person(Person&& person) { _name = std::move(person._name); }

    friend std::ostream& operator << (std::ostream& _os, const Person& person) 
    { 
      return std::cout << "this person is: " 
                       << person._name; 
    }

  private:
    std::string _name;
};

int main()
{
  Person p1("hello");
  Person p2(p1);
  std::cout << p1 << std::endl 
            << p2 << std::endl 
            << "after moving" << std::endl;
  Person p3(std::move(p1));
  std::cout << p1 << std::endl
            << p3;
}
