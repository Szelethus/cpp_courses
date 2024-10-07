#include <iostream>

struct A {
  // változó deklaráció
  static int count;
};

// változó definÍció
int A::count = 0;

static int x;

void f() {
  static int x;
  std::cout << ++x << '\n';
}

int main() {
  A a1, a2;
  a1.count = 6;
  std::cout << a2.count << '\n';
}
