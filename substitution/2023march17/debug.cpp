#include <cstdlib>
#include <iostream>

int calculate(int i) {
#ifdef DEBUG
  if (i == 0) {
    std::cout << "Division by zero!\n";
    std::exit(1);
  }
#endif // DEBUG
  return 10 / i;
}

#define KORTE 5

#error KORTE % 5 == 0

int main() {
  std::cout << calculate(2) << '\n';
  std::cout << calculate(0) << '\n';
}
