#include <iostream>

struct A {
  using X = int;
};

struct B {
  const static int X = 5;
};

template <class T>
struct Bela {
  typename T::X cont;
};

int main() {

  Bela<A> a;
  //Bela<B> b;
  
}
