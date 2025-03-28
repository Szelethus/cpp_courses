#include <iostream>

struct Complex {
  int re, im;
};

std::istream& operator>>(std::istream &in,
                         Complex &c) {
  in >> c.re >> c.im;
  return in;
}

std::ostream& operator<<(std::ostream &out,
                         Complex &c) {
  out << c.re << c.im;
  return out;
}

int main() {
  Complex c;

  std::cin >> c;

  std::cout << c;
}
