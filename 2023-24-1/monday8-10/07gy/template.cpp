#include <iostream>

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
int printN() {
  return N;
}

struct Wrapper {
  int a;
};

template <typename A, typename B>
void print(A a, B b) {
  std::cout << a << ' ' << b << '\n';
}

int main() {
  int c = 5;
  int d = 6.7;
  swap(c, d);

  Wrapper a{6};
  Wrapper b{7};

  swap(a, b);

  print(5, 6.7);

  std::cout << printN<100>() << '\n';
}
