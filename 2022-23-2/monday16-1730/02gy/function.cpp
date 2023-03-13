#include <iostream>

int mulByTwo(int i) {
  return i * 2;
}

int main() {
  int i = 2;
  i = mulByTwo(i);
  std::cout << i << '\n';
}
