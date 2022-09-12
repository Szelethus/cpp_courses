#include <iostream>
#include "hello.h"


static void f() {
  std::cout << "Hello\n";
}

int main() {
  f();
  f();
  f();
  f();
  f();
  f();
}
