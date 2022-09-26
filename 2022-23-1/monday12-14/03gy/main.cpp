#include <iostream>

struct BIG {
  long l, k, r, f, g;
};

int f(int a) { return 2 * a; }



int main() {
  int b = 5;
  std::cout << f(b) << '\n';

  std::cout << sizeof(BIG) << ' ' << sizeof(BIG*) << '\n';
  std::cout << sizeof(long) << '\n';
}
