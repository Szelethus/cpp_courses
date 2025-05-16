#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> vec;

  for (int i = 0; i < 64; ++i) {
    vec.push_back(i);
    std::cout << "size(): " << vec.size() << '\n';
    std::cout << "capacity(): " << vec.capacity() << '\n';
  }

  std::cout << "before modification: " << vec[0] << '\n';
  
  vec_iter it = vec.begin();
  vec.push_back(5);
  *it = 999;
  
  std::cout << "after  modification: " << vec[0] << '\n';
}
