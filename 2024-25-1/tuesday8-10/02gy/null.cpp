#include <iostream>

void f(int) {
  std::cout << "int\n";
}
void f(int *) {
  std::cout << "int*\n";
}
void f(std::nullptr_t) {
  std::cout << "std::nullptr_t\n";
}

int main() {
  f(0);
  f(nullptr);
}
