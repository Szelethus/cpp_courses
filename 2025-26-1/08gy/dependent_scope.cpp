
template <class T>
struct X {
  using type = int;
  // typedef int T;
};

//template <>
//struct X<float> {
//  const static int type = 6;
//};

template <class T>
void f() {
  typename X<T>::type i = 5;
}
