#include <iostream>

int main() {
  //std::string str1 = {'a', 'b', 'c', '\0'};
  std::string str1 = "abc";
  std::string str2 = "abc";

  std::cout << str1.size() << '\n';
  //std::cout << sizeof(str2) << '\n';

  std::cout << str1 << '\n';
  std::cout << str2 << '\n';

  std::string str3 = str1 + str2;

  std::cout << str3 << '\n';
}
