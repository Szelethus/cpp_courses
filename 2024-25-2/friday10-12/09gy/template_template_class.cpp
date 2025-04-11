
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
  template <class T>
  class Container
>
struct Matrix {
  Container<int> cont;
};

int main() {
  Matrix<vector> vmtx;
  Matrix<list> lmtx;
  Matrix<deque> dmtx;
}
