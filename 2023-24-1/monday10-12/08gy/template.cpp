#include <iostream>

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
void printN() {
  std::cout << N << '\n';
}

struct Wrapper {
  int i;
};

int main() {
  int c = 5, d = 8;

  swap(c, d);

  Wrapper w1{5};
  Wrapper w2{8};

  swap(w1, w2);

  printN<100>();
}
