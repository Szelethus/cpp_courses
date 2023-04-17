#include <iostream>

struct Complex {
  int re;
  int im;

  Complex(int _re, int _im) {
    re = _re;
    im = _im;
  }

  Complex() {
    re = 0;
    im = 0;
  }

  void conjugate() {
    im = -im;
  }
};

Complex operator+(Complex left, Complex right) {
  Complex ret(left.re + right.re,
              left.im + right.im);
  return ret;
}

Complex operator*(Complex left, Complex right) {
  Complex ret(left.re * right.re - left.im * right.im,
              left.re * right.im + left.im * right.re);
  return ret;
}

std::ostream& operator<<(std::ostream &out, Complex c) {
  out << "(" << c.re << "," << c.im << "i)\n";
  
  return out;
}

std::istream& operator>>(std::istream &in, Complex &c) {
  in >> c.re >> c.im;
  
  return in;
}

int main() {
  Complex c1;

  std::cin >> c1;

  Complex c2(2, -5);

  c1.conjugate();

  //Complex ret = c1 + c2;
  Complex ret = c1 * c2;

  std::cout << ret << "Aaaand thats it!\n";
}
