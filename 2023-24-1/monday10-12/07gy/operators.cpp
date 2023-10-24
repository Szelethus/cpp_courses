#include <iostream>

struct Complex {
  double re, im;

  Complex(double re, double im = 0) : re(re), im(im) {}
};

Complex operator+(Complex left, Complex right) {
  return Complex{left.re + right.re, left.im + right.im};
}

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

int main() {
  Complex a{1,2}, b{2,3};

  Complex ret = 6 + a;

  std::cout << ret << '\n';

}
