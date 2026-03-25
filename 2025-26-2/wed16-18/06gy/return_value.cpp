#include <iostream>

int& ret() {
  int i = 5;
  return i;
}

int main() {
  int &ref = ret();
  std::cout << ref << '\n';
}
