#include <iostream>

struct A {
  static int i;
};

int A::i = 0;

int main() {
  A a1;
  A a2;
  A a3;

  a3.i = 6;

  std::cout << A::i << '\n';
}
