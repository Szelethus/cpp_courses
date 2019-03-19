#include <iostream>

int main() {
  int *p = new int;
  *p = 3;
  delete p;
  delete p;
}
