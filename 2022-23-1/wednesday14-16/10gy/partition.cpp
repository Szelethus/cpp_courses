#include <algorithm>
#include <iostream>
#include <vector>

struct IsEven {
  bool operator()(int i) { return i % 2 == 0; }
};

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> vec{3, 2, 4, 1, 5, 7, 6};
  vec_iter it = stable_partition(vec.begin(), vec.end(), IsEven{});

  if (it != vec.end())
    std::cout << *it << '\n' << '\n';

  for (int i : vec) {
    std::cout << i << '\n';
  }
}
