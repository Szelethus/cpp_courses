#include <iostream>

int main() {
  std::string h = "Hello";
  std::cout << h.size() << '\n';
  std::cout << sizeof(h) << '\n';
  std::cout << sizeof("Hello") << '\n';
}
