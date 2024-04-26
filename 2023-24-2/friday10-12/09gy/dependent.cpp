
template <class R>
struct A {
  using T = int;
};

template <class R>
void f() {
  A<R>::T i;
}
