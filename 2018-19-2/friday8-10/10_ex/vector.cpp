#include <vector>
#include <iostream>
#include <list>
#include "list.h"

template <class T>
void addOneToAllElements(T begin, T end) {
  while(begin != end) {
    *begin += 1;
    ++begin;
  }
}

int main() {
  std::vector<int> v;
  std::vector<double> v2;
  std::list<int> l;
  List<double> l2;

  for (int i = 0; i < 10; ++ i) {
    v.push_back(i);
    l.push_back(i);
    v2.push_back(5.6);
    l2.add(5.6);
  }

  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << '\n';
  }
  std::cout << '\n';

  addOneToAllElements(v.begin(), v.end());
  addOneToAllElements(v2.begin(), v2.end());
  addOneToAllElements(l.begin(), l.end());
  addOneToAllElements(l2.begin(), l2.end());

  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << '\n';
  }
  std::cout << '\n';
}
