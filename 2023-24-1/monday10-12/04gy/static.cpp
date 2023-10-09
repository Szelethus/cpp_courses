#include <iostream>

void f() {
  static int i = 0;
  std::cout << i++ << '\n';
}

static int x;
static void g() {}

namespace {
int x;
void g() {}
}

int main() {
  g();

}
