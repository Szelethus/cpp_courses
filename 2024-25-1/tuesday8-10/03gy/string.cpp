#include <iostream>

int main() {
  char *c = "Hello";

  std::string str = "Hello";
  std::cout << sizeof("Hello") << '\n';
  std::cout << str.size() << '\n';
  // NEM a tárolt adat mérete!!!
  std::cout << sizeof(str) << '\n';

}
