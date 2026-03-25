#include <iostream>

struct A {
  int i;

  A();

  // tagfüggvény deklaráció
  void print();
};

A::A() : i(0) {}

// tagfüggvény definíció
void A::print() {
  std::cout << i << '\n';
}
