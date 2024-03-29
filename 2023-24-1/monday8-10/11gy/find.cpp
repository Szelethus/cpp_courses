#include <iostream>
#include <vector>
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
  std::list<int> v = {1,2,3,4,5,3};
  auto it = find(v.begin(), v.end(), 3);
  if (it != v.end())
    std::cout << *it << '\n';
}
