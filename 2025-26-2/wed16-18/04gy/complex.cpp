#include <iostream>

struct Complex {
  int re;
  int im;

  Complex(int re_, int im_ = 0) {
    re = re_;
    im = im_;
  }
};

Complex operator+(const Complex lhs, const Complex rhs) {
  Complex ret{lhs.re + rhs.re, lhs.im + rhs.im};
  return ret;
}

Complex operator*(const Complex lhs, const Complex rhs) {
  return {
    lhs.re * rhs.re - lhs.im * rhs.im,
    lhs.re * rhs.im + lhs.im * rhs.re
  };
}

Complex operator~(const Complex c) {
  return {c.re, -c.im};
}

void print(const Complex c) {
  std::cout << "(" << c.re << ", " << c.im << ")\n";
}

int main() {
  Complex c1{1,7};
  Complex c2{-1, 5};
  Complex c3{6};

  Complex result = c1 * ~c2;
  //Complex result = operator+(c1, c2);

  print(result);
}
