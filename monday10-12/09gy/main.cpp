#include <iostream>
#include "complex.h"

int main() {
  Complex<int> c1{2, -5};
  Complex<int> c2{3, 2};
  Complex<std::string> c3;
  
  Complex<int> result = c1 + c2;
  result.display();
  std::cout << '\n';
}
