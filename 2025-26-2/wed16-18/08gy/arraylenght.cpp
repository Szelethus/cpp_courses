#include <iostream>

template <int Size, class T>
int arrayLength(T (&t)[Size]) {
  return Size;
}

int main() {
  int t[] = {0,1,2,3,4,5};

  std::cout << arrayLength(t) << '\n';
}
