#include <iostream>

int add(int a, int b) {
  return a + b;
}

int mul(int a, int b) {
  return a * b;
}

void printSomething(int a, int b, int op(int, int)) {
  std::cout << op(a, b) << '\n';
}

int main() {
  int c = 3, d = 5;
  printSomething(c, d, mul);
  printSomething(c, d, add);
}
