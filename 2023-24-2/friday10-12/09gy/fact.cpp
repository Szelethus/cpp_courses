#include <iostream>

template <int N>
struct Sum {
  const static int value = N + Sum<N - 1>::value;
};

template <>
struct Sum<0> {
  const static int value = 0;
};

int main() {
  std::cout << Sum<1000000>::value << '\n';
}
