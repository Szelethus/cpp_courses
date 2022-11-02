#include <iostream>

struct A {
  int x;
};

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N = 0>
void printNumber() {
  std::cout << N << '\n';
}

int main() {
  int c = 5, d = 8;
  swap(c, d);

  A a1{3}, a2{5};
  swap(a1, a2);

  printNumber<100>();
  printNumber<500>();

  const int N = 300;
  printNumber<N>();
  printNumber();
}
