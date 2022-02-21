#include <iostream>

int main() {
  //char c = 'k';

  char str[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};

  int t[] = {1, 2, 3, 4};

  std::cout << str[0] << '\n';

  std::cout << "Size of in str: " << sizeof(str) << '\n';

  std::cout << "Size of in t: " << sizeof(t) << '\n';

  std::cout << "Size of char: " << sizeof(char) << '\n';
  std::cout << "Size of int: " << sizeof(int) << '\n';

  std::cout << "Element count in t: " << sizeof(t) / sizeof(t[0]) << '\n';
  std::cout << "Element count in str: " << sizeof(str) / sizeof(str[0]) << '\n';

  std::string str2 = "Hello World!";

  std::cout << "Element count in str2: " << str2.size() << '\n';

  std::cout << str << '\n';
  std::cout << "Hello World!\n";
}
