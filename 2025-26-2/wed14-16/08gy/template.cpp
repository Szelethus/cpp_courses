#include <iostream>

template <class T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

struct A {
  int i;
};

int main() {
  int c = 5, d = 8;
  swap(c, d);

  A a1{3}, a2{4};

  swap(a1, a2);
}
