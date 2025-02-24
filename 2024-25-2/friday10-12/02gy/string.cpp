#include <iostream>

int main() {
  std::string str = "alma";

  std::cout << str[0] << '\n';

  std::cout << str.size() << '\n';
  std::cout << sizeof(str) << '\n'; // NEM UGYANAZ!!!!
}
