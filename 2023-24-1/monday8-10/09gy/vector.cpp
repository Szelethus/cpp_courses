#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

void removeOdd(std::vector<int> &v) {
  for (vec_iter it = v.begin(); it != v.end();) {
    if (*it % 2 == 1)
      it = v.erase(it);
    else
      ++it;
  }
}

void print(std::vector<int> &v) {
  for (int i : v)
    std::cout << i << '\n';
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  removeOdd(v);
  print(v);


  for (int i = 0; i < 100; ++i)
    v.push_back(i);

  vec_iter it = v.begin() + 1;
  v.erase(it);
}
