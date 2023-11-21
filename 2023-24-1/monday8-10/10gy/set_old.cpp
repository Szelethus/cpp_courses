#include <iostream>
#include <set>

using set_iter = std::set<int>::iterator;

int main() {
  std::set<int, std::less<int>> s = {1, 3, 4, 2, 6, 5};

  s.insert(0);
  s.insert(0);

  set_iter a_it = s.find(3);
  set_iter b_it = s.find(5);

  if (a_it == s.end())
    return -1;

  s.erase(b_it, a_it);

  for (int i : s) {
    std::cout << i << '\n';
  }
}
