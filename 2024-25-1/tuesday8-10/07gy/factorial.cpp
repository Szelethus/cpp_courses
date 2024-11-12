#include <iostream>

template <int N>
struct factorial {
  const static int value = N * factorial<N -1>::value;
};

template <>
struct factorial<0> {
  const static int value = 1;
};

int main() {
  std::cout << factorial<5>::value << '\n';
}
