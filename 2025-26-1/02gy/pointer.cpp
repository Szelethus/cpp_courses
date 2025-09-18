#include <iostream>

int main() {
  int k = 5;

  // konstansra mutató mutató
  const int *ptr = &k;

  std::cout << ptr << '\n';
  std::cout << &k << '\n';
  std::cout << *ptr << '\n';
  std::cout << k << '\n';

  int c;

  // konstans mutató
  int *const qtr = &k;

  *qtr = 6;

  // konstansra mutató konstans mutató
  const int *const qptr = NULL;


  int *ctr = nullptr;
  int **pptr = &ctr;

}
