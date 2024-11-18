#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <class Iter>
Iter advance(Iter begin, int, std::bidirectional_iterator_tag) {
  std::cout << "SLOW\n";
}
template <class Iter>
Iter advance(Iter begin, int, std::random_access_iterator_tag) {
  std::cout << "FAST\n";
}
template <class Iter>
Iter advance(Iter begin, int end) {
  advance(begin, end, typename Iter::iterator_category{});
}

int main() {
  std::list<int> l = {1,2,3,4};
  std::vector<int> v = {1,2,3,4};
  auto lit = l.begin();
  auto vit = v.begin();

  std::list<int>::iterator::iterator_category cat;

  lit = advance(lit, 2);
  vit = advance(vit, 2);
}
