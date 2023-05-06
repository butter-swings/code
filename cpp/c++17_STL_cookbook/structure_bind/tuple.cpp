#include <chrono>
#include <stdlib.h>
#include <string>
#include <tuple>

std::tuple<std::string, 
           std::chrono::system_clock::time_point,
           unsigned>
stock_info(const std::string& name);

int main()
{
  const auto [name, valid_time, price] = stock_info("INTC");

  std::tuple<int, float, long> tup(1, 2.0, 3);
  // auto [a, b] = tup;
  // should provide all the elements
  auto [a, b, c] = tup;
}
