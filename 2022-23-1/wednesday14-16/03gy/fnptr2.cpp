#include <iostream>

int add(int l, int r) { return l + r; }
int mul(int l, int r) { return l * r; }

int main() {
  int (*ptr)(int, int) = &add;
  std::cout << (*ptr)(5, 6) << '\n';

  ptr = &mul;

  std::cout << (*ptr)(5, 6) << '\n';
}
