#include <iostream>

static int st;

static void f() {
  static int x = 0;
  ++x;
  std::cout << x << '\n';
}

struct A {
  static int count;
  const static int ID = 8;

  A() {
    ++count;
  }
};

int A::count = 0;

// anonymous namespace
// minden static ezen belül
namespace {

struct B {
  int i;
};

} // end of anonymous namespace

int main() {
  f();
  f();
  f();
  f();
  f();

  A a1, a2, a3;

  std::cout << "A was created " << A::count << " times\n";
}
