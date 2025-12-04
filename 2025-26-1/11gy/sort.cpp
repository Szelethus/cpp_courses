#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v = {4, 3, 1, 2, 5};

  std::sort(v.begin(), v.end(), std::greater<int>{});

  for (auto &i : v) {
    std::cout << i << '\n';
  }
}
