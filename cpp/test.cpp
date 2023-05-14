#include <iostream>

template <typename Arg>
class AddSpace
{
public:
  AddSpace(const Arg& arg) : _ref(arg) {}

  friend std::ostream& operator<<(std::ostream& _os, const AddSpace& add_space)
  {
    return _os << add_space._ref << " ";
  }

private:
  const Arg& _ref;
};

template <typename... Args>
void print(Args... args)
{
  (std::cout << ... << AddSpace<Args>(args)) << std::endl;
}

int main(int argc, char* argv[])
{
  print(1, 0.3, "hello");
  return 0;
}
