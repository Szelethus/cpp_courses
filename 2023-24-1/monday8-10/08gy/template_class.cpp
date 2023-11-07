#include <iostream>

template <typename T>
class B {
  typename T::X a;
};

template <typename T>
class A {
  typedef int X;
};

template <>
class A<void> {
  static int X;
};

int main() {
  B<void> b;
}
