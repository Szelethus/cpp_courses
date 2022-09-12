#include <iostream>

template <class T>
struct A {
  typedef T Alma;
};

template <>
struct A<double> {
  static int Alma;
};

template <class T>
void f() {
  typename A<T>::Alma x;
}

template <int N>
struct Factorial {
  static const int value = Factorial<N-1>::value * N;
};

template <>
struct Factorial<1> {
  static const int value = 1;
};

int main() {
  f<int>();
  //f<double>();

  std::cout << Factorial<5>::value << '\n';
}
