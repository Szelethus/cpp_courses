#include <iostream>

int factorial(int i) {
  if (i == 0)
    return 1;
  return i * factorial(i - 1);
}

int main() {
  std::cout << factorial(5) << '\n';
}
