#include <iostream>

struct A {
  A() {
    std::cout << "A!\n";
  }
  A(int i) {
    std::cout << "A(int)!\n";
  }
};

int main() {
  A a{}; // C++11
}
