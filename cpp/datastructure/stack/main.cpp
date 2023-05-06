#include "stack.hpp"

int main()
{
  stack<int> st;
  for (int i = 0; i != 10; ++i)
  {
    st.push(i);
  }
  while (!st.empty())
  {
    std::clog << st.top() << " ";
    st.pop();
  }
  return 0;
}
