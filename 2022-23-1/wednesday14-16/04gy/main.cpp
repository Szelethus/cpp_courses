#include <iostream>

struct S {
  int i;
  long k;
  int j;
};

int main() {
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(long) << '\n';
  std::cout << sizeof(S) << '\n';
}
