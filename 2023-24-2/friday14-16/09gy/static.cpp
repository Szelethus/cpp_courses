#include <iostream>

struct A {
  static int counter;

  A() {
    ++counter;
    std::cout << "A constructed, counter is: " << counter << '\n';
  }

  ~A() {
    --counter;
    std::cout << "A destructed, counter is: " << counter << '\n';
  }
};

int A::counter = 0;

int main() {
  A t[10];
}
