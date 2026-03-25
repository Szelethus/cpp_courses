#include <iostream>

struct A {
  const int i;
  int &ref;
  // inicializációs lista
  A(int _i, int &_ref) : i(_i), ref(_ref) { }
};

int main() {
  int k = 0;
  A a(5, k);
}
