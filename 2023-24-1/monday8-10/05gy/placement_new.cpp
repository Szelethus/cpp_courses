#include <iostream>

struct A {
  int a;
  A(int _a) {
    a = _a;
    std::cout << "Constructed\n";
  }
  ~A() {
    std::cout << "Destructed\n";
  }
};

int main() {
  A *ptr = static_cast<A*>(malloc(sizeof(A)));
  new(ptr) A(5);
  ptr->~A();
  free(ptr);
}
