#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

template <typename T>
class Complex {
  T re;
  T im;

public:
  Complex(T _re, T _im);

  T getRe();
  T getIm();
  void setRe(T _re);
  void setIm(T _im);
}; 

template <typename T>
std::ostream &operator<<(std::ostream &out, Complex<T> c);

template <typename T>
Complex<T> operator+(Complex<T> left, Complex<T> right);

//===----------------------------------------------------------------------===//
// Implementation.
//===----------------------------------------------------------------------===//

template <typename T> Complex<T>::Complex(T _re, T _im) : re(_re), im(_im) {}

template <typename T> T Complex<T>::getRe() { return re; }
template <typename T> T Complex<T>::getIm() { return im; }
template <typename T> void Complex<T>::setRe(T _re) { re = _re; }
template <typename T> void Complex<T>::setIm(T _im) { im = _im; }

template <typename T>
std::ostream &operator<<(std::ostream &out, Complex<T> c) {
  out << c.getRe();
  if (c.getIm() >= 0)
    out << '+';
  out << c.getIm() << 'i';
  return out;
}

template <typename T> Complex<T> operator+(Complex<T> left, Complex<T> right) {
  return {left.getRe() + right.getRe(), left.getIm() + right.getIm()};
}

#endif
