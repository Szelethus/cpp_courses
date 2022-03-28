#include <iostream>

struct Complex {
  double re;
  double im;
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
  Complex ret;
  ret.re = c1.re + c2.re;
  ret.im = c1.im + c2.im;
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
  Complex c1;
  c1.re = 3;
  c1.im = 2;

  std::cout << c1 << '\n';

  Complex c2;
  c2.re = 4;
  c2.im = 6;
}
