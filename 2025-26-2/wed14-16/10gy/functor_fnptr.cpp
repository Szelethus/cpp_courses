#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

bool is_even(int i) {
  return i % 2 == 0;
}

template <class Iter>
Iter find(Iter begin, Iter end, bool (*op)(int)) {
  for (; begin != end; ++begin)
    if (op(*begin))
      return begin;
  return end;
}

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7};

  vec_iter it = find(v.begin(), v.end(), is_even);

  if (it != v.end())
    std::cout << "Found it!\n";
}
