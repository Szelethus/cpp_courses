#include <iostream>

struct A {
  static int counter; 

  A() {
    ++counter;
    std::cout << "A constructed, count: " << counter << '\n';
  }

  ~A() {
    --counter;
    std::cout << "A destructed, count: " << counter << '\n';
  }
};

int A::counter = 0;

int main() {
  A a;
  A a2;

  A t[20];
};
