#include <iostream>
#include <utility>

std::pair<int, int> divide_remainder(int dividend, int divisor)
{
  int a = dividend / divisor;
  int b = dividend - a * divisor;
  return std::make_pair(a, b);
}

int main()
{
  // usually
  const auto result(divide_remainder(16, 3));
  std::cout <<  "16 / 3 is "
            << result.first  << " with a remainder of "
            << result.second << '\n';
  // structure bind
  auto [fraction, remainder] = divide_remainder(16, 3);
  std::cout <<  "16 / 3 is "
            << fraction  << " with a remainder of "
            << remainder << '\n';
}
