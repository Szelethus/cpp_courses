#include <cassert>
#include <iostream>
#include "poscomplex.h"
#include "complex.h"

int main() {
  Complex c{-3, 2};
  Complex c2 = c;
  PosComplex pc{5, 9};

  pc.setIm(6);

  // c = pc;
  std::cout << c << ' ' << pc << '\n';
  std::cout << "Prefix before/after: " << c << ' ' << ++c << '\n';
  std::cout << "Postfix before/after: " << c2 << ' ' << c2++ << '\n';
  std::cout << c + pc << '\n';
  std::cout << pc + c << '\n';
  std::cout << operator+(pc, c) << '\n';
}
