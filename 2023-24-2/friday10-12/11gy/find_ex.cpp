#include <iostream>
#include <list>
#include <vector>

template <class Iter, class T> Iter find(Iter begin, Iter end, T value) {
  for (; begin != end; ++begin) {
    if (*begin == 3)
      return begin;
  }
  return end;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};
  std::vector<int>::iterator it1 = find(v.begin(), v.end(), 3);

  if (it1 == v.end())
    return -1;

  std::cout << *it1 << '\n';

  std::list<int> l = {1, 2, 3, 4, 5, 3};
  std::list<int>::iterator it2 = find(l.begin(), l.end(), 3);

  if (it2 == l.end())
    return -1;

  std::cout << *it2 << '\n';
}
