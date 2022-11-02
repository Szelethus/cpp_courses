#include <iostream>

template <class T, int Size>
int arraylength(T (&t)[Size]) {
  return Size;
}

int main() {
  int t[5];
  std::cout << arraylength(t) << '\n';
}
