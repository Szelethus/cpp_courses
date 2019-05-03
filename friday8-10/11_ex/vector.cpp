#include <vector>
#include <iostream>
#include <list>
#include "list.h"

template <class T>
struct Incr {
  int count;

  Incr() : count(0) {}

  void operator()(T &i) {
    ++count;
    if (count == 2)
      ++i;
  }
};

template <class T, class Operand>
void forEach(T begin, T end, Operand op) {
  while(begin != end) {
    op(*begin);
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

  forEach(v.begin(), v.end(), Incr<int>());
  forEach(v2.begin(), v2.end(), Incr<double>());
  forEach(l.begin(), l.end(), Incr<int>());
  forEach(l2.begin(), l2.end(), Incr<double>());

  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << '\n';
  }
  std::cout << '\n';
}
