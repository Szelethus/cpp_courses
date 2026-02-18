#include <iostream>

int mulBy2(int i);

void print(int i = 0);

int main() {
  int i = 5;
  i = mulBy2(i);
  print();

  return 0;
}

int mulBy2(int i) {
  return i * 2;
}

void print(int i) {
  std::cout << i << '\n';
}
