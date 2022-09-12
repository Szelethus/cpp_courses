#include <iostream>

struct A {
  int a, b;

  A() : b(3), a(b) {}
};

int main() {
  A a;
  std::cout << a.a << ' ' << a.b << '\n';
}
