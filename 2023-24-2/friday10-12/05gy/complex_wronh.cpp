#include <iostream>
#include <fstream>

struct Complex {
  int re;
  int im;

  Complex(int re_, int im_ = 0) {
    this->re = re_;
    this->im = im_;
  }

  Complex operator~() {
    return {re, -1 * im};
  }

  Complex operator+(Complex right) {
    return {this->re + right.re, this->im + right.im};
  }
};

Complex operator-(Complex left, Complex right) {
  return {left.re - right.re, left.im - right.im};
}

Complex operator*(Complex left, Complex right) {
  return {left.re * right.re - left.im * right.im,
          left.re * right.im + left.im * right.re};
}

std::ostream& operator<<(std::ostream &out, Complex c) {
  out << '(' << c.re << ", " << c.im << ')';
  return out;
}

int main() {
  Complex c1(5, 2);
  Complex c2(-2, 7);
  
  operator-(c1, c2); // c1 - c2;
  c1.operator+(5); // c1 + 5;
  5.operator+(c1); // 5 + c1;

  Complex ret = 5 + c1;

  std::cout << ~c1 << '\n';
}
