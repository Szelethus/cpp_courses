#include <iostream>

void pass(int *p, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << p[i] << '\n';
    std::cout << i[p] << '\n';
    std::cout << *(p + i) << '\n';
  }
}

void pass2(int (&p)[5]) {
  std::cout << sizeof(p) << '\n';
}

int main() {
  int t[5];

  for (int i = 0; i < 5; ++i) {
    t[i] = i;
  }

  std::cout << sizeof(t) << '\n';
  // std::cout << sizeof(t) / sizeof(t[0]) << '\n';

  pass(t, sizeof(t) / sizeof(t[0]));

  pass2(t);
}
