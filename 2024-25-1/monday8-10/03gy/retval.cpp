#include <iostream>

int &ret() {
  int k;
  return k;
}

int main() {
  int &k = ret();

  std::cout << k << '\n';
}
