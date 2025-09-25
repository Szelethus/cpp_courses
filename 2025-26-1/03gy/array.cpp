#include <iostream>

void f(int *p, int size) {
  std::cout << sizeof(p) << '\n';
}

void fpointer(int (*t)[5]) {
  std::cout << sizeof(*t) << '\n';
}

void fref(int (&t)[5]) {
  std::cout << sizeof(t) << '\n';
}

int main() {
  int t[5] = {1,2,3,4,5};

  std::cout << sizeof(t) << '\n';
  std::cout << sizeof(t[0]) << '\n';
  std::cout <<  sizeof(t)/sizeof(t[0]) << '\n';

  f(t, sizeof(t)/sizeof(t[0]));

  fpointer(&t);
  fref(t);
}
