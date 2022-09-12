#include <cassert>
#include <iostream>
#include "complex.h"
#include "poscomplex.h"

int main() {
  Complex c{1, -2};
  Complex c2{1, -2};
  PosComplex ps{4, 2};

  // c = ps;
  std::cout << c << ' ' << ps << '\n';
  std::cout << c + ps << '\n';
  std::cout << "Prefix operator before/after: "
            << ++c << ' ' << c << '\n';
  std::cout << "Postfix operator before/after: "
            << c2++ << ' ' << c2++ << '\n';
  std::cout << operator+(c, ps) << '\n';
}
