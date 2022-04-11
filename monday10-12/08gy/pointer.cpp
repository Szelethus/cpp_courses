#include <iostream>

int main() {
  int c = 2;
  int d = 5;

  // konstansra mutató mutató
  //const int* ptr = &c;

  // konstans mutató
  int *const ptr = &c;

  // referencia
  int &ref = c;

  // nullptr
  int *qtr = 0; // NE!!!
  int *str = NULL; // jobb
  int *gtr = nullptr; // C++11

  ref = 5;

  std::cout << c << ' ' << ref << '\n';
  std::cout << &c << ' ' << &ref << '\n';

  // konstansra mutató konstans mutató
  //const int *const ptr = &c;

  //ptr = &d;
  //*ptr = 5;

  //std::cout << c << ' ' << *ptr << '\n';
  //std::cout << &c << ' ' << ptr << '\n';
}
