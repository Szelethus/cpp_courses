#include <iostream>

void f() {
  static int i = 0;
  std::cout << i++ << '\n';
}

static int x;
static void g() {
  std::cout << "static\n";
}

namespace {
int x;
void g() {
  std::cout << "anonymous\n";
}
}

int main() {
  ::f();   
  ::f();   
  ::f();   
  ::f();   
  ::f();   
  ::g();
}
