#include <iostream>

struct Complex {
  int re, im;

  Complex(int re, int im) : re(re), im(im) {}

  // constructor delegation
  Complex(int re) : Complex(re, 0) {}
};
