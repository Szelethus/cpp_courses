#include <iostream>
#include <set>

template <class T>
struct less {
  bool operator()(T left, T right) {
    return left < right;
  }
};

using set_iter = std::set<int, std::less<int>>::iterator;

int main() {
  std::set<int, std::less<int>> s = {1, 3, 2, 6, 4, 5};

  s.insert(0);
  s.insert(0);

  set_iter it = s.find(3);

  if (it == s.end())
    return -1;

  set_iter it2 = s.find(5);

  s.erase(it, it2);

  for (set_iter it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }
}
