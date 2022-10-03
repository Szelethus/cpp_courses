#include <iostream>

static int x;

static void g();

void f() {
  static int x;
  x++;
  std::cout << x << '\n';
}

namespace {
int k;
void fgfg();
}

int main() {

  f();
  f();
  f();
  f();
  f();
  f();
}
