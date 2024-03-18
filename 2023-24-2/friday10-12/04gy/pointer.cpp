#include <iostream>

int main() {
  int i = 5;

  int *ptr = &i;

  std::cout << &i << '\n';
  std::cout << ptr << '\n';
  std::cout << *ptr << '\n';

  int &ref = i;

  std::cout << &i << '\n';
  std::cout << &ref << '\n';
  std::cout << ref << '\n';
}
