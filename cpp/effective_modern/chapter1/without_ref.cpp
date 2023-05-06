template <typename T>
void f(T para);

int main()
{
  int x = 27;
  const int cx = x;
  const int& crx = cx;

  f(x);
  // T --> int
  // para --> int

  f(cx);
  // T --> int
  // para --> int
  // the top const to int was ignored

  f(crx);
  // T --> int
  // para --> int
  // the top const to int was ignored
  // and the same as it's reference attribution

  const char* const str = "Hello World";
  f(str);
  // T --> const char*
  // para --> const char*

  const char s[] = "Hello";
  const char* ptr = s;
  f(s);
  // const char[5] decay
  // --> const char*

  // the reference T& will protect char[] from decaying to char *
  // template <typename T, std::size_t N>
  // void f(T (&) [N] para)
  // {
  //    return N;
  // }
  // the para will contain the length of array, it a true array type(reference)
  //
  //
  // the function type is similar to array type 
  // if T, it will decay to function pointers
  // otherwise it's a reference to function
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// the top const will be ignored
// same as the reference attribution
//
