#include "complex.h"
#include "poscomplex.h"
#include <iostream>

Complex::Complex(const PosComplex &ps) : re(ps.re), im(ps.im) {}
Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

std::ostream &operator<<(std::ostream &out, const Complex this_) {
  out << this_.re;
  if (this_.im >= 0)
    out << '+';
  out << this_.im << 'i';
  return out;
}

Complex operator+(const Complex left, const Complex right) {
  return {left.re + right.re, left.im + right.im};
}

Complex operator-(const Complex left, const Complex right) {
  return {left.re - right.re, left.im - right.im};
}

Complex operator~(const Complex c) { return {c.re, -c.im}; }

bool operator==(const Complex left, const Complex right) {
  return left.re == right.re && left.im == right.im;
}

bool operator!=(const Complex left, const Complex right) {
  return !(left == right);
}
