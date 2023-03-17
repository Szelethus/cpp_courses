#include <iostream>
#include <cstdlib>

int calculate(int i) {
#ifdef DEBUG
  if (i == 0) {
    std::cerr << "Division by zero error!\n";
    std::exit(1);
  }
#endif
  return 10 / i;
}

int main() {
  std::cout << calculate(2) << '\n';
  std::cout << calculate(0) << '\n';

}
