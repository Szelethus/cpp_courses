#include <iostream>

int main() {
  std::string str = "Hello";
  for (int i = 0; i < 100; ++i)
    str += "Hello";

  std::cout << str << '\n';
}
