
template <class T>
struct vector {};

template <class T>
struct list {};

template <class T>
struct dequeue {};



template <
  template<class>
  class Container
>
struct Matrix {
  Container<int> cont;
};

int main() {
  Matrix<vector> m1;
  Matrix<list> m2;
  Matrix<dequeue> m3;
}
