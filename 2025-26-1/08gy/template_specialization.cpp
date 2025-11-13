#include <iostream>

template <class T>
struct A {
  T t;
};

// template specializáció
template <>
struct A<std::string> {
  std::string t;
  int size;
};

int main() {
  A<int> a1;
  A<float> a2;

}
