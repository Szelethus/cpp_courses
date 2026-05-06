#include <iostream>

struct A {
  A() {
    std::cout << "A constructed\n";
  }
  virtual ~A() {
    std::cout << "A destructed\n";
  }
};

struct B : public A {
  B() {
    std::cout << "B constructed\n";
  }
  ~B() {
    std::cout << "B destructed\n";
  }
};
struct C : public B {
  C() {
    std::cout << "C constructed\n";
  }
  ~C() {
    std::cout << "C destructed\n";
  }
};
struct D : public C {
  int *ptr;

  D() {
    ptr = new int;
    std::cout << "D constructed\n";
  }
  ~D() {
    delete ptr;
    std::cout << "D destructed\n";
  }
};

int main() {
  A *aptr = new D;

  delete aptr;
}
