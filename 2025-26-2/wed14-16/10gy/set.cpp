#include <iostream>
#include <set>

using set_iter = std::set<int>::iterator;

int main() {
  std::set<int> s;

  s.insert(3);
  s.insert(2);
  s.insert(1);
  s.insert(2);
  s.insert(2);
  s.insert(2);

  set_iter it = s.begin();
  *it = 7;

  for (set_iter it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }
}
