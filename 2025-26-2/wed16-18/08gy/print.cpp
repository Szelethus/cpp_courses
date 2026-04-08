#include <iostream>

template <int N>
void print() {
  std::cout << N << '\n';
}

int main() {
  print<5>();
  print<4>();
  print<3>();
  print<2>();

  int N;
  std::cin >> N;
  print<N>();
}
