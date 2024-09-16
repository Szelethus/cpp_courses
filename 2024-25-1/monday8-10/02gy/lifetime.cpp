#include <iostream>

int x = 4;

namespace detail {
int y;
}

int main() {
  int x = 5;
  int *ptr = &x;

  detail::y = 8;

  {
    int x = 6;
    std::cout << x << '\n';
    std::cout << ::x << '\n';
  }
}
