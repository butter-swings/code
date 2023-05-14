class non_copyable_private
{
public:
  non_copyable_private() = default;
private:
  non_copyable_private(const non_copyable_private& rhs);
  non_copyable_private& operator=(const non_copyable_private& rhs);
};

class non_copyable_delete
{
public:
  non_copyable_delete() = default;
  non_copyable_delete(const non_copyable_delete& rhs) = delete;
  non_copyable_delete& operator=(const non_copyable_delete& rhs) = delete;
};

// delete function overload which we don't need
bool isLucky(int number);
bool isLucky(char) = delete;
bool isLucky(double) = delete;
bool isLucky(bool) = delete;

// forbid template instantiation which we don't need
template <typename T>
void processPointer(T* ptr);

// usually char* like is a str
// void* is a special pointer
// both need to be address specially
template < >
void processPointer(char*) = delete;

template < >
void processPointer(void*) = delete;
// is void and char are illegal
// is the same as const void* and const char*

template < >
void processPointer(const void*);

template < >
void processPointer(const char*);

// ----------------------------------------
class Widget
{
public:
  template <typename T>
  void processPointer(T* ptr){}

private:
  // template < >
  // void processPointer(void*);
  // though it doesn's cause synax error
  // it will be error when compiling
  // invalid
};

// we should do like bottom
template < >
void Widget::processPointer(void*) = delete;


int main()
{
  non_copyable_private pri_rhs{};

  // calling a private constructor
  // non_copyable_private pri(pri_rhs);

  non_copyable_delete del_rhs{};

  // calling a deleted constructor
  // non_copyable_delete del(del_rhs);

  isLucky(1);

  // called deleted functions
  // isLucky(true);
  // isLucky('a');
  // isLucky(3.0);
}
