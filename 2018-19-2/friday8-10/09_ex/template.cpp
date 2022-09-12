#include <iostream>

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
void printInt() {
  std::cout << N << '\n';
}

template <class T, int ArraySize>
int arraySize(T (&array)[ArraySize]) {
  return ArraySize;
}

int main() {
  int i1 = 3, i2 = 5;
  double d1 = 6.2, d2 = 7.4;

  swap(i1, i2);
  swap(d1, d2);

  printInt<30>();

  int t[] = {1,2,3,4,345,34,6345,6,345};
  std::cout << arraySize(t) << '\n';
}
