#include <iostream>
#include "complex.h"

int main() {
  Complex<int> c{1, 2};
  Complex<int> c2{-6, 3};
  std::cout << c + c2 << '\n';
}
