#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }

  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << '\n';
    std::cout << vec.at(i) << '\n';
  }

  for (std::vector<int>::iterator it = vec.begin();
       it != vec.end(); ++it) {
    int &i = *it;
    std::cout << i << '\n';
  }

  for (int &i : vec) {
    std::cout << i << '\n';
  }
}
