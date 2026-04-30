#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
  bool operator()(int i) const {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {4,2,3,5,1,6,7};

  std::stable_partition(v.begin(), v.end(), IsEven{});

  for (int i : v)
    std::cout << i << '\n';

}
