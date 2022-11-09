#include <iostream>
#include <set>

//template <class Iter>
//void printRange(Iter begin, Iter end) {
//  for (; begin != end; ++begin)
//    std::cout << *begin << '\n';
//}

using set_iter = std::set<int>::iterator;
using set_const_iter = std::set<int>::const_iterator;

void printSet(const std::set<int> &set) {
  for (set_iter it = set.begin(); it != set.end(); ++it) {
    std::cout << *it << '\n';
  }
}
