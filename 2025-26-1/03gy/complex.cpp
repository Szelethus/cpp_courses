#include <iostream>

struct Complex {
  int re;
  int im;
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
  Complex ret {lhs.re + rhs.re, lhs.im + rhs.im};
  return ret;
}

std::ostream& operator<<(std::ostream &out, const Complex &c) {
  out << '(' << c.re << ", " << c.im << ')';
  return out;
}

int main() {
  Complex c1{2, 3};
  Complex c2{4, -2};

  Complex a = c1 + c2;
  //Complex a = operator+(c1, c2);

  //operator<<(std::cout, a);
  std::cout << a << std::endl;

}
