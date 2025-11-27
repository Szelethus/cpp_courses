#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <class Iter>
void my_advance_impl(Iter &it, int offset,
                     std::bidirectional_iterator_tag) {
  for (int i = 0; i < offset; ++i) {
    ++it;
  }
  std::cout << "SLOW\n";
}

template <class Iter>
void my_advance_impl(Iter &it, int offset,
                     std::random_access_iterator_tag) {
  it = it + offset;
  std::cout << "FAST\n";
}

template <class Iter>
void my_advance(Iter &it, int offset) {
  using cat = typename Iter::iterator_category;
  my_advance_impl(it, offset, cat{});
}

int main() {
  std::vector<int> v = {1,2,3,4,5};
  std::list<int> l = {1,2,3,4,5};

  std::vector<int>::iterator vit = v.begin();
  std::list<int>::iterator lit = l.begin();

  my_advance(vit, 3);
  my_advance(lit, 3);
}
