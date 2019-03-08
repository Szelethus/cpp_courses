#include <iostream>
#include "global.h"

static int x = 8;

static void sort();

void f() {
  static int count = 0;
  count++;
  std::cout << count << '\n';
}
