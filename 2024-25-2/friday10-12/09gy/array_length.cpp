#include <iostream>

template <class T, int Size>
int arrayLength(T (&arr)[Size]) {
  return Size;
}

int main() {
  int t[5];
  std::string strt[7];

  std::cout << arrayLength(t) << '\n';
  std::cout << arrayLength(strt) << '\n';
}
