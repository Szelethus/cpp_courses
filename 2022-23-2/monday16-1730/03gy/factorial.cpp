#include <iostream>

int factorial(int n) {
  if (n <= 0)
    return 1;
  else
    return n * factorial(n - 1);
}
int main() {
  std::cout << factorial(5) << std::endl;
}
