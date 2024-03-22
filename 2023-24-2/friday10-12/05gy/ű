#include <iostream>

struct Complex {
  int re;
  int im;
};

Complex operator+(Complex left, Complex right) {
  Complex ret;
  ret.re = left.re + right.re;
  ret.im = left.im + right.im;
  return ret;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
  out << '(' << c.re << ", " << c.im << ")";
  return out;
}

void foo(int a) {}
void foo(std::string s) {}

int main() {
  Complex c;
  c.re = 3;
  c.im = 2;

  Complex c2;
  c2.re = 8;
  c2.im = 1;

  Complex ret = c + c2;

  std::cout << ret << '\n';
}
