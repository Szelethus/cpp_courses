#include <vector>
#include <iostream>

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> vec;

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  
  for (int i = 0; i < vec.size(); ++i) 
    std::cout << vec[i] << '\n';
  
  // biztonságosabb
  for (int i = 0; i < vec.size(); ++i) 
    std::cout << vec.at(i) << '\n';

  for (vec_iter it = vec.begin(); it != vec.end(); ++it) {
    int i = *it;
    std::cout << i << '\n';
  }

  // foreach
  for (int i : vec) {
    std::cout << i << '\n';
  }
}
