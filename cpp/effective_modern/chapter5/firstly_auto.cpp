#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include <functional>
#include <unordered_map>

class Widget
{
  public:
    bool operator>(const Widget& w){ return false; }
};

template <typename Iterator>
void f(Iterator begin, Iterator end)
{
  while (begin != end)
  {
    // typename std::iterator_traits<Iterator>::value_type curValue = *begin;
    // use auto to avoid coding the very long type of std::iterator_traits<Iterator>::value::type
    auto curValue = *begin;
  }
}

// c++11
auto derefUPLess = 
  [](const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2){
    return *p1 > *p2;
  };

// c++14
auto derefLess = 
  [](const auto& p1, const auto& p2){
    return *p1 > *p2;
  };

using func_type = std::function<bool(const std::unique_ptr<Widget>&, 
                                     const std::unique_ptr<Widget>)>;

std::function<bool(const std::unique_ptr<Widget>&, 
                   const std::unique_ptr<Widget>&)> func1 = derefUPLess;

func_type func2 = derefLess;
func_type func3 = derefUPLess;

// !!!!
// use auto rather then the std::function
// if the size is too small for std::function to hold the lambda
// it will cause extra memory size to be allocated on heap
// so use auto to hold lambdas

std::vector<int> v{1, 2, 4};
// unsigned size = v.size();
//
// use auto to deduce std::vector<int>::size_type
auto size = v.size();
// std::vector<int>::size_type size = v.size();
//

std::unordered_map<std::string, int> m;
void test(){
  for (const std::pair<std::string, int> p : m)
  {
    // always convert const std::string to std::string
    // loser!!!!
    // copy always!!!!
    // the element of std::unordered_map<std::string, int> is
    // "std::pair<const std::string, int>"
  }
}

// if use auto
void autoLoop()
{
  for(const auto& p : m)
  {
    // it's ok now
  }
}
