#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename Cont, typename T>
typename Cont::const_iterator find(const Cont& c, const T& t)
{
  for (typename Cont::const_iterator it = c.begin(); it != c.end(); ++it)
    if (*it == t)
      return it;

  return c.end();
}

template <typename It, typename T>
It find(It b, It e, const T& t)
{
  while (b != e)
  {
    if (*b == t)
      return b;
    ++b;
  }

  return e;
}

template <typename It, typename F>
It find_if(It b, It e, F f)
{
  while (b != e)
  {
    if (f(*b))
      return b;
    ++b;
  }

  return e;
}

const int& max(const int& a, const int& b)
{
  return a < b ? b : a;
}

/*
bool palindrom(It b, It e)
{
(e - b) / 2
}
*/

int main()
{
  // const int& x = max(1, 2);

  std::vector<int> v;
  std::vector<int>::const_iterator i = find(v, 42);
  if (i == v.end())
    std::cout << "Nincs benne" << std::endl;
  else
    std::cout << "Benne van" << std::endl;

  const std::vector<int> cv;
  std::find(cv.begin(), cv.end(), 42);

  std::sort(v.begin(), v.end());

  std::list<int> l;
  //std::sort(l.begin(), l.end());
  l.sort();
}
