#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << '\n';
  }

  for (int i = 0; i < v.size(); ++i) {
    // safe getter
    std::cout << v.at(i) << '\n';
  }

  for (vec_iter it = v.begin(); it != v.end(); ++it) {
    int i = *it;
    std::cout << i << '\n';
  }

  for (int i : v) {
    std::cout << i << '\n';
  }

  auto it2 = v.begin();
}
