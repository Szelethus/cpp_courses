
struct A {
  int i;
  A(int i) : i(i) {}
};

void foo(const A &a) {

}

int main() {
  foo(A{2});
}
