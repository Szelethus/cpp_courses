#include <iostream>

int main() {
  std::string s = "Hello\n";

  std::cout << s << '\n';
  std::cout << s.size() << '\n';
  std::cout << s[0] << '\n';

  int i = 0;

  while (i < s.size()) {
    std::cout << "the value of s at index '" << i << "' is: "
              << s[i] << '\n';
    i = i + 1;
  }
}
