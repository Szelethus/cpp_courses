#include <climits>
#include <iostream>

int main() {
  std::cout << CHAR_BIT << '\n';
  std::cout << sizeof(char) << '\n';
  std::cout << sizeof(int) << '\n';

  std::string str = "hello\n";

  std::cout << "string elemszám: " << str.size() << '\n';
  std::cout << "string méret: " << sizeof(str) << '\n';
}
