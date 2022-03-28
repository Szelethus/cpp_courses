#include <iostream>

struct Complex {
  double re;
  double im;

  Complex(double re, double im) {
    this->re = re;
    this->im = im;
  }
};

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << c.re;
  if (c.im < 0)
    out << '-';
  else
    out << '+';
  out << c.im << 'i';
  return out;
}

Complex operator+(Complex c1, Complex c2) {
  Complex ret(c1.re + c2.re, c1.im + c2.im);
  return ret;
}

Complex operator-(Complex c1, Complex c2) {
   Complex ret{c1.re + c2.re, c1.im + c2.im};

   return ret;
}

Complex operator~(Complex c) {
  return Complex{c.re, -c.im};
}

int main() {
  Complex c1(3,2);

  std::cout << c1 << '\n';

  Complex c2(4,6);

  std::cout << c1 + c2 << '\n';
}
