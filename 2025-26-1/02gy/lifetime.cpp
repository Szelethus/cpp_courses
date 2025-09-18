#include <iostream>

int x = 9;

int main() {
  int x = 7;

  {
    int x = 5;
    std::cout << ::x << '\n';
  }
}
