#include <iostream>

struct Complex {
  int re;
  int im;

  // konstruktor (ctor)
  Complex(int _re, int _im = 0) : re(_re), im(_im) {}

  // fordító mégis generálja a default konstruktort
  Complex() = default;

  Complex conjugate() {
    return {re, -im};
  }
};

Complex operator+(Complex lhs, Complex rhs) {
  Complex ret;

  ret.re = lhs.re + rhs.re;
  ret.im = lhs.im + rhs.im;
  return ret;
}

Complex operator*(Complex lhs, Complex rhs) {
  Complex ret{
    lhs.re * rhs.re - rhs.im * lhs.im,
    lhs.re * rhs.im + lhs.im * rhs.re
  };

  return ret;
}

Complex operator-(Complex lhs, Complex rhs) {
  // név nélküli temporális változó
  return {lhs.re - rhs.re, lhs.im - rhs.im};
}

int main() {
  Complex c1{5, -2};

  Complex c2{3, 4};

  Complex c3{5};

  //Complex ret = operator+(c1, c2);
  //implicit konverzió 5->(5, 0)
  Complex res = c1 - 5;
  Complex res2 = 5 - c1;

  std::cout << res.re << ' ' << res.im << '\n';
}
