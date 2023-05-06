template <typename T>
void f(T& para);

int main()
{
  int x = 27;
  const int cx = x;
  const int& crx = cx;

  f(x);
  // T --> int
  // para --> int&

  f(cx);
  // T --> const int
  // para --> const int&

  f(crx);
  // T --> const int
  // para --> const int&
}
// the reference attribution will be ignored
// and the const attribution will be hold
