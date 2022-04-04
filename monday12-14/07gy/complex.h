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

  double getRe() const;
  double getIm() const;

  void setRe(double re_);
  void setIm(double im_);

  friend std::ostream &operator<<(std::ostream &out, const Complex c);
  friend Complex operator+(const Complex left, const Complex right);
  friend Complex operator-(const Complex left, const Complex right);
  friend Complex operator++(const Complex c);
  friend Complex operator++(const Complex c, int);
  friend bool operator==(const Complex left, const Complex right);
};

std::ostream &operator<<(std::ostream &out, const Complex c);
Complex operator+(const Complex left, const Complex right);
Complex operator-(const Complex left, const Complex right);
Complex operator++(const Complex c);
Complex operator++(const Complex c, int);
bool operator==(const Complex left, const Complex right);

#endif
