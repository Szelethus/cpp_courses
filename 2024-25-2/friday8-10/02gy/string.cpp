#include <iostream>

int main() {
  std::string str = "alma";

  for (int i = 0; i < str.size(); ++i) {
    std::cout << str[i] << '\n';
  }

  std::cout << str.size() << '\n';
  std::cout << sizeof(str) << '\n'; // NEM UGYANAZ!!!

  std::cout << str << '\n';
}
