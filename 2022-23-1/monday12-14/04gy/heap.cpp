#include <iostream>

int main() {
  int *p = new int(2);
  delete p;
  delete p;
}
