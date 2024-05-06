
template <class T>
struct A {
  using R = int;
};

template <>
struct A<float> {
  static const int R = 0;
};

template <class T>
void foo() {
  typename A<T>::R i;
}

int main() {
  //foo<float>();
}
