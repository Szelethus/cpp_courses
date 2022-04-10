#include <iostream>

int main() {
  int c = 0;
  int d = 2;

  int *const ptr = &d;
  int &ref = d;

  ref = 5;

  std::cout << c << '\n';
}
