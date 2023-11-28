#include <iostream>
#include <list>

template <class Iter, class T>
Iter find(Iter begin, Iter end, T val) {
  for (; begin != end; ++begin) {
    if (*begin == val)
      return begin;
  }
  return end;
}

int main() {
  std::list<int> v = {1,2,3,4,5,6,7,8,9,10};

  std::list<int>::iterator it = find(v.begin(), v.end(), 3);
  if (it != v.end())
    std::cout << *it << '\n';
}
