#include <iostream>

// globális
int x;

namespace alma {
int x = 7;
} // alma

int main() {
  int x = 3;
  {
    int x = 4;
    std::cout << ::x << '\n';
  }
}
