#include <iostream>

int main() {
  char str1[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
  std::string str2 = "Hello World!";
  char str3[] = "Hello World!";

  std::cout << "Element count in str: " << sizeof(str1) / sizeof(str1[0])
            << '\n';
  std::cout << "Element count in str2: " << str2.size() << '\n';
  std::cout << "Element count in str: " << sizeof(str3) / sizeof(str3[0])
            << '\n';

  std::cout << str1 << '\n'; // -fsanitize=address
  std::cout << str2 << '\n';
  std::cout << str3 << '\n';

  // strings can concatenate
  // strings are a non-fundamental type

}
