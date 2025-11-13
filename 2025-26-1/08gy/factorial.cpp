#include <iostream>

template <int N>
struct factorial {
  static const int value = factorial<N-1>::value * N;
};

template <>
struct factorial<1> {
  static const int value = 1;
};

int main() {
  std::cout << factorial<5>::value << '\n';
}
