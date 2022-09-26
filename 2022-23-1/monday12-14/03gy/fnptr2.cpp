#include <iostream>

int add(int l, int r) { return l + r; }
int mul(int l, int r) { return l * r; }

int main() {
  int (*op)(int, int) = &add;

  std::cout << add(5, 3) << '\n';
  std::cout << (*op)(5, 3) << '\n';
  
  op = &mul;

  std::cout << (*op)(5, 3) << '\n';
}
