#include <fstream>
#include <iostream>
#include "complex.h"

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << c.getRe();
  if (c.getIm() < 0) {
    out << c.getIm();
  } else {
    out << '+' << c.getIm();
  }
  out << 'i';

  return out;
}

Complex operator+(const Complex left, const Complex right) {
  Complex ret;
  ret.setRe(left.getRe() + right.getRe());
  ret.setIm(left.getIm() + right.getIm());
  return ret;
}

Complex operator-(Complex left, Complex right) {
  Complex ret{left.getRe() - right.getRe(), left.getIm() - right.getIm()};
  return ret;
}

Complex operator~(Complex c) { return {c.getRe(), -c.getIm()}; }

int main() {
  Complex c{5, 7};
  Complex c2{3, -4};

  Complex real{7.2};

  std::cout << "real: " << real << '\n';
  std::cout << "c: " << c << '\n';
  std::cout << "c2: " << c2 << '\n';
  std::cout << "c+c2: " << c + c2 << '\n';
  std::cout << "c-c2: " << c - c2 << '\n';
  std::cout << "~c: " << ~c << '\n';
}
