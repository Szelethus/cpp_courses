#include <iostream>

int f() {
  return 0;
}

int main() {
  int i;

  i = i + 10;
  ++i;


  std::cout << f() << ++i << "\n";
  return 0;
}
