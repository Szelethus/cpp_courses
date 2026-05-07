#include <iostream>

struct A {
  A() {
    std::cout << "Constructed A!\n";
  }
  virtual ~A() {
    std::cout << "Destructed A!\n";
  }
};
struct B : A {
  B() {
    std::cout << "Constructed B!\n";
  }
  ~B() {
    std::cout << "Destructed B!\n";
  }
};
struct C : B {
  C() {
    std::cout << "Constructed C!\n";
  }
  ~C() {
    std::cout << "Destructed C!\n";
  }
};
struct D : C {
  D() {
    std::cout << "Constructed D!\n";
  }
  ~D() {
    std::cout << "Destructed D!\n";
  }
};

int main() {
  A *ptr = new D;
  delete ptr;
}
