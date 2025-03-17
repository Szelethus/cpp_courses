#include <iostream>

void foo(int *p, int size) {
  std::cout << "foo(): " << sizeof(p) << '\n';
}

void foo2(int (*p)[5]) {
  std::cout << "foo2(): " <<  sizeof(*p) << '\n';
}

void foo3(int (&p)[5]) {
  std::cout << "foo3(): " <<  sizeof(p) << '\n';
}

int main() {
  int t[5] = {1, 2, 3, 4, 5};

  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(t) << '\n';
  std::cout << sizeof(t) / sizeof(int) << '\n';

  foo(t, sizeof(t) / sizeof(t[0]));

  foo2(&t);
  foo3(t);
}
