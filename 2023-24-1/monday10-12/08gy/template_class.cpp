#include <iostream>

template <class T>
struct A {
  T i;
};

template <>
struct A<std::string> {
  std::string s = "Hello";
};

int main() {
  A<int> a;
  a.i = 6;
  A<std::string> s;
  std::cout << s.s << '\n';
}
