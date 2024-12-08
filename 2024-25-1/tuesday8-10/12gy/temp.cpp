
struct A {};

void f(const A &a) {}

void bar(const int &i) {}

int main() {
  f(A{});

  bar(5);
}
