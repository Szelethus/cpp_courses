#include <iostream>

template <int N>
struct Factorial {
  const static int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  const static int value = 1;
};

int main() {
  std::cout << Factorial<5>::value << '\n';
}
