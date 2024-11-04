#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> v;

  for (int i = 0; i < 32; ++i) {
    v.push_back(i);

    std::cout << "size: " << v.size() << '\n';
    std::cout << "capacity: " << v.capacity() << '\n';
  }

  vec_iter it = v.begin();

  for (int i = 0; i < 1000; ++i)
    v.push_back(i);

  *it = 8;

  std::cout << v[0] << '\n';
}
