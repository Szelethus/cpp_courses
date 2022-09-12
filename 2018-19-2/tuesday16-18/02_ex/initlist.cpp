#include <iostream>

struct A {
  int a, b;

  A() : b(13), a(b) {}
};

int main() {

  A alma;
  std::cout << alma.a << ' ' << alma.b << '\n';
}
