#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

template <class UnaryPred>
vec_iter find(std::vector<int> &v, UnaryPred op) {
  for (vec_iter it = v.begin(); it != v.end(); ++it) {
    if (op(*it))
      return it;
  }
  return v.end();
}

struct IsSecondEven {
  int count = 0;

  bool operator()(int i) {
    if (i % 2 == 0) {
      ++count;
      if (count == 2)
        return true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1,2,3,4,5,6};

  vec_iter it = find(v, IsSecondEven());

  if (it == v.end())
    return -1;

  std::cout << *it << '\n';
}
