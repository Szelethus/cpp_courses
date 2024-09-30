#include <climits>
#include <iostream>

struct A {
  int i;
  long c;
  int k;
};

int main() {
  std::cout << CHAR_BIT << '\n';
  std::cout << sizeof(signed short int) << '\n';
  std::cout << sizeof(signed int) << '\n';
  std::cout << sizeof(signed long int) << '\n';
  std::cout << sizeof(signed long long int) << '\n';

  std::cout << sizeof(A) << '\n';
}
