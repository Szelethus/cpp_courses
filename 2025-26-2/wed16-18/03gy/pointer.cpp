#include <iostream>

int main() {
  const int c = 5;
  int d = 8;

  // konstansra mutató mutató
  const int* ptr = &c;
  // nem tudja megváltoztatni a mutatott értéket,
  // de meg tudja változtatni hogy hova mutasson
  ptr = &d;

  // konstans mutató
  int * const qtr = &d;
  // meg tudja változtatni a mutatott értéket,
  // de nem tudja megváltoztatni hogy hova mutasson
  *qtr = 10;

  // konstansra mutató konstans mutató
  const int * const ktr = &c;

  std::cout << c << '\n';
  std::cout << &c << '\n';
  std::cout << ptr << '\n';
  std::cout << *ptr << '\n';

  int i = 7;
  int *iptr = &i;
  int **iiptr = &iptr;
}
