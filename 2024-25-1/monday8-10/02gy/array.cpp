#include <iostream>

void f(int *p, int size) {
  std::cout << sizeof(p) << '\n';
}

void g(int (*p)[5]) {
  std::cout << sizeof(*p) << '\n';
}

int main() {
  int t[6];
  std::cout << sizeof(t) / sizeof(t[0]) << '\n';

  f(t, sizeof(t) / sizeof(t[0]));

  g(&t);

}
