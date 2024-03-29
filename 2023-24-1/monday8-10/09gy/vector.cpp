#include <cstdlib>
#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

void removeEven(std::vector<int> &v) {
  for (vec_iter it = v.begin(); it != v.end();) {
    if (*it % 2 == 0)
      it = v.erase(it);
    else
      ++it;
  }
}

int main() {
  std::vector<int> v;

  for (int i = 1; i <= 7; ++i) {
    v.push_back(i);
    std::cout << "size: " << v.size() << '\n';
    std::cout << "capacity: " << v.capacity() << '\n';
  }

  vec_iter it = v.begin();

  for (int i = 0; i < 100; ++i)
    v.push_back(i);

  v.erase(it);

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << '\n';
  }

  removeEven(v);

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << '\n';
  }

  //for (vec_iter it = v.begin(); it != v.end(); ++it) {
  //  std::cout << *it << '\n';
  //}

  //// c++11
  //for (auto &i : v) {
  //  std::cout << i << '\n';
  //}
}
