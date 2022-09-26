#include <iostream>

static int x;

void f() {
  static int x;
  std::cout << x++ << '\n';
}

void g();
static void g() {
  std::cout << "static\n";
}

int main() {
  g();
  f();
  f();
  f();
  f();
  f();
  f();
}
