#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> vec; 
  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }

  vec_iter it = vec.begin();

  for (int i = 0; i < 10000; ++i) 
    vec.push_back(i);
  
  *it = 30;

  std::cout << vec[0] << '\n';
}
