#include <iostream>

namespace example_1 {
int x;

void f() {
  std::cout << "hello1\n";
}
} // end of namespace example_1

void f() {
  std::operator<<(std::cout, "hello2\n");
}

int main() {
  example_1::f();
  f();
} 
