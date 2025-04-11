#include <iostream>

int main() {
  for (float f = 0; f - 1 < 0.000001; f += 0.1) {
    std::cout << f << '\n';
  }
}
