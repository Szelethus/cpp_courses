#include <iostream>

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
void printNumber() {
  std::cout << N;
}

int main() {
  int c = 2;
  int d = 7;
  swap(c, d);

  double d1 = 5.6;
  double d2 = 8.9;
  swap(d1, d2);

  std::cout << c << ' ' << d << '\n';

  printNumber<6>();
}
