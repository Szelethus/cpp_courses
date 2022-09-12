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

int main() {
  int c = 3, d = 4;
  double c1 = 3, d1 = 4;
  
  printInt<235>();

  swap(c,d);
  swap(c1,d1);

  std::cout << c << ' ' << d << '\n';
  std::cout << c1 << ' ' << d1 << '\n';
}
