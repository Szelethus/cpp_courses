#include <iostream>

int global;

// statikus változók
static int st;

void g() {
  // függvényre statikus változók
  static int count = 0;

  std::cout << ++count << '\n';
}

struct A {
  // osztályra statikus változók
  static int count;

  A() {
    std::cout << "A instantiated " << ++count
              << " times\n";
  }
};

int A::count = 0;

int main() {
  A a1, a2, a3;
}
