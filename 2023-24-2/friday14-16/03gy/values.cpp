#include <iostream>

int x = 3;

int main() {
  int x = 5;

  {
    int x = 7;

    std::cout << ::x << '\n';
  }
}
