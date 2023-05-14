#include <memory>

class Base
{
public:
  virtual void doWork();
};

class Derived : public Base
{
  virtual void doWork();
};

int main(int argc, char *argv[])
{
  std::unique_ptr<Base> upb = std::make_unique<Derived>();
  return 0;
}
