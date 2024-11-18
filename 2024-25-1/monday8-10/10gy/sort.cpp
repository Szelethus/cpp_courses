#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

struct Desc {
  bool operator()(int lhs, int rhs) const {
    return lhs > rhs;
  }
};

int main() {
  std::vector<int> v{3,2,5,4,1,6,8,7};

  std::sort(v.begin(), v.end(), std::greater<int>{});

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << '\n';
  }
}
