#include <iostream>
#include <vector>

template <
  template <class, class>
  class Container,
  class T
>
class Z {
  Container<T, std::allocator<T>> cont;
  Container<double, std::allocator<double>> cont2;
};

struct A {
  using X = int;
};

struct K {
  const static int X = 0;
};

template <class T>
class B {
  typename T::X a;
};

int main() {
  Z<std::vector, int> k;

  B<A> b;
  A::X a;
}
