#include <iostream>

struct A {
  int i;
  int j;

  // hibás!!
  A(int i) : j(j), i(j) {}
};

int main() {
  A a(5);
}
