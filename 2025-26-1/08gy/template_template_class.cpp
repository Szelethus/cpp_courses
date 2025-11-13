
template <class T>
struct vector {

};

template <class T>
struct list {

};

template <
  template <class>
  class Container
>
struct Matrix {
  Container<int> m;
};

int main() {
  Matrix<vector> m1;
  Matrix<list> m2;
}
