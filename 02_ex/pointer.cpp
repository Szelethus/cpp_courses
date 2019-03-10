#include <iostream>

int main() {
  int c = 3;
  int *p = &c;

  int **q = &p;

  std::cout << c << ' ' << *p << ' ' << **q << '\n';
}
