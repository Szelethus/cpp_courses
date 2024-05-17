#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v = {5,2,3,1,6,4,8,7};

  std::stable_sort(v.begin(), v.end());

  for (int i : v)
    std::cout << i << '\n';
}
