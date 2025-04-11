#include <iostream>

struct IntWrapper {
  int i;
};

template <class T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N = 150> void print() {
  std::cout << N << '\n';
}

int main() {
  int c = 5, d = 8;
  // template paraméter dedukció
  swap(c, d);

  IntWrapper iw1{1}, iw2{2};
  swap<IntWrapper>(iw1, iw2);

  int N;
  std::cin >> N;
  print<100>();
  print<>();
  print();
  //print<N>();
}
