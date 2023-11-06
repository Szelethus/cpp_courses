#include <iostream>

struct Complex {
  double re, im;

  Complex(double re, double im = 0) : re(re), im(im) {}
};

Complex operator+(Complex left, Complex right) {
  return Complex{left.re + right.re, left.im + right.im};
}

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << ", " << c.im << "i)";
  return out;
}


int main() {
  Complex a{1,2}, b{3,4};

  Complex ret = 5 + a;

  std::cout << ret << '\n';
}
