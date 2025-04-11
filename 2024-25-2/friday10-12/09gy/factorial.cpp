#include <iostream>

template <int N>
struct Factorial {
  static const int value = Factorial<N - 1>::value * N;
};

// template specializáció
template <>
struct Factorial<1> {
  static const int value = 1;
};

int main() {
  std::cout << Factorial<5>::value << '\n';
}
