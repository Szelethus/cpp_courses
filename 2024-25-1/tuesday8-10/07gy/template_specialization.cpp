#include <iostream>

template <int N>
struct factorial {
  static const int value = N * factorial<N - 1>::value;
};

template <>
struct factorial<0> {
  static const int value = 1;
};

int main() {
  std::cout << factorial<5>::value << '\n';
}
