#include <iostream>

struct A {
  const static int counter = 0;
  A() {
  }
};

int main() {
  std::cout << A::counter << '\n';
}
