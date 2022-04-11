#include <iostream>

int main() {
  int c = 2;
  int d = 5;

  // null pointer
  int *ptr = 0; // NE!!!
  int *ptr2 = NULL; // jobb
  int *ptr3 = nullptr; // C++11, legjobb

  // int *ptr = &c;
  // int **qtr = &ptr;

  // std::cout << qtr << ' ' << *qtr << ' ' << **qtr << '\n';
  // std::cout << ptr << ' ' << *ptr << '\n';
  // std::cout << c << '\n';

  // konstansra mutató mutató
  // const int *ptr = &c;

  // konstans mutató
  // int *const ptr = &c;

  // referencia
  // int &ref = c;

  // ref = 5;
  // std::cout << ref << ' ' << c << '\n';

  // konstanra mutató konstans mutató
  // const int *const ptr = &c;

  // konstans referencia
  // const int &cref = c;

  // ptr = &d;
  //*ptr = 5;

  // std::cout << c << ' ' << &c << '\n';
  // std::cout << c << ' ' << *ptr << '\n';
}
