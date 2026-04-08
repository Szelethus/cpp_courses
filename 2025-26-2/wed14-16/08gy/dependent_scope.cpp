#include <iostream>

template <class T>
struct X {
  using Type = T;
};

template <>
struct X<float> {
  static int Type;
};

template <class T>
void foo() {
  typename X<T>::Type i;
}

void g() {
  foo<int>();
}
