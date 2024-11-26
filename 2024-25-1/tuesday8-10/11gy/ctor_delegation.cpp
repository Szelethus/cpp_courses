
struct A {
  int x, y;

  A(int x, int y) : x(x), y(y) {}

  A(int x) : A(x, 0) {}
};

int main() {
  A a(1);
}
