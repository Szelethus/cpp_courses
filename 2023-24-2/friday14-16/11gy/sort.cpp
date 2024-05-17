#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v = {3,2,5,1,4,6,9,8,7}; 

  std::stable_sort(v.begin(), v.end());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
