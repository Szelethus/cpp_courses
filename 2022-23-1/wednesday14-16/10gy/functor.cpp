#include <iostream>
#include <vector>

using vec_const_iter = std::vector<int>::const_iterator;

template <class T>
vec_const_iter find(vec_const_iter begin, vec_const_iter end,
                    T pred) {
  for (; begin != end; ++begin) {
    if (pred(*begin))
      return begin;
  }
  return end;
}

struct SecondGreaterThan100 {
  int count = 0;

  bool operator()(int i) {
    if (i > 100)
      count++;
    if (count == 2)
      return true;
    return false;
  }
};

int main() {
  std::vector<int> v = {102, 1, 4, 5, 103};

  vec_const_iter it = find(v.begin(), v.end(), SecondGreaterThan100{});

  if (it != v.end()) {
    std::cout << "Found: " << *it << '\n';
  }

}
