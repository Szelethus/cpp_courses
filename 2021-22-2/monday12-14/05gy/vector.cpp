#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(7);
  vec.push_back(7);
  vec.push_back(7);

  std::cout << "vec.size(): " << vec.size() << '\n';
  std::cout << "vec.capacity(): " << vec.capacity() << '\n';

  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec.at(i) << ' ';
  }

  std::cout << '\n';
}
