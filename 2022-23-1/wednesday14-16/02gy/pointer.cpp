#include <iostream>

int main() {
  int a = 5;
  int b = 9;

  const int *const p = &a;
  const int *const *q = &p;

  int *k;

  int *const r = &a;
  int &ref = a;

  std::cout << &a << '\n';
  std::cout << *p << '\n';
}
