#include <iostream>

struct A {
  int i;
  int j;

  A(int i) : i(i), j(i) {}
};

int main() {
  A a(5);
}
