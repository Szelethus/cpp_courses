#include <iostream>

// referencia szerinti paraméter átvétel
void swapRef(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap(int *const a, int *const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// Pointer szerinti paraméter átvétel
void swapWrong2(int *a, int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

// érték szerinti paraméter átvétel
void swapWrong(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5, d = 8;

  swapRef(c, d);

  std::cout << c << ' ' << d << '\n';
}
