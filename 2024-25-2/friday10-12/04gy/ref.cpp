#include <iostream>

int main() {
  int i = 5;

  int &ref = i;

  std::cout << i << '\n';
  std::cout << ref << '\n';
  std::cout << &i << '\n';
  std::cout << &ref << '\n';

  std::cout << sizeof(int*) << '\n';
  std::cout << sizeof(long*) << '\n';
}
