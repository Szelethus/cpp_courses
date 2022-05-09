#include "complex.h"
#include <iostream>

int main() {
  int your_mark = 1;

  Complex a(4.3, 3.1);
  Complex b(1.1);
  your_mark = a.getImag() - b.getReal();
  std::cout << "your mark is " << your_mark << std::endl;

  const Complex c = (a * b) - a;
  b.real() = 3;
  b.imag() = 3;
  if (b.getReal() == 3 && b.getImag() == 3)
    your_mark += 1;
  std::cout << "your mark is " << your_mark << std::endl;

  Complex conj = ~c;
  if (conj.imag() == -c.imag() && conj.abs() == c.abs())
    ++your_mark;
  std::cout << "your mark is " << your_mark << std::endl;
  if ("0.430000+0.310000i" == c.to_string() &&
      "0.430000+(-0.310000)i" == conj.to_string())
    ++your_mark;
  std::cout << "your mark is " << your_mark << std::endl;

  return 0;
}
