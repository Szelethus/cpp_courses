#include <iostream>
#include "complex.h"

Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

double Complex::getRe() const { return re; }
double Complex::getIm() const { return im; }

void Complex::setRe(double re_) { re = re_; }
void Complex::setIm(double im_) { im = im_; }

std::ostream &operator<<(std::ostream &out, const Complex c) {
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

Complex operator-(const Complex left, const Complex right) {
  Complex ret{left.getRe() - right.getRe(), left.getIm() - right.getIm()};
  return ret;
}

Complex operator~(const Complex left) { return {left.getRe(), -left.getIm()}; }

int main() {
  const Complex c{5, 8};
  const Complex c2{2, -1};

  const Complex real{6.3};
  std::cout << "real: " << real << '\n';

  std::cout << "c: " << c << '\n';
  std::cout << "~c: " << ~c << '\n';
  std::cout << "c2: " << c2 << '\n';
  std::cout << "c + c2: " << c + c2 << '\n';
  std::cout << "c - c2: " << c - c2 << '\n';

  // std::cout << reResult << '+' << imResult << "i\n";
}
