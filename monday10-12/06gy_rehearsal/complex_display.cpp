#include <iostream>

struct Complex {
  double re;
  double im;
};

void display(std::ostream &out, Complex c) {
  out << c.re;
  if (c.im < 0)
    out << '-';
  else
    out << '+';
  out << c.im << 'i';
}

int main() {
  Complex c1;
  c1.re = 3;
  c1.im = 2;

  display(std::cout, c1);

  std::cout << '\n';

  Complex c2;
  c2.re = 4;
  c2.im = 6;
}
