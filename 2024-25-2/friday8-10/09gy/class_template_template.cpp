
template <class T>
struct vector {

};

template <class T>
struct list {

};

template <class T>
struct deque {

};

template <
  template <class>
  class Container
>
struct Matrix {
  Container<int> cont;
};

int main() {
  Matrix<vector> cvec;
  Matrix<list> cvec2;
  Matrix<deque> cvec3;
}
