#include <iostream>

int main() {
  // memóriaszemetet tartalmazó pointer
  int *k;

  std::cout << sizeof(int*) << '\n';
  std::cout << sizeof(long*) << '\n';

  int i = 5;

  // referencia (~konstans mutató)
  int &ref = i;

  std::cout << i << '\n';
  std::cout << ref << '\n';
  std::cout << &i << '\n';
  std::cout << &ref << '\n';
}
