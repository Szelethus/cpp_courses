#include <iostream>

struct A {
  const int i;
  int &ref;

  A(int _i, int &_c) : i(_i), ref(_c) {}
};

int main() {
  int c;

  A a(5, c);
}
