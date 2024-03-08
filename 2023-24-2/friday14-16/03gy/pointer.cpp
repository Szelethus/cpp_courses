#include <iostream>

int main() {
  const int m = 0;
  int l = 5, k = 7;

  const int *ptr = &m;
  // *ptr = 5;
  ptr = &l;

  int *const qtr = &l;
  *qtr = 8;
  //qtr = &k;

  const int *const qptr = &m;

  // std::cout << &m << ' ' << ptr << '\n';

  // std::cout << m << '\n';
  // *ptr = 5;
  // std::cout << m << '\n';

  // int *g;
  // int *k = nullptr;
}
