#include <iostream>

int main() {
  std::string str = "alma";

  std::cout << str.size() << '\n';
  std::cout << sizeof(str) << '\n';
  std::cout << sizeof("alma") << '\n';

  const char *c = str.c_str();
}
