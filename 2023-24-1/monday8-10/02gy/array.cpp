#include <iostream>

void f(int *p, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << p[i] << '\n';
    std::cout << *(p + i) << '\n';
    std::cout << *(i + p) << '\n';
    std::cout << i[p] << '\n';
  }
}

void g(int (&p)[5]) {
  std::cout << sizeof(p) << '\n';
}

int main() {
  int t[5] = {1,2,3,4,5};

  std::cout << sizeof(t) / sizeof(t[0]) << '\n';
  f(t, sizeof(t) / sizeof(t[0]));

  g(t);
}
