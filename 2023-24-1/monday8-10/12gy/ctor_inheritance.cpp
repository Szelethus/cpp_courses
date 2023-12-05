#include <iostream>

struct A {
  A() {
    std::cout << "A\n";
  }
  ~A() {
    std::cout << "~A\n";
  }
};
struct B : public A {
  B() {
    std::cout << "B\n";
  }
  ~B() {
    std::cout << "~B\n";
  }
};
struct C : public B {
  C() {
    std::cout << "C\n";
  }
  ~C() {
    std::cout << "~C\n";
  }
};
struct D : public C {
  D() {
    std::cout << "D\n";
  }
  ~D() {
    std::cout << "~D\n";
  }
};

int main() {
  D d;

  //A *ptr = new D;
  //delete ptr;
}
