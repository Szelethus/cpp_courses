#include <iostream>

struct A {
  int a;

  A(int i) {
    a = i;
    std::cout << "Constructed A\n";
  }

  ~A() {
    std::cout << "Destructed A\n";
  }
};

std::ostream &operator<<(std::ostream &out, A &a) {
  out << a.a << '\n';
  return out;
}

int main() {
  A *ptr = static_cast<A *>(malloc(sizeof(A)));
  ptr->a = 5;
  new (ptr) A(5);

  std::cout << *ptr << '\n';
  ptr->~A();
  free(ptr);
}
