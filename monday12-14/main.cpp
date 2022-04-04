#include <cassert>
#include <iostream>

class PosComplex {
  double re;
  double im;

public:
  PosComplex(double re_, double im_) : re(re_), im(im_) {
    assert(re > 0 && "re");
    assert(im > 0 && "im");
  }

  friend class Complex;
};

class Complex {
  double re;
  double im;

public:
  Complex(PosComplex ps) : re(ps.re), im(ps.im) {}
  Complex(double re_, double im_) : re(re_), im(im_) {}

  friend std::ostream &operator<<(std::ostream &out, Complex c);
  friend Complex operator+(Complex left, Complex right);
  friend Complex operator-(Complex left, Complex right);
};

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << c.re << '\n';
  if (c.im > 0)
    out << '+';
  out << c.im << 'i';

  return out;
}

Complex operator+(Complex left, Complex right) {
  return {left.re + right.re, left.im + right.im};
}

Complex operator-(Complex left, Complex right) {
  return {left.re - right.re, left.im - right.im};
}

int main() {
  Complex c1{1, -2};
  Complex c2{6, 1};
  PosComplex ps1{5, 2.3};

  c1 = ps1;
}
