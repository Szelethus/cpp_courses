#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(5);
  vec.push_back(5);

  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << '\n';
  }
}
