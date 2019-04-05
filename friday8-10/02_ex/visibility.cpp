#include <iostream>

int x = 1;

int main() {
  int x = 2;
  {
    int x = 3;
    std::cout << ::x << '\n';
  }


}
