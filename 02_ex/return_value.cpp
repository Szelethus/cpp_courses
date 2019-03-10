#include <iostream>

int* f(int p) {
  p++;
  return &p;
}

int main() {
  int a = 3;

  int *return_val = f(a);

  int t[0];

  std::cout << *return_val << std::endl;
}
