#include <iostream>

int x;

int main() {
  int x = 5;

  {
    int x = 6;
    std::cout << ::x << '\n';
  }

}
