#include <iostream>
#include <vector>

void removeEven(std::vector<int> &v) {
  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {

    if (*it % 2 == 0)
      it = v.erase(it);
    else
      ++it;
  }
}

int main() {
  std::vector<int> v = {1,2,3,4,5,6};

  removeEven(v);

  for (int i : v) {
    std::cout << i << '\n';
  }
}
