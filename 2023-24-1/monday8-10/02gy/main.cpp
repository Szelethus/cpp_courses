#include <iostream>

void swap(int *const a, int *const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void print(const int &a, const int &b) {
  std::cout << &a << ' ' << &b << '\n';
}

void swapRef(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
  print(a, b);
}

int main() {
  int c = 5, d = 8;
  swap(&c, &d);
  swapRef(c, d);
  std::cout << c << ' ' << d << '\n';

  const int k;
  int &p;
}
