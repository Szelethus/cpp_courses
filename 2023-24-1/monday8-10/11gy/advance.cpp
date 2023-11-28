#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <class Category>
struct is_random_access {
  static const bool value = false;
};

template <>
struct is_random_access<std::random_access_iterator_tag> {
  static const bool value = true;
};

template <class Iter>
struct is_iterator_random_access {
  static const bool value =
    is_random_access<typename Iter::iterator_category>::value;
};

template <class Iter>
Iter advance_fast(Iter it, int count) {
  std::cout << "Fast\n";
  return it + count;
}

template <class Iter>
Iter advance_slow(Iter it, int count) {
  while (count > 0) {
    it++;
    count--;
  }
  std::cout << "Slow\n";
  return it;
}

template <class Iter>
Iter advance(Iter it, int count) {
  if constexpr (is_iterator_random_access<Iter>::value)
    return advance_fast(it, count);
  return advance_slow(it, count);
}

int main() {
  std::list<int> l = {1,2,3,4};
  std::vector<int> v = {1,2,3,4};
  auto lit = l.begin();
  auto vit = v.begin();

  lit = advance(lit, 2);
  vit = advance(vit, 2);

}
