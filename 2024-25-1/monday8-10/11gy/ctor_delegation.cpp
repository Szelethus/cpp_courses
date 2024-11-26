#include <iostream>

struct A {
  int x;

  A(int x) : x(x) {}
};

struct B : public A {
  int y;

  B(int x, int y) : A(x), y(y) {}

  B(int x) : B(x, 0) {}
};
