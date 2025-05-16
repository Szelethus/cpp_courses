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

  auto it = std::remove_if(v.begin(), v.end(), IsEven{});

  std::cout << *it << '\n';
  std::cout << '\n';

  v.erase(it, v.end());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
