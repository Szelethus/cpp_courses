#include <iostream>

int add(int c, int d) {
  return c + d;
}

int mul(int c, int d) {
  return c * d;
}

int doSomething(int c, int d, int op(int, int)) {
  return op(c, d);
}

int main() {
  int a = 5, b = 7;
  std::cout << doSomething(a, b, add) << '\n';
  std::cout << doSomething(a, b, mul) << '\n';
}
