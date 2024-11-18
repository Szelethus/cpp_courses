#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>

template <class BidirIter>
BidirIter advance(BidirIter it, int n, std::bidirectional_iterator_tag) {
  std::cout << "SLOW\n";
  for (int i = 0; i < n; ++i)
    ++it;
  return it;
}

template <class RandIter>
RandIter advance(RandIter it, int n, std::random_access_iterator_tag) {
  std::cout << "FAST\n";
  return it + n;
}

template <class Iter>
Iter advance(Iter it, int n) {
  typename Iter::iterator_category cat;
  return advance(it, n, cat);
}

int main() {
  std::set<int> l = {1,2,3,4};
  std::vector<int> v = {1,2,3,4};

  auto lit = l.begin();
  auto vit = v.begin();

  lit = advance(lit, 2);
  vit = advance(vit, 2);
}
