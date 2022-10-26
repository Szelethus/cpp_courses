#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

void printVecInfo(const std::vector<int> &vec) {
  std::cout << "size " << vec.size() << '\n';
  std::cout << "cap " << vec.capacity() << '\n';

  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << '\n';
  }
}

void removeOdd(std::vector<int> &vec) {
  for (vec_iter it = vec.begin(); it != vec.end();) {
    if (*it % 2 == 1)
      it = vec.erase(it);
    else
      ++it;
  }
}

int main() {
  std::vector<int> vec;

  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }

  vec_iter it = vec.begin();
  //*it = 100;

  removeOdd(vec);
  printVecInfo(vec);

  //vec.push_back(4);
  //*it = 200;

  //printVecInfo(vec);
  //for (auto it = vec.begin(); it != vec.end(); ++it) {
  //  std::cout << *it << '\n';
  //}

  //for (vec_iter it = vec.begin(); it != vec.end(); ++it) {
  //  auto i = *it;
  //  std::cout << i << '\n';
  //}

  //for (auto i : vec) {
  //  std::cout << i << '\n';
  //}


}
