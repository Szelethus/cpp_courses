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

  for (int i = 0; i < 8; ++i) {
    v.push_back(i);
    //std::cout << "size: " <<  v.size() << '\n';
    //std::cout << "capacity: " << v.capacity() << '\n';
  }

  for (int i : v) {
    std::cout << i << '\n';
  }

  removeEven(v);
  std::cout << "after removal:\n";

  for (int i : v) {
    std::cout << i << '\n';
  }
}
