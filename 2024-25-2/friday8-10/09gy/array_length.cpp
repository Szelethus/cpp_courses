#include <iostream>

template <class T, int Size>
int arrayLength(T (&t)[Size]) {
  return Size;
}

int main() {
  int t[5];
  int r[6];

  std::cout << arrayLength(t) << '\n';
  std::cout << arrayLength(r) << '\n';
}
