#include <iostream>

void f(int *p, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << p[i] << '\n';
  }
}

int main() {
  int t[5] = {1,2,3,4,5};

  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(t) << '\n';
  std::cout << sizeof(t) / sizeof(t[0]) << '\n';

  f(t, sizeof(t) / sizeof(t[0]));
}
