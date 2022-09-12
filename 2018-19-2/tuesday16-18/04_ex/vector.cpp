#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {0, 1, 2, 3, 3, 3, 3, 2, 7, 4, 5};

  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
    if (*it == 3)
      it = v.erase(it);
    else
      ++it;
  }

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << '\n';
  std::cout << '\n';
}