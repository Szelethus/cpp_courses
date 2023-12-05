#include <iostream>

struct A {
  A() {
    std::cout << "A\n";
  }
  virtual ~A() {
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
  int *ptr;
  D() : ptr(new int) {
    std::cout << "D\n";
  }
  ~D() {
    delete ptr;
    std::cout << "~D\n";
  }
};

int main() {
  A *a = new D;
  delete a;
}
