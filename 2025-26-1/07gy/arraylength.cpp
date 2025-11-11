#include <iostream>

template <class T, int Size>
int arrayLength(T (&t)[Size]) {
  return Size;
}

void f(int (&t)[5]);

int main() {
  int t[] = {1,2,3,4,5};

  std::cout << arrayLength(t) << '\n';
}
