#include <iostream>

int main() {
  int *ptr = new int{5};
  int *qtr = new int[5];

  delete ptr;
  delete[] qtr;
}
