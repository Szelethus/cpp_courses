#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct Even {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {3,2,4,1,5,6,8,7};
  
  auto it = std::remove_if(v.begin(), v.end(), Even());
  v.erase(it, v.end());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
