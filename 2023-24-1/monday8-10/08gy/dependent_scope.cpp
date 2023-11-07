#include <iostream>

template <class T>
struct MyStruct {
  typename T::type a;
};

template <class T>
struct Int {
  using type = int;
};

int main() {
  MyStruct<Int<void>> s;
}
