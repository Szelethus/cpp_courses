#include <iostream>
#include <array>

int getArraySize(int (*p)[5]) {
  return sizeof(*p) / sizeof(*p[0]);
}

int main() {
  int t[] = {1,2,3,4,5};
  std::array<int, 5> arr;
  //int t2[5] = t;
  std::cout << getArraySize(&t) << '\n';
}
