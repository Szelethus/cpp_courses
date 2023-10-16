#include <iostream>

struct A {
  int a;
};

std::ostream &operator<<(std::ostream &out, const A &a) {
  out << a.a << '\n';
  return out;
}

int main() {
  const A &ref = A{5};
  std::cout << ref;
}
