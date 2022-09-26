#include <iostream>
#include <array>

int getArrayLength(int *t, int size) {
  return size;
}

int main() {
  int t[] = {1,2,3,4,5};
  int t2[5] = t;
  std::array<int, 3> a = {1,2,3};

  std::cout << sizeof(t) << '\n';
  std::cout << getArrayLength(t, sizeof(t) / sizeof(t[0])) << '\n';
}
