template <typename T>
void f(const T& para);

int main()
{
  int x = 27;
  const int cx = x;
  const int& crx = cx;

  f(x);
  // T --> int
  // para --> const int&

  f(cx);
  // T --> int
  // para --> const int&

  f(crx);
  // T --> int
  // para --> const int&
}
// same as the T&& situation
// the reference attribution will be ignored
