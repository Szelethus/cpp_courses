
template <class T>
struct A {
  T a;

  void foo() {
    a.bar();
  }
};

int main() {
  A<int> a1;
  A<float> a2;

  //a1.foo();
}
