#include <iostream>

void swap(int &c, int &d) {
  std::cout << "c: " << &c << " d: " << &d << '\n';
  int tmp = c;
  c = d;
  d = tmp;
}

int main() {
  int a = 1, b = 2;

  std::cout << "a: " << &a << " b: " << &b << '\n';

  swap(a, b);

  std::cout << "a: " << a << " b: " << b << '\n';
}
