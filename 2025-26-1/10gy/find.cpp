#include <iostream>
#include <list>
#include <vector>

template <class Iter, class T>
Iter find(Iter begin, Iter end, T val) {
  for (; begin != end; ++begin) {
    if (*begin == val)
      return begin;
  }
  return end;
}

int main() {
  std::vector<int> v = {1,2,3,4,5};
  std::list<std::string> l = {"a", "b", "c"};

  std::vector<int>::iterator it1 = find(v.begin(), v.end(), 3);
  std::list<std::string>::iterator it2 =
                                   find(l.begin(), l.end(), "a");
}
