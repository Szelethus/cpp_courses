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
  std::vector<int> v = {1,2,3,4,5,6,8};

  removeEven(v);

  for (int &i : v)
    std::cout << i << '\n';
}
