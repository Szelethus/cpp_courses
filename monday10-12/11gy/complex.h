#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex {
  double re;
  double im;

public:
  Complex(double re_, double im_ = 0);

  double getImag() const;
  double getReal() const;

  double &real();
  double &imag();

  const double &real() const;
  const double &imag() const;

  Complex operator~() const;
  double abs() const;

  std::string to_string() const;
};

Complex operator*(Complex left, Complex right);
Complex operator-(Complex left, Complex right);

#endif
