#include <iostream>

template <class T = std::string>
struct A {
  T t;
};

int main() {
  A<int> a1;
  A<float> a2;

  A a3;

}
