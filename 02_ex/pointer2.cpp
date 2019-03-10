#include <iostream>

int main() {
  const int c = 3;
  const int *p = &c;
  int d = 0;

  p = &d;

  const int *const r = &d;

  const int *const *o = &r;

  const int * const * const * * * const *;

  int k = 8;

  r = &k;

  std::cout << c << ' ' << *p <<  '\n';
}
