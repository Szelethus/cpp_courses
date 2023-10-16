#include <iostream>

struct A {
  int a, b;

  A(int i) : b(i), a(b) {}
};

int main() {
  A a(5);
}
