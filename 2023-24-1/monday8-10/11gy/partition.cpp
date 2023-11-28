#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct Even {
  bool operator()(int i) { return i % 2 == 0; }
};

int main() {
  std::vector<int> v = {5,2,3,1,6,4,8,7};

  auto it = std::stable_partition(v.begin(), v.end(), Even());

  for (int i : v)
    std::cout << i << '\n';
}
