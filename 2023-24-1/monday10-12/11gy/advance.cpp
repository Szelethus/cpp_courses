#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <class Iter>
Iter advance_impl(Iter it, int count,
                  std::bidirectional_iterator_tag) {
  std::cout << "SLOW\n";
  for (int i = 0; i < count; ++i)
    ++it;
  return it;
}

template <class Iter>
Iter advance_impl(Iter it, int count,
                  std::random_access_iterator_tag) {
  std::cout << "FAST\n";
  return it + count;
}

template <class Iter>
Iter advance(Iter it, int count) {
  typename Iter::iterator_category cat;

  return advance_impl(it, count, cat);
}

int main() {
  std::list<int> l = {1,2,3,4};
  std::vector<int> v = {1,2,3,4};
  auto lit = l.begin();
  auto vit = v.begin();

  lit = advance(lit, 2);
  vit = advance(vit, 2);
}
