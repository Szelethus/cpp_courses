#include <iostream>

template <typename T, int Size>
int getArrayLength(T (&t)[Size]) {
  return Size;
}

int main() {
  int t[5];

  std::cout << getArrayLength(t) << '\n';
}
