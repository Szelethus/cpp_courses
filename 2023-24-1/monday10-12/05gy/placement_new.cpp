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
  A *ptr = new A(5);
  std::cout << *ptr << '\n';
  delete ptr;
}
