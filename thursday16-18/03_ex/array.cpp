#include <iostream>

int main() {
  int t[] = {0,1,2,3};

  for (int *p = t; p != t + 4; ++p) {
    std::cout << *p;
  }
}
