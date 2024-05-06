#include <iostream>

void f1(int *t, int size) {}

void f2(int (&t)[5]) {}

template <class T, int Size>
int getSize(T (&t)[Size]) {
  return Size;
}

int main() {
  int t[] = {1,2,3,4,5};

  f1(t, sizeof(t) / sizeof(t[0]));
  f2(t);

  std::cout << getSize(t) << '\n';
}
