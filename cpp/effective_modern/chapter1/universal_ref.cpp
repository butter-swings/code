template <typename T>
void f(T&& para);

int main()
{
  int x = 27;
  const int cx = x;
  const int& crx = cx;

  f(x);
  // T --> int&
  // para --> int& && --> int&

  f(cx);
  // T --> const int&
  // para --> const int& && --> const int&

  f(crx);
  // T --> const int&
  // para --> const int& && --> const int&

  f(11);
  // T --> int
  // para --> int&&
}

// when deducing lvalue, T is always a reference(&), 
// and the const attribution will be hold
// if the call para is a rvalue, T will be pure type, 
// and the para will be a reference(&&)
