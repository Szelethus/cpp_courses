#include <iostream>

int main() {
  const int c = 5;
  const int d = 4;

  const int* const ptr = &c;

  int i = 4;
  int * const cptr = &i;
  int &ref = i;

  std::cout << &ref << '\n';
  std::cout << &i << '\n';
  
  int *nptr = 0;
  int *nptr1 = NULL;
  int *nptr2 = nullptr;

  // std::cout << "&c: " << &c << '\n';
  // std::cout << "ptr: " << ptr << '\n';
  // std::cout << "*ptr: " << *ptr << '\n';

  // *ptr = 6;

  // std::cout << c << '\n';

  // int** qtr = &ptr;

  // std::cout << "qtr: " << qtr << '\n';
  // std::cout << "*qtr: " << *qtr << '\n';
  // std::cout << "**qtr: " << **qtr << '\n';
}
