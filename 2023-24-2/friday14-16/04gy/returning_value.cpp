#include <iostream>

int *get5() {
  int i = 5;
  return &i;
}

int main() {
  int *j = get5();
  std::cout << *j << '\n';
}
