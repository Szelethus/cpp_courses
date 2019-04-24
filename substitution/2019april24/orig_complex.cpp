#include <cmath>
#include <iostream>

struct Complex {
  double re;
  double im;

  Complex(double r, double i) : re(r), im(i) {}

  void print() {
    std::cout << re;
    if (im >= 0)
      std::cout << "+";
    std::cout << im << 'i' << std::endl;
  }

  void conjugate() {
    im = -im;
  }

  double abs() {
    return std::sqrt(re*re + im*im);
  }
};

int main() {
  Complex c(3, 2);
  c.print();

  std::cout << c.abs() << std::endl;

  c.conjugate();
  c.print();

  return 0;
}
