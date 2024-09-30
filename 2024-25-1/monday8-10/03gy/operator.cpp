#include <iostream>

struct Complex {
  double re, im;
};

Complex operator+(Complex left, Complex right) {
  return Complex{left.re + right.re, left.im + right.im};
}

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << ", " << c.im << "i)";
  return out;
}

std::ostream &my_endl(std::ostream &out) {
  out << '\n';
  out.flush();
  return out;
}

int main() {
  Complex a{1,2}, b{3,4};

  Complex ret = operator+(a, b);

  int m = 5;

  std::cout << ret << my_endl;
  return 0;

  std::cout.flush();
  operator<<(operator<<(std::cout, ret), '\n');

  std::cout.operator<<(m);
}
