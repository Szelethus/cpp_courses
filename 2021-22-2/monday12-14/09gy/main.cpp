#include <iostream>
#include "complex.h"

int main() {
  Complex<int> c1{2, -6};
  Complex<int> c2{-3, 8};

  Complex<int> result = c1 + c2;

  result.display();
}
