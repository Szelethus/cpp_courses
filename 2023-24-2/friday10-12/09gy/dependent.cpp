
template <class T>
struct A {
  using R = int;
};

template <>
struct A<float> {
  const static int R = 0;
};

template <class T>
void foo() {
  typename A<T>::R i;
}

