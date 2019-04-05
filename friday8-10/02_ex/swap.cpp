#include <iostream>

void swapWrong(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swapWrong2(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

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
  int c = 3, d = 2;
  swapRef(c, d);
  std::cout  << c << ' ' << d << '\n';
}
