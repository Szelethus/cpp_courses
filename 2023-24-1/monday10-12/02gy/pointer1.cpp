#include <iostream>

int main() {
  int k = 5;
  int *ptr = &k;

  std::cout << &k << '\n';
  std::cout << ptr << '\n';

  *ptr = 10;

  std::cout << k << '\n';

  int c = 3;
  ptr = &c;

  int **q = &ptr;

  *q = &k;

}
