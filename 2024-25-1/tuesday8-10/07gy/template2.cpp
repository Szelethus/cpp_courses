#include <iostream>

template <int N>
void printN() {
  std::cout << N << '\n';
}

int main() {
  printN<500>();

  int n;
  std::cin >> n;

  printN<n>();
}
