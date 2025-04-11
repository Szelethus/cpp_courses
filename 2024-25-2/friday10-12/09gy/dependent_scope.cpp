
template <class T>
struct A {
  using Type = int;
};

template <>
struct A<float> {
  static const int Type = 6;
};

template <class T>
void foo() {
  typename A<T>::Type i;
}

int main() {

  foo<int>();
  //foo<float>();
}
