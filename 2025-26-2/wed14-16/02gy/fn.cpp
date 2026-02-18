#include <iostream>

int mulBy2(int i) {
  return i * 2;
}

void print(int i = 0) {
  std::cout << i << '\n';
}

int main() {
  int i = 5;

  i = mulBy2(i);

  print(i);

  return 0;
}
