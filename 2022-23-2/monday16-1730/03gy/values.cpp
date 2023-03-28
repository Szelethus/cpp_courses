#include <iostream>

int x;

void g() {
  int i;
}

int main() {
  int x = 3;

  {
    int x = 4;

    // int *p = new int;
    // delete p;
    x = 5;

    std::cout << x << '\n';
    std::cout << ::x << '\n';
  }

  g();
  int y;
}
