#include <algorithm>
#include <iostream>
#include <vector>

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> vec {1, 2, 3, 4, 5};
  std::stable_partition(vec.begin(), vec.end(), IsEven{});

  for (int i : vec) {
    std::cout << i << '\n';
  }
}
