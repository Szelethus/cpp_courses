#include <iostream>

struct Complex {
  int re, im;
};

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

Complex operator+(Complex lhs, Complex rhs) {
  Complex ret{lhs.re + rhs.re, lhs.im + rhs.im};
  return ret;
}

int main() {
  Complex c1{1, 2};
  Complex c2{1, 2};

  //Complex ret = operator+(c1, c2);
  Complex ret = c1 + c2;

  std::cout << ret << '\n';
}
