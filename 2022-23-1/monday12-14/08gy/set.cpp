#include <set>
#include <iostream>

int main() {
  std::set<int> s = {3,4,2,5,1,6,9,8,0,7};
  for (int i : s) {
    std::cout << i << '\n';
  }
}
