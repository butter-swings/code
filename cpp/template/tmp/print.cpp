#include <iostream>
#include <utility>
#include <functional>

template <typename T>
class AddSpace
{
  public:
    const T& _ref;
  public:
    AddSpace(const T& ref) : _ref(ref) {}
    friend std::ostream& operator<<(std::ostream& _os, AddSpace addspace)
    {
      return std::cout << addspace._ref << " ";
    }
};

template <typename T, typename ...Args>
void print1(const T& t, const Args&...args)
{
  std::cout << t << " ";
  if constexpr(sizeof...(args) > 0) print(args...);
}

template <typename ...Args>
void print2(Args... args)
{
  (std::cout << ... << AddSpace<Args>(args)) << std::endl;
}

// template <std::size_t N>
// constexpr std::size_t Fatorial(std::size_t num)
// {
//   if constexpr(N == 0) return 1;
//   else return Fatorial(N-1) * N;
// }

int main()
{
  print2(1,1.0,"hello");
}


