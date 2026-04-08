#include <iostream>

template <class T>
struct X {
  using Type = T;
};

template <>
struct X<float> {
  static const int Type = 5;
};

template <class T>
void foo() {
  typename X<T>::Type i = 5;
}

void bar() {
  foo<int>();
}
