#include <iostream>
template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

struct A {
  int i;
};

template <int N>
void printN() {
  std::cout << N << '\n';
}

int main() {
  int c = 5, d = 8;
  swap(c, d);

  A a1{1}, a2{2};
  swap(a1, a2);

  printN<200>();
  printN<500>();
}
