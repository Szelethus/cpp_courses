#include <iostream>
#include "complex.h"
#include "poscomplex.h"

Complex::Complex(const PosComplex &ps) : re(ps.re), im(ps.im) {}
Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

double Complex::getRe() const { return re; }
double Complex::getIm() const { return im; }

void Complex::setRe(double re_) { re = re_; }
void Complex::setIm(double im_) { im = im_; }

std::ostream &operator<<(std::ostream &out, const Complex c) {
  out << c.re;
  if (c.im >= 0)
    out << '+';
  out << c.im << 'i';
  return out;
}

Complex operator+(const Complex left, const Complex right) {
  return {left.re + right.re, left.im + right.im};
}

Complex operator-(const Complex left, const Complex right) {
  return {left.re - right.re, left.im - right.im};
}

Complex operator++(Complex c, int) {
  Complex orig = c;
  c.re++;
  c.im++;
  return orig;
}

Complex &operator++(Complex &c) {
  c++;
  return c;
}

bool operator==(const Complex left, const Complex right) {
  return left.re == right.re && left.im == right.im;
}

bool operator!=(const Complex left, const Complex right) {
  return !(left == right);
}
