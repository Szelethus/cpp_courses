#include <iostream>

struct Vec {
  int a;
  int b;
};

int operator+(const Vec &LHS, const Vec &RHS) {
  return LHS.a + LHS.b + RHS.a + RHS.b;
}

std::ostream &operator<<(std::ostream &out, const Vec &v) {
  out << v.a << ' ' << v.b;
  return out;
}

int main() {

  Vec a, b;

  a.a = 0;
  a.b = 0;
  b.a = 0;
  b.b = 0;

  std::cout << a + b << '\n';

  std::cout << a << '\n';
}
