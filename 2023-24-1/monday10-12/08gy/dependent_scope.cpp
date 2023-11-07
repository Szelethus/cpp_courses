#include <iostream>

template <class T>
struct MyStruct {
  typename T::type i;
};

template <class T>
struct MyType {
  using type = int;
};

int main() {
  MyStruct<MyType<void>> m;
  m.i = 6;
}
