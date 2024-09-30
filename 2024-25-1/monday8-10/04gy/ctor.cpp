struct A {
  int a, b;

  A(int i) : a(i), b(a) {}

  A(int i, int j) : a(i), b(j) {}
};

int main() {
  A a1(1), a2(1, 2);
}
