#include <iostream>

void pass(int *p, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << p[i] << '\n';
    std::cout << i[p] << '\n';
    std::cout << *(p + i) << '\n';
  }
}

int main() {
  int t[5];
  std::string s[5];

  for (int i = 0; i < 5; ++i) {
    t[i] = i;
  }

  std::cout << sizeof(t) << '\n';
  //std::cout << sizeof(t) / sizeof(t[0]) << '\n';

  pass(t, sizeof(t) / sizeof(t[0]));
}
