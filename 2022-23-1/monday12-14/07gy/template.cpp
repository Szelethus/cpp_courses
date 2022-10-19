#include <iostream>
#include <string>

struct A {
  int i;
};

template <typename T>
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

  A a1{0};
  A a2{1};
  swap(a1, a2);

  printNumber<100>();

  constexpr int N = 500;
  printNumber<N>();
}

