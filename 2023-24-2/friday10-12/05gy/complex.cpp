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
};

Complex operator+(Complex left, Complex right) {
  return {left.re + right.re, left.im + right.im};
}

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

std::istream& operator>>(std::istream &in, Complex &c) {
  in >> c.re >> c.im;
  return in;
}

int main() {
  Complex c1(5, 2);
  Complex c2(-2, 7);

  std::cin >> c1;

  Complex ret = c1 + 5;

  std::cout << ~c1 << '\n';
  std::cout << c1.operator~() << '\n';

}
