#include <iostream>

int main() {
  int c = 5;

  std::cout << &c << '\n';

  int k = 8;

  const int *const ptr = &c;

  int &ref = k;
  ref = 10;


  int *n = nullptr;

}
