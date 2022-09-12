#include <iostream>

void f() {
  std::cout << "Hellobello\n";
}

void f(int i) {
  std::cout << i << "\n";
}

struct A {
  int a;
  int b;
};

int operator+(const A &a1, const A &a2) {
  return a1.a + a1.b + a2.a + a2.b;
}

std::ostream& operator<<(std::ostream &out, const A &a) {
  out << a.a << ' ' << a.b;
  return out;
}

int main() {
  A a1, a2;
  a1.a = 0;
  a1.b = 1;
  a2.a = 2;
  a2.b = 3;
  std::cout << a1 << ' ' << a2 << '\n';
}
