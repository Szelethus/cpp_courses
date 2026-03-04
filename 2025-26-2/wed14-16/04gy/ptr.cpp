#include <iostream>

int main() {
  int c = 5;
  int &ref = c;

  ref = 10;

  std::cout << c << '\n';
}
