#include <iostream>

template <class T>
struct A {
  T i;

  void foo() {
    i.bar();
  }
};

int main() {
  A<int> a1{5};
  a1.foo();
  A<float> a2{5.6};

  //a1 = a2;
}
