#include <iostream>

int main() {
  int *ptr = new int(5);
  std::cout << *ptr << '\n';
  delete ptr;
}
