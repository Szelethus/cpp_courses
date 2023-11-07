#include <iostream>

template <
  template <typename>
  class Container
>
struct Matrix {
  Container<float> c;
};

template <class T = void>
struct vector {
};

template <class T>
struct list {
};

int main() {
  Matrix<vector> m1;
  Matrix<list> m2;
}
