#include <iostream>

struct Complex {
  int re;
  int im;
};

Complex operator+(Complex lhs, Complex rhs) {
  Complex ret;
  ret.re = lhs.re + rhs.re;
  ret.im = lhs.im + rhs.im;
  return ret;
}

Complex operator-(Complex lhs, Complex rhs) {
  Complex ret{lhs.re - rhs.re, lhs.im - rhs.im};
  return ret;
}

Complex operator*(Complex lhs, Complex rhs) {
  // név néküli temporális változó
  return {
    lhs.re * rhs.re - lhs.im * rhs.im,
    lhs.re * rhs.im + lhs.im * rhs.re
  };
}

Complex conjugate(Complex c) {
  return {c.re, -c.im};
}

int main() {
  Complex c1{5, 9};
  Complex c2{3, -2};

  //Complex res = operator+(c1, c2);
  Complex res = c1 - conjugate(c2);

  std::cout << res.re << ' ' << res.im << '\n';
}
