#include <deque>
#include <iostream>
#include <iterator>
#include <set>

template <class RandAccIter>
void advance(RandAccIter &it, int n, std::random_access_iterator_tag) {
  std::cout << "FAST\n";
  it += n;
}

template <class BidirIter>
void advance(BidirIter &it, int n, std::bidirectional_iterator_tag) {
  std::cout << "SLOW\n";
  for (int i = 0; i < n; ++i) {
    ++it;
  }
}

template <class Iter>
void advance(Iter &it, int n) {
  typename Iter::iterator_category cat;
  advance(it, n, cat);
}

int main() {
  std::set<int> l = {1,2,3,4};
  std::deque<int> v = {1,2,3,4};

  auto lit = l.begin();
  auto vit = v.begin();

  advance(lit, 2);
  advance(vit, 2);
}
