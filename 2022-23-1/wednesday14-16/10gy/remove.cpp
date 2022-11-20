#include <algorithm>
#include <iostream>
#include <vector>

struct IsEven {
  bool operator()(int i) { return i % 2 == 0; }
};

using vec_iter = std::vector<int>::iterator;

int main() {
  std::vector<int> vec{3, 2, 4, 1, 5, 7, 6};
  std::cout << vec.size() << '\n';
  vec_iter new_end = std::remove_if(vec.begin(), vec.end(), IsEven{});
  vec.erase(new_end, vec.end());
  std::cout << vec.size() << '\n';

  std::cout << '\n';

  for (int i : vec) {
    std::cout << i << '\n';
  }
}
