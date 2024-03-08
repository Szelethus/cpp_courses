#include <iostream>

int x = 1;

int main() {
  int x = 3;

  {
    int x = 7;

    std::cout << ::x;
  }
}
