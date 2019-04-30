#include <vector>
#include <iostream>

int main() {
  std::vector<int> v = {0, 1, 3, 4, 7, 3, 2, 3, 2, 3};

  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
    if (*it % 2 != 0)
      it = v.erase(it);
    else
      ++it;
  }

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
}
