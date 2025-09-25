#include <iostream>

void swapWrong1(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void swapWrong2(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}
void swap(int *a, int *b) {
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

  swapRef(c, d);

  std::cout << c << ' ' << d << '\n';
}
