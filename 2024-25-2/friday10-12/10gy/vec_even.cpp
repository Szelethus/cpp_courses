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
  std::vector<int> vec = {1,2,3,4,5,6};

  removeEven(vec);

  for (int i : vec)
    std::cout << i << '\n';
}
