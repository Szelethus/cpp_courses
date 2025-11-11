#include <iostream>

int main() {
  int t[5] = {1,2,3,4,5};

  for (int *p = t; p != t + 5; ++p) {
    std::cout << *p << '\n';
  }
}
