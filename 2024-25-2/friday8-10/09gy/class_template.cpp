#include <string>

template <class T>
struct A {
  T b;

  void foo() {
    b.bar();
  }
};

//template <float F>
//void foo();

int main() {
  A<int> a;
  A<float> a2;

  //a.foo();
}
