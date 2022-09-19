#include <iostream>
#include <climits>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5, d = 8;

  std::cout << c << ' ' << d << '\n';
  swap(c, d);
  std::cout << c << ' ' << d << '\n';
}
