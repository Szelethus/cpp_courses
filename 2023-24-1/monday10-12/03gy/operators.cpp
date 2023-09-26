#include <iostream>

struct Complex {
  double re, im;
};

Complex operator+(Complex left, Complex right) {
  return Complex{left.re + right.re, left.im + right.im};
}

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

std::ostream &my_endl(std::ostream &out) {
  out << '\n';
  out.flush();
  return out;
}

int main() {
  Complex a{1,2}, b{2,3};

  Complex ret = operator+(a, b);

  std::cout << ret << '\n';
  operator<<(operator<<(std::cout, ret), '\n');

  std::cout << 5 << my_endl;

  std::cout.operator<<(5);

}
