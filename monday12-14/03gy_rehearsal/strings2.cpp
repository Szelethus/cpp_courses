#include <iostream>

int main() {
  char str1[] = {'a', 'b', 'c', '\0'};
  char str2[] = "abc";
  std::string str3 = "abc";
  std::string str4 = "abc";

  std::cout << sizeof(str1) << '\n';
  std::cout << sizeof(str2) << '\n';
  std::cout << str3.size() << '\n';

  std::cout << str1 << '\n';
  std::cout << str2 << '\n';
  std::cout << str3 << '\n';

  std::string str5 = str3 + str4;
  std::cout << str5 << '\n';
}
