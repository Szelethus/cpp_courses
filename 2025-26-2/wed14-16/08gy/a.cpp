template <class T>
struct A {

};

template <class T>
struct B {
  using A = ::A<T>;
};
