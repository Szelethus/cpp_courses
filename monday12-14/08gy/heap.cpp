#include <iostream>

int main() {
  int *ptr = new int{5};
  int *ttr = new int[5];

  delete ptr;
  delete[] ttr;
}
