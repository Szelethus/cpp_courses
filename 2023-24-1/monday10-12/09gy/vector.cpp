#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

void removeEven(std::vector<int> &v) {
  vec_iter it = v.begin();
  while (it != v.end()) {
    if (*it % 2 == 0)
      it = v.erase(it);
    else
      ++it;
  }
}

int main() {
  std::vector<int> v;
  v.reserve(6);

  for (int i = 1; i <= 6; ++i) {
    v.push_back(i);
    std::cout << "size: " << v.size() << '\n';
    std::cout << "capacity: " << v.capacity() << '\n';
  }

  vec_iter it = v.begin();

  for (int i = 0; i < 1000; ++i)
    v.push_back(i);

  v.erase(it);

  for (int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << '\n';

  //removeEven(v);
  //std::cout << '\n';

  //for (int i = 0; i < v.size(); ++i)
  //  std::cout << v.at(i) << '\n';

  // for (vec_iter it = v.begin(); it != v.end(); ++it) {
  //   int i = *it;
  //   std::cout << i << '\n';
  // }

  // for (int &i : v)
  //   std::cout << i << '\n';
}
