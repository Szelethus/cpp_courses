#include <iostream>

int main() {
  //char c = 'n';
  //int t[] = {1, 2, 3, 4};
  //std::cout << t[0] << '\n';

  char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  //char str[] = "Hello";

  std::string hello = "Hello ";
  std::string world = "World\n";

  std::string helloworld = hello + world;

  std::cout << helloworld << '\n';

  std::cout << sizeof(str)/sizeof(str[0]) << '\n';
  std::cout << str << '\n';
}
