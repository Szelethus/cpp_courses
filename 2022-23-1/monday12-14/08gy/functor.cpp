#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::const_iterator;

template <class Pred>
vec_iter find(const std::vector<int> &vec, Pred pred) {
  for (vec_iter it = vec.begin(); it != vec.end(); ++it) {
    if (pred(*it))
      return it;
  }
  return vec.end();
}

bool is5(int i) {
  return i == 5;
}

// Funktorok
struct SecondGreaterThan3 {
  int count = 0;

  bool operator()(int i) {
    if (i > 3)
      count++;
    if (count == 2)
      return true;
    return false;
  }
};

int main() {
  std::vector<int> vec = {1,2,3,4,5,6};
  vec_iter ret = find(vec, SecondGreaterThan3{});
  if (ret != vec.end()) {
    std::cout << *ret << '\n';
  }
}
