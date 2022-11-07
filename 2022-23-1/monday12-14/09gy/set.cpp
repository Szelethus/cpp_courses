#include <set>
#include <iostream>

using set_iter = std::set<int>::iterator;

void printSet(const std::set<int> &set) {
  for (set_iter it = set.begin(); it != set.end(); ++it) {
    std::cout << *it << '\n';
  }
}

struct Point {
  int x;
  int y;
};

int main() {
  std::set<int> s = {3,4,2,5,1,6,9,8,0,7};
  printSet(s);
}
