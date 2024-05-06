#include <iostream>

struct A {
  A() = default;
  A(const A &other) = delete;
  A& operator=(const A &other) = delete;
};
