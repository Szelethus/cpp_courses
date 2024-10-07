struct A {
  int a, b;

  A(int i = 0, int j = 0) : b(i), a(b) {}
  A(int i) : a(i), b(i) {}

};

int main() {
  A a1(1, 2);
  A a2;
}
