#include <iostream>

int x;

int main() {
  int x = 6;

  {
    int x = 5;
    std::cout << ::x << '\n';
  }
}
