#include <iostream>
int main() {
  int k = 7;

  int& ref = k;

  std::cout << &ref << '\n';
  std::cout << &k << '\n';

  int *const ptr = &k;
}
