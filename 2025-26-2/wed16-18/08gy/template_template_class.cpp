
template <class T>
class vector {
  // ...
};

template <class T>
class list {

};

template <
  template <class>
  class Container
>
struct Matrix {
  Container<int> cont;
};

int main() {
  Matrix<vector> m1;
  Matrix<list> m2;
}
