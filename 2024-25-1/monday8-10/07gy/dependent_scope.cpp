#include <string>

template <class T>
struct A {
  using X = int;
};

template <>
struct A<int> {
  static const int X = 0;
};

template <class T>
void foo() {
  typename A<T>::X k;
}

int main() {
  foo<std::string>();
}
