#include <iostream>

int main() {
  int t[] = {3,4,5,2345,34,346};

  for (int *p = t; p != t + sizeof(t) / sizeof(t[0]); ++p) {
    std::cout << *p << '\n';
  }
}
