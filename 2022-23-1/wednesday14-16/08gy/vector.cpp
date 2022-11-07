#include <iostream>
#include <vector>

void printVec(const std::vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << '\n';
  }
}

void removeOdd(std::vector<int> &vec) {
  for (auto it = vec.begin(); it != vec.end();) {
    if (*it % 2 == 1)
      it = vec.erase(it);
    else
      ++it;
  }
}

int main() {
  std::vector<int> vec = {0, 1, 2, 3};

  std::vector<int>::iterator it = vec.begin();

  for (int i = 0; i < 10; ++i)
    vec.push_back(i);

  removeOdd(vec);
  printVec(vec);

  // for (std::vector<int>::iterator it = vec.begin(); it < vec.end();
  //     ++it) {
  //   std::cout << *it << '\n';
  // }

  // for (auto it = vec.begin(); it < vec.end(); ++it) {
  //   int i = *it;
  //   std::cout << *it << '\n';
  // }

  // for (int i : vec) {
  //   std::cout << i << '\n';
  // }
}
