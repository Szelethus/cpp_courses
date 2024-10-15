#include <iostream>

int main() {
  int t[] = {1,2,3,4,5};

  const int sizeOfT = sizeof(t)/sizeof(t[0]);

  for (int *ptr = t; ptr != t + sizeOfT; ++ptr) {
    std::cout << *ptr << '\n';
  }
}
