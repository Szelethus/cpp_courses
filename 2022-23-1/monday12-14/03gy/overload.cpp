#include <iostream>

void g() {}
void g(int) {}

struct Complex {
  int rel, im;
};

Complex operator+(Complex l, Complex r) {
  Complex ret;
  ret.rel = l.rel + r.rel;
  ret.im = l.im + r.im;
  return ret;
}

int main() {
  Complex a{2, 3};
  Complex b{5, 6};
  Complex ret = a + b;
  Complex ret2 = operator+(a, b);
  int ret3 = 5 + 6;
}
