#include <iostream>
#include <vector>

int main() {
  std::vector<int> t = {1,2,3,4,5};

  for (std::vector<int>::iterator it = t.begin();
       it != t.end(); ++it) {
    std::cout << *it << '\n';
  }
}
