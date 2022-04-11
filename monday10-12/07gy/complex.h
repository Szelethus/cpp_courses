#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iosfwd>

class PosComplex;

class Complex {
  double re;
  double im;

public:
  Complex(const PosComplex &ps);
  Complex(double re_, double im_);

  friend std::ostream &operator<<(std::ostream &out, const Complex this_);
  friend Complex operator+(const Complex left, const Complex right);
  friend Complex operator-(const Complex left, const Complex right);
  friend Complex operator~(const Complex c);

  friend bool operator==(const Complex left, const Complex right);

  Complex &operator++() {
    ++re;
    ++im;
    return *this;
  }

  Complex operator++(int) {
    Complex tmp = *this;
    ++re;
    ++im;
    return tmp;
  }
};

std::ostream &operator<<(std::ostream &out, const Complex this_);
Complex operator+(const Complex left, const Complex right);
Complex operator-(const Complex left, const Complex right);
Complex operator~(const Complex c);

bool operator==(const Complex left, const Complex right);

#endif
