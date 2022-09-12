#include "complex.h"
#include <string>

Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

double Complex::getImag() const { return im; }
double Complex::getReal() const { return re; }

double &Complex::real() { return re; }
double &Complex::imag() { return im; }

const double &Complex::real() const { return re; }
const double &Complex::imag() const { return im; }

std::string Complex::to_string() const {
  std::string ret;
  ret += std::to_string(re);
  ret += '+';
  if (im < 0)
    ret += '(';
  ret += std::to_string(im);
  if (im < 0)
    ret += ')';
  ret += 'i';
  return ret;
}

Complex operator*(Complex left, Complex right) {
  return {left.getReal()*right.getReal() - left.getImag()*right.getImag(),
          right.getReal()*left.getImag() + left.getReal()*right.getImag()};
}
Complex operator-(Complex left, Complex right) {
  return {left.getReal() - right.getReal(), left.getImag() - right.getImag()};
}

