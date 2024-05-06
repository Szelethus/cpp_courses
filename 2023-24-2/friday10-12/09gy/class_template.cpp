#include <iostream>

template <class T = float>
struct A {
  T a;

  void foo() {
    a.bar();
  }
};

int main() {
  A<int> a;
  a.foo();
}
