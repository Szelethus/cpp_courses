#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
  std::vector<int> v = {5,2,3,1,6,4,8,7};

  std::sort(v.begin(), v.end());

  for (int i : v)
    std::cout << i << '\n';
}
