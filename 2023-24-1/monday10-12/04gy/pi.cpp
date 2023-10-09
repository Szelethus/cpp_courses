#include <iostream>

int main() {
  int pi = (3,14);
  std::cout << pi << '\n';
  for (double d = 0; d - 1 < 0.00001; d += 0.1) {
    std::cout << d << '\n';
  }
}
