#include <cstdio>
#include <iostream>

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
void foo(T lhs, T rhs) {
  swap(lhs, rhs);
}

//template <float f>
//void bar() {
//
//}

template <int N>
void printN() {
  std::cout << N << '\n';
}

int main() {
  int c = 5, d = 8;
  swap(c, d);
  float f1 = 0.5, f2 = 0.9;
  swap(f1, f2);

  //int N;
  //std::cin >> N;
  printN<100>();
  printN<101>();
  printN<102>();
}
