#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> v = {1};

  vec_iter it = v.begin();

  v.push_back(2);

  *it = 10;

  std::cout << v[0] << '\n';
}
