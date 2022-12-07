#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  // Prefer sort
  std::vector<int> vec{2, 1, 4, 3, 6, 7, 5};
  std::set<int> s{vec.begin(), vec.end()};
  vec.assign(s.begin(), s.end());

  for (int i : vec) {
    std::cout << i << '\n';
  }
}
