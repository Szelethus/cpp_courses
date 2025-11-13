#include <iostream>
#include <vector>

void removeEven(std::vector<int> &v) {
  for (std::vector<int>::iterator it = v.begin(); it != v.end();++it) {

    if (*it % 2 == 0)
      v.erase(it);
  }
}

int main() {
  std::vector<int> v = {1,2,2,4,5};

  removeEven(v);

  for (int i : v) {
    std::cout << i << '\n';
  }
}
