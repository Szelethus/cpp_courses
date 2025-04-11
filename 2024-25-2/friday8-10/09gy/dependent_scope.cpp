
template <class T>
struct A {
  using Type = int;
};

template <>
struct A<int> {
  static const int Type = 5;
};

template <class T>
void foo() {
  typename A<T>::Type i;
}

int main() {
  foo<float>();
  //foo<int>();
}
