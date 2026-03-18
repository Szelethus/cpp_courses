#include <iostream>

struct Complex {
  int re;
  int im;

  // konstruktor
  Complex(int re_, int im_ = 0) {
    re = re_;
    im = im_;
  }

  void print() {
    std::cout << "(" << (*this).re << ", " << this->im << ")\n";
  }

  Complex operator~() {
    return {re, -im};
  }
};

Complex operator~(const Complex c) {
  return {c.re, -c.im};
}

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

std::ostream& operator<<(std::ostream &out, const Complex c) {
  out << c.re << ' ' << c.im << '\n';
  return out;
}

int main() {
  Complex c1{1,7};
  Complex c2{-1, 5};
  Complex c3{6};

  Complex result = c1 * ~c2;
  //Complex result = operator+(c1, c2);

  ~c3;
  operator~(c3);
  c3.operator~();

  std::cout << c1 << '\n';
}
