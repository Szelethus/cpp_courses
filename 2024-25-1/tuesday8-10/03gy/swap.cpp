#include <iostream>

void swap(int *const a, int *const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapRef(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5, d = 8;
  swap(&c, &d);
  swapRef(c, d);

  std::cout << c << ' ' << d << '\n';
}
