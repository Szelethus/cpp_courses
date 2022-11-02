#include <iostream>
#include "linked_list.h"

struct A {
  int x = 7;

  const static int y = 4;

  void print() {
    std::cout << "x: " << x << ", y: " << y << '\n';
  }

  static void printStatic() {
    std::cout << "y: " << y << '\n';
  }
};

int main() {
  A a1, a2;
  std::cout << &a1.y << '\n';
  std::cout << &a2.y << '\n';
  std::cout << &A::y << '\n';

  a1.print();
  A::printStatic();
  List l1, l2, l3;
  std::cout << List::counter << '\n';
}

