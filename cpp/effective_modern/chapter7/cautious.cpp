#include <iostream>
#include <utility>
#include <vector>

template <typename _Tp, typename... Args>
_Tp doSomeWork(Args&&... args)
{
  _Tp localObject(std::forward<Args>(args)...);
  // _Tp localObject{std::forward<Args>(args)...}
  return localObject;
}

int main()
{
  auto variable = doSomeWork<std::vector<int>>(10, 20);
  for (const auto& elem : variable)
    std::cout << elem << " ";
}
