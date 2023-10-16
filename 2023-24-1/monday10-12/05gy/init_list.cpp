#include <iostream>

struct A {
  int a, b;

  A(int i) : b(i), a(b) {}
  A(std::string i) : a(i.size()), b(7) {}
};

int main() {
  A a(5);
  std::cout << a.a << '\n';
}
