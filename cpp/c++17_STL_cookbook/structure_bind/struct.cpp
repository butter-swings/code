#include <vector>
#include <string>
#include <iostream>

struct employee
{
  unsigned id;
  std::string name;
  std::string role;
  unsigned salary;
};

int main()
{
  std::vector<employee> employees{
    {0, "xf", "rbq", 0}
  };
  for (const auto& [id, name, role, salary] : employees)
  {
    std::cout << "Name: " << name
              << "Role: " << role
              << "salary" << salary << '\n';
  }
}
