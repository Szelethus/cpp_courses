#include <iostream>

// referencia szerinti paraméter átadás
void swapRef(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// mutató szerinti paraméter átadás
void swap(int *const a, int *const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapWrong2(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

// érték szerinti paraméter átadás
void swapWrong(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5;
  int d = 8;

  swap(&c, &d);
  swapRef(c, d);

  std::cout << c << ' ' << d << '\n';
}
