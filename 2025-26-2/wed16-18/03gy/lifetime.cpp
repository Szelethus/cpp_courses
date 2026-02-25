#include <iostream>

int x;

int main() {
  int x = 3;
  {
    int x = 4;
    std::cout << ::x << '\n';
  }
}
