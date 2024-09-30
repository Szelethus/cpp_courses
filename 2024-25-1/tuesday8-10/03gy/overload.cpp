#include <iostream>

void f(int) {
  std::cout << "int\n";
}

void f(std::string) {
  std::cout << "std::string\n";
}

int main() {
  f(5);
  f("hello");
}
