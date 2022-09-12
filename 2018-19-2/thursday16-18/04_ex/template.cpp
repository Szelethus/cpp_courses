#include <iostream>

/*
struct Vec {
  int a, b;

private:
  Vec &operator=(const Vec &) {
    return *this;
  }
};
*/

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
void f() {
  std::cout << N << '\n';
}

void f2(int N) {
  std::cout << N << '\n';
}

template <typename A>
struct Store {
  A a;
  void foo() {}
};

template <>
struct Store<int> {};

int main() {
  f<0>();
  f<6>();


  //Store<int> tmp;
  //tmp.foo();
  Store<double> tmp2;
  tmp2.foo();
}
