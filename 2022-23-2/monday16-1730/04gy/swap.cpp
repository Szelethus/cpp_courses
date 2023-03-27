#include <iostream>

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5;
  int d = 8;

  swap(c, d);

  std::cout << "c: " << c << " d: " << d << '\n';
}
