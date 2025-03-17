#include <iostream>

struct Complex {
  int re;
  int im;

  // konstruktor (ctor)
  Complex(int _re, int _im = 0) {
    this->re = _re;
    this->im = _im;
  }

  // mégis generálja ki a fordító
  Complex() = default;

  Complex operator~() {
    return {this->re, -this->im};
  }
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

int main() {
  Complex c1{5, 9};
  Complex c2{3, -2};

  Complex c3{9};

  //Complex res = operator+(c1, c2);
  Complex res = c1 - 5;
  Complex res2 = 5 - c1;

  std::cout << res.re << ' ' << res.im << '\n';
}
