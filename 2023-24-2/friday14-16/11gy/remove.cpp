#include <iostream>
#include <algorithm>
#include <vector>

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {3,2,5,1,4,6,9,8,7}; 

  auto it = std::remove_if(v.begin(), v.end(), IsEven{});

  v.erase(it, v.end());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
