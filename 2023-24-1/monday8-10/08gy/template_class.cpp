#include <iostream>

template <typename T>
struct A {
  T t;
};

template <>
struct A<std::string> {
  std::string str = "Hello";
};

int main() {
  A<int> a;
  a.t = 6;

  A<std::string> s;
  std::cout << s.str << '\n';

}
