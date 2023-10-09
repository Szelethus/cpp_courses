#include <iostream>

int main() {
  for (double d = 0; d - 1 < 0.0001 ; d += 0.1) {
    std::cout << d << '\n';
  }
}
