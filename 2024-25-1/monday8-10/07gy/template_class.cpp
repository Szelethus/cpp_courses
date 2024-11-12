#include <iostream>

template <class T>
struct A {
  T data;
  A() { std::cout << "General\n"; }

  void foo() {
    data.helloWorld();
  }
};

template <>
struct A<int> {
  int data;

  A() { std::cout << "Specialized\n"; }
};

int main() {
  A<int> a1;
  A<std::string> a2;


}
