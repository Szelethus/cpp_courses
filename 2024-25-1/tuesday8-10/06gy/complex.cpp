#include <iostream>

struct Complex {
  int re, im;

  Complex(int re, int im = 0) : re(re), im(im) {}

  Complex operator+(Complex rhs) {
    return Complex{re + rhs.re, im + rhs.im};
  }
};

std::ostream &operator<<(std::ostream &out, Complex c) {
  out << '(' << c.re << ", " << c.im << ")";

  return out;
}

int main() {
  Complex c1{1, 2};
  Complex c2{1, 2};

  //Complex ret = operator+(c1, c2);
  Complex ret = c1 + 5;
  Complex ret2 = 5 + c2;

  std::cout << ret << '\n';

}
