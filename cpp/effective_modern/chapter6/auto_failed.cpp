#include <vector>

class Widget{};

Widget w;

std::vector<bool> features(const Widget& w);

void processWidget(const Widget& w, bool priority);

int main()
{
  bool highPriority = features(w)[5];
  // it will work correctly
  // features(w)[5] is type "std::vector<bool>::reference"
  // implicit convertion from "std::vector<int>::reference" to "bool"
  // highPriority is bool type


  auto highPriority_failure = features(w)[5];

  // highPriority_failure is std::vector<bool>::reference type
  // because of auto deduction
  // errors happends here
  //
  // features(const Widget&, bool) --> std::vector<bool>
  // the return value is a temporary container
  // after being destructed, danging pointer happends

  // std::vector<int>::reference is like a proxy
  // other similar designs std::bitset::reference
  //
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // shouldn't try to use auto's deduction of proxy type direcly
  //
  // use static_cast< destined type > ( proxy type )
  // to make auto work correctly


  auto highPriority_auto = static_cast<bool>(features(w)[5]);

  processWidget(w, highPriority_failure);
  // undefined behavior
  // danging pointer in highPriority !!

  processWidget(w, highPriority);
  processWidget(w, highPriority_auto); 
  // the two are both OK

  double calculateSomething(double);


  // use this format to show that you try to cast double to float
  // on purpose
  auto result = static_cast<float>(calculateSomething(3.0));

  // rather than
  float r = calculateSomething(3.0);
}
