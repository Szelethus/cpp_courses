#include <iostream>

template <class T>
struct A {
  T data;
};

template <>
struct A<int> {
  int data1;
  int data2;
};

int main() {
  A<int> a1{5, 6};

  A<std::string> a2;
  
}
