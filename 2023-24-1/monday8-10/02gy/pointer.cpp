#include <iostream>

int main() {
  const int k = 5;

  // konstansra mutató mutató
  const int *p = &k;

  int c = 8;
  p = &c;
  std::cout << *p << '\n';
  c = 10;
  std::cout << *p << '\n';

  // konstans mutató
  int * const q = &c;

  int z;
  //q = &z;
  *q = 7;

  // konstansra mutató konstans mutató
  const int * const r = &k;

  int *************************************l;
}
