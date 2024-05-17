#include <iostream>
#include <vector>
#include <list>

template <class Iter, class T>
Iter find(Iter begin, Iter end, T val) {
  for (Iter it = begin; it != end; ++it) {
    if (*it == val)
      return it;
  }

  return end;
}

int main() {
  std::vector<int> v = {1,2,3,4,3,10};

  std::vector<int>::iterator it1 = find(v.begin(), v.end(), 3);
  if (it1 == v.end()) {
    std::cout << "not found\n";
  }

  std::cout << *it1 << '\n';

  std::list<int> l = {1,2,3,4,3,10};

  auto it2 = find(l.begin(), l.end(), 3);
  if (it2 == l.end()) {
    std::cout << "not found\n";
  }

  std::cout << *it2 << '\n';
}
