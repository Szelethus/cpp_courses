#include <iostream>
#include <vector>
#include <algorithm>

using vec_iter = std::vector<int>::iterator;

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {4, 3, 1, 2, 5};

  vec_iter it = std::remove_if(v.begin(), v.end(), IsEven{});

  v.erase(it, v.end());

  for (auto &i : v) {
    std::cout << i << '\n';
  }
}
