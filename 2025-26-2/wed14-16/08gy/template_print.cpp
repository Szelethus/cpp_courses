#include <iostream>

template <int I>
void print() {
  std::cout << I << '\n';
}

int main() {
  print<5>();
  print<3>();
  print<2>();
  print<1>();

  int N;
  std::cin >> N;
  print<N>();
}
