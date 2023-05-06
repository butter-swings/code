#include <type_traits>

template <typename T>
struct AccumulationTraits;

template < >
struct AccumulationTraits<char>
{
  using type = int;
  const static type value = 0;
};

template < >
struct AccumulationTraits<int>
{
  using type = int;
  const static type value = 0;
};

template <typename T, std::size_t N>
constexpr std::size_t _arrLength(T (&)[N])
{
  return N;
}

template <typename T, typename accumu_traits = AccumulationTraits<T> >
auto accumulate(const T* begin, const T* end)
{
  typename accumu_traits::type total = accumu_traits::value;
  while (begin != end)
  {
    total += *begin++;
  }
  return total;
}

template <typename T>
T* begin(T (&__arr)[]) noexcept(noexcept(end(__arr)));

template <typename T, std::size_t N>
T* end(T (&_arr)[N]) noexcept(noexcept(begin(std::add_lvalue_reference_t<T [N]>(_arr))));

template <typename T>
T* begin(T (&_arr)[]) noexcept(noexcept(end(_arr)))
{
  return static_cast<T*>(_arr);
}

template <typename T, std::size_t N>
T* end(T (&_arr)[N]) noexcept(noexcept(begin(std::add_lvalue_reference_t<T [N]>(_arr))))
{
  return static_cast<T*>(_arr) + N - 1;
}
