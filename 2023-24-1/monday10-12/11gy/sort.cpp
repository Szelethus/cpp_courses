#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

struct Descending {
  bool operator()(int lhs, int rhs) {
    return lhs > rhs;
  }
};

int main() {
  std::vector<int> v = {6,8,4,2,3,1,5,7};
  
  std::sort(v.begin(), v.end(), Descending());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
