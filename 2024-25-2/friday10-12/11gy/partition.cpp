#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  std::stable_partition(v.begin(), v.end(), IsEven{});

  for (int i : v) {
    std::cout << i << '\n';
  }
}
