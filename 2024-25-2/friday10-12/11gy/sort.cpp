#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v{3,0,5,2,1,4};

  std::stable_sort(v.begin(), v.end(), std::greater<int>{});

  for (int i : v) {
    std::cout << i << '\n';
  }
}
