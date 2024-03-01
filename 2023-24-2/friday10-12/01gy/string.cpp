#include <iostream>
#include <string>

int main() {
  std::string s = "Hello!\n";

  int i = 0;

  while (i < s.size()) {
    std::cout << "value of s at index '" << i << "' is " << s[i] << '\n';

    i = i + 1;
  }
}
