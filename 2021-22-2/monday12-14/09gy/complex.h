#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

template <typename T>
class Complex {
  T re;
  T im;

public:
  Complex(T _re = 0, T _im = 0);

  T getRe() const;
  T getIm() const;

  void setRe(T _re);
  void setIm(T _im);

  void display();
};

template <typename T>
Complex<T> operator+(Complex<T> left, Complex<T> right);

//===-------------------------------------===//
// Implementation:
//===-------------------------------------===//

template <typename T>
Complex<T>::Complex(T _re, T _im) : re(_re), im(_im) {}

template <typename T>
T Complex<T>::getRe() const { return re; }
template <typename T>
T Complex<T>::getIm() const { return im; }

template <typename T>
void Complex<T>::setRe(T _re) { re = _re; }
template <typename T>
void Complex<T>::setIm(T _im) { im = _im; }

template <typename T>
void Complex<T>::display() {
  std::cout << re;
  if (im >= 0) {
    std::cout << '+';
  }
  std::cout << im << 'i' << '\n';
}

template <typename T>
Complex<T> operator+(Complex<T> left, Complex<T> right) {
  return {left.getRe() + right.getRe(), left.getIm() + right.getIm()};
}

#endif
