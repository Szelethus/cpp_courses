#include <iostream>

int &incr(int &i) {
  i += 1;
  return i;
}

int main() {
  int a = 5;
  int &ref = incr(a);
  ref += 1;
  std::cout << ref << '\n';
  std::cout << sizeof(int) << ' ' << sizeof(int*) << '\n';
}
