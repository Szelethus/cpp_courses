#include <iostream>

int main() {
  int t[] = {1,2,3,4,5};

  for (int *ptr = t; ptr != t + sizeof(t)/sizeof(t[0]); ++ptr) {
    std::cout << *ptr << '\n';
  }
}
